#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "../headers/sprites.h"
#include "../headers/input.h"

//TODO: 
// FINISH WRITING "ball_move" function, with all directions
// WRITE NEW THREAD FOR BALL MOVEMENT
// BALL DIAGONAL MOVEMENT IS TOO AGRESSIVE ON THE Y POSITION

int main()
{
   setlocale(LC_ALL, ""); // Setting locale so that wide chars are supported

   initscr();
   clear();
   curs_set(0);
   noecho();

/*
   short height = 6;  // Height of the bar
   
   // Left bar vars
   int *posYleft = malloc(sizeof(int)); // Position Y of the left bar
   *posYleft = LINES /2 - (height /2); // Middle of screen
   int posXleft = COLS /8; // Position X of the left bar (never changes)

   // Right bar vars
   int *posYright = malloc(sizeof(int)); // Position Y of the right bar
   *posYright = LINES /2 - (height /2); // Middle of screen
   int posXright = COLS /1.2; // Position X of the right bar (never changes)

   draw_bar(height, posYleft, posXleft);
   draw_bar(height, posYright, posXright);
   char input = '0';
   int quit = 0;
   while (quit == 0)
   { 
      input = getch();
      quit = move_bar(input, height, posYleft, posXleft, posYright, posXright); // Func returns 1 when 'q' is pressed btw
   }

   free(posYleft);
   free(posYright);
*/

   int *posYball = malloc(sizeof(int));
   int *posXball = malloc(sizeof(int));
   *posYball = LINES /2;
   *posXball = COLS /2;

   ball_move(posYball, posXball, up_left);

   free(posYball);
   free(posXball);

   endwin();
   return 0;
}
