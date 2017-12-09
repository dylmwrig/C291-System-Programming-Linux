/* game.c --- 
 * 
 * Filename: game.c
 * Description: 
 * Author: Bryce Himebaugh
 * Maintainer: 
 * Created: Tue Sep  6 11:08:59 2016
 * Last-Updated: 
 *           By: 
 *     Update #: 0
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change log:
 * 
 * 
 */

/* Copyright (c) 2016 The Trustees of Indiana University and 
 * Indiana University Research and Technology Corporation.  
 * 
 * All rights reserved. 
 * 
 * Additional copyrights may follow 
 */

/* Code: */
#include <unistd.h> 
#include <ncurses.h>
#include <time.h>
#include "highscore.h"
#include "game.h"
#include "well.h"
#include "tetris.h"
#include "tetromino.h"
#include "key.h"

void init_game(void) {
  int x,y;
}

//display and undisplay time
void display_time(float time, int x, int y) {
  mvprintw(y,x,"***  TIME ***");
  mvprintw(y+1,x,"%f",time);
}

void undisplay_time(int x, int y) {
  mvprintw(y,x,"             ");
  mvprintw(y+1,x,"        ");
}

highscore_t *game(highscore_t *highscores) {
  static int state = INIT;
  tetromino_t *next = NULL;
  tetromino_t *current = NULL;
  well_t *w;
  int x,y;
  int c;
  int arrow;
  struct timespec tim = {0,1000000};
  struct timespec tim_ret;
  int move_counter = 0;
  int move_timeout = 500;
  int status;
  int counter = 0;
  int maximumWellWidth = WELL_WIDTH * 2;
  int currentWellWidth = WELL_WIDTH;
  int lines_cleared = 0;
  int score = 0;
  float timeInMS = 0.0f;
  const float MAX_TIME = 300.0f; //game over when timeInMS >= MAX_TIME
  char str[80];  

  while(1) {
    switch(state) {
    case INIT:               // Initialize the game, only run one time 
      initscr();
      nodelay(stdscr,TRUE);  // Do not wait for characters using getch.  
      noecho();              // Do not echo input characters 
      getmaxyx(stdscr,y,x);  // Get the screen dimensions 
      w = init_well(((x/2)-(WELL_WIDTH/2)),3,WELL_WIDTH,WELL_HEIGHT);
      draw_well(w);
      srand(time(NULL));     // Seed the random number generator with the time. Used in create tet. 
      display_score(score, w->upper_left_x-15,w->upper_left_y);  
      state = ADD_PIECE;
      break;
    case ADD_PIECE:          // Add a new piece to the game
      if (next) {
	current = next;
	next = create_tetromino ((w->upper_left_x+(w->width/2)), w->upper_left_y);
      }
      else {
	current = create_tetromino ((w->upper_left_x+(w->width/2)), w->upper_left_y);
	next = create_tetromino ((w->upper_left_x+(w->width/2)), w->upper_left_y);
      }

      //if collision is happening before the user can move the piece, game over
      if (check_collision(current) == COLLIDE){
        state = GAME_OVER;
        break;
      }      
      display_tetromino(current);
      state = MOVE_PIECE;
      break;
    case MOVE_PIECE:     // Move the current piece 
      if ((arrow = read_escape(&c)) != NOCHAR) {
	switch (arrow) {
	case UP:
	  undisplay_tetromino(current);
	  rotate_ccw(current);
	  display_tetromino(current);
	  break;
	case DOWN:
	  undisplay_tetromino(current);
	  rotate_cw(current);
	  display_tetromino(current);
	  break;
	case LEFT:
	  undisplay_tetromino(current);
	  move_tet(current,current->upper_left_x-1,current->upper_left_y);
	  display_tetromino(current);
	  break;
	case RIGHT:
	  undisplay_tetromino(current);
	  move_tet(current,current->upper_left_x+1,current->upper_left_y);
	  display_tetromino(current);
	  break;

	case PLUS:
	
          currentWellWidth = w->width + (w->width * 0.1);
          if(!(currentWellWidth > maximumWellWidth)) {
            undisplay_score(score, w->upper_left_x-15,w->upper_left_y);
            undraw_well(w);
	    w->width = currentWellWidth;
	    w = changeWellSize(((x/2)-(w->width/2)),1,w->width,WELL_HEIGHT,w);	
            display_score(score, w->upper_left_x-15,w->upper_left_y);   
	    draw_well(w);
	  }
          break;

        case MINUS:
          if(w->width > 10) {  
            undisplay_score(score, w->upper_left_x-15,w->upper_left_y);
	    undraw_well(w);
	    w->width -= (w->width * 0.1);
	    w = changeWellSize(((x/2)-(w->width/2)),1,w->width,WELL_HEIGHT,w);	
            display_score(score, w->upper_left_x-15,w->upper_left_y); 
	    draw_well(w);
          } 
	  break;

        case PAUSE:
          state = PAUSED;
          break;

	case REGCHAR: 
	  mvprintw(10,10,"REGCHAR 0x%02x",c);
          if (c == ' ') {
	    move_timeout = DROP_RATE;
 	  }
	  if (c == 'q') {
	    state = GAME_OVER;
 	  }
	}
      } 

      if (move_counter++ >= move_timeout) {
	counter++;
	undisplay_tetromino(current);
	status = move_tet(current,current->upper_left_x,current->upper_left_y+1);
	display_tetromino(current);
	if (status == MOVE_FAILED) {
	  state = ADD_PIECE;
	  move_timeout = BASE_FALL_RATE;
	}
	move_counter = 0;
      }
      break;
    case GAME_OVER:
      nodelay(stdscr,FALSE);
      clear();
      getmaxyx(stdscr,y,x);
      mvprintw(1,x/2-5,"  GAME_OVER  ");
      mvprintw(2,x/2-5,"#############");
      mvprintw(3,x/2-5,"  YOUR SCORE ");
      mvprintw(4,x/2-5,"     %d      ", score);
      mvprintw(16,x/2-5,"Hit q to exit");
      getch(); // Wait for a key to be pressed. 
      state = EXIT;
      break;

    case PAUSED:
      if ((arrow = read_escape(&c)) != NOCHAR) {
        if (arrow == PAUSE){
          state = MOVE_PIECE;
        }
      }
      break;
    case EXIT:
      return(highscores);  // Return the highscore structure back to main to be stored on disk. 
      break;
    }
    if (state != PAUSED){
      timeInMS += 0.001; //loop is 1ms long
      display_time(timeInMS, w->upper_left_x-15,w->upper_left_y+3);
  
      //game is over when 5 minutes have passed
      //if you want more or less time, just adjust the MAX_TIME var
      if (timeInMS >= MAX_TIME){
        state = GAME_OVER;
      }
    }

    int linesRemoved = prune_well(w);
    if (linesRemoved > 0)
    {
      score = compute_score(score, linesRemoved);
      display_score(score, w->upper_left_x-15,w->upper_left_y);  
    } //end if
    refresh();
    nanosleep(&tim,&tim_ret);
  }
}

/* game.c ends here */
