#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "../headers/sprites.h"
#include "../headers/input.h"

int main()
{
   setlocale(LC_ALL, ""); // Setting locale so that wide chars are supported

   initscr();
   clear();
   curs_set(0);
   noecho();


   short height = 6;  // Height of the bar
   
   // Left bar vars
   int *posYleftB = malloc(sizeof(int)); // Position Y of the left bar
   *posYleftB = LINES /2 - (height /2); // Middle of screen
   int posXleftB = COLS /8; // Position X of the left bar (never changes)

   // Right bar vars
   int *posYrightB = malloc(sizeof(int)); // Position Y of the right bar
   *posYrightB = LINES /2 - (height /2); // Middle of screen
   int posXrightB = COLS /1.2; // Position X of the right bar (never changes)

   draw_bar(height, posYleftB, posXleftB);
   draw_bar(height, posYrightB, posXrightB);
   char input = '0';
   int quit = 0;
   while (quit == 0)
   { 
      input = getch();
      quit = move_bar(input, height, posYleftB, posXleftB, posYrightB, posXrightB); // Func returns 1 when 'q' is pressed btw
   }

   free(posYleftB);
   endwin();
   return 0;
}
