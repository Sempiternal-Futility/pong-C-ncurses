// This script draws all the graphics

#include "../headers/sprites.h"
#include <ncurses.h>

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
