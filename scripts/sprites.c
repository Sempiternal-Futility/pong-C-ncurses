// This script draws all the graphics

#include "../headers/sprites.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>

void draw_bar(short height, int *posY, int posX)
{
   for (short i = 0; i < height; i++)
   {
      move(*posY, posX);
      printw(SPRITE);
      *posY += 1;
   } 
}

void erase_bar(short height, int *posY, int posX)
{
   *posY -= height;
   for (short i = 0; i < height; i++)
   {
      move(*posY, posX);
      printw(" ");
      *posY += 1;
   }
}

void draw_ball(int *posY, int *posX)
{
   move(*posY, *posX);
   printw(SPRITE);

   move(*posY, *posX -1);
   printw(SPRITE);
   refresh();
}

void erase_ball(int *posY, int *posX)
{
   move(*posY, *posX);
   printw(" ");
   
   move(*posY, *posX -1);
   printw(" ");
   refresh();
}

void ball_move(int *posY, int *posX, short dir)
{
   bool quit_loop = false;

   if (dir == right)
   {
      while(quit_loop == false)
      {
         draw_ball(posY, posX);
         system("sleep 0.03s");
         erase_ball(posY, posX);
         *posX += 1;

         if (*posX > COLS)
            quit_loop = true;
      }
   }

   else if (dir == left)
      printw("FUCK!");
}
