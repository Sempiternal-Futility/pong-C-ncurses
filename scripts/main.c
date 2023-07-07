#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include <pthread.h>
#include "../headers/sprites.h"
#include "../headers/input.h"

//TODO: 
// BALL DIAGONAL MOVEMENT IS TOO AGRESSIVE ON THE Y POSITION
// ADD DIAGONAL MOVEMENT

void *ball_func();

int main()
{
   setlocale(LC_ALL, ""); // Setting locale so that wide chars are supported

   initscr();
   clear();
   curs_set(0);
   noecho();


   short height = 6;  // Height of the bar
   
   // Left bar vars
   int *posYleft = malloc(sizeof(int)); // Position Y of the left bar
   *posYleft = LINES /2 - (height /2); // Middle of screen
   int posXleft = COLS /8; // Position X of the left bar (never changes)

   // Right bar vars
   int *posYright = malloc(sizeof(int)); // Position Y of the right bar
   *posYright = LINES /2 - (height /2); // Middle of screen
   int posXright = COLS /1.2; // Position X of the right bar (never changes)
   
   // Draws both bars
   draw_bar(height, posYleft, posXleft);
   draw_bar(height, posYright, posXright);

   // Writes "PUSH START" to the middle of the screen (this is needed to avoid visual bugs)
   move(LINES /2, COLS /2 -5);
   printw("PUSH START");
   getch(); // This getch is here to avoid visual bugs
   move(LINES /2, COLS /2 -5);
   printw("          "); 
   refresh();

   // Positions of the ball
   int *posYball = malloc(sizeof(int));
   int *posXball = malloc(sizeof(int));
   *posYball = LINES /2;
   *posXball = COLS /2;

   int *player_lost = malloc(sizeof(int));
   *player_lost = 0; // If the player loses, this will be 1
   int *args[] = {posYball, posXball, posYleft, posYright, player_lost}; // This array is used to pass arguments to the "ball_func" function
   pthread_t t1;
   pthread_create(&t1, NULL, ball_func, args); // Creates a separate thread for the ball

   // Gives control to the player
   char input = '0';
   int quit = 0;
   while (quit == 0)
   { 
      input = getch();
      quit = move_bar(input, height, posYleft, posXleft, posYright, posXright, *player_lost); // Func returns 1 when 'q' is pressed btw
   }

   free(posYleft);
   free(posYright);
   free(posYball);
   free(posXball);
   free(player_lost);

   endwin();
   return 0;
}

void *ball_func(int *args[]) // This function has all the ball stuff
{
   short height = 6;
   ball_move(args[0], args[1], args[2], args[3], args[4], height, right);

   free(args[0]); // Frees posYball
   free(args[1]); // Frees posXball
   free(args[4]); // Frees player_lost
}
