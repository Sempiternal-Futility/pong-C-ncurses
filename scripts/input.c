#include <ncurses.h>
#include "../headers/input.h"
#include "../headers/sprites.h"

int move_bar(char input, short height, int *posYleftB, int posXleftB, int *posYrightB, int posXrightB)
{
   if (input == 'w')
   {
      erase_bar(height, posYleftB, posXleftB);
      *posYleftB -= (height +1);
      draw_bar(height, posYleftB, posXleftB);
   }

   else if (input == 's')
   {
      erase_bar(height, posYleftB, posXleftB);
      *posYleftB -= (height -1);
      draw_bar(height, posYleftB, posXleftB);
   }

   else if (input == 'o')
   {
      erase_bar(height, posYrightB, posXrightB);
      *posYrightB -= (height +1);
      draw_bar(height, posYrightB, posXrightB);
   }

   else if (input == 'l')
   {
      erase_bar(height, posYrightB, posXrightB);
      *posYrightB -= (height -1);
      draw_bar(height, posYrightB, posXrightB);
   }

   else if (input == 'q')
      return 1;

   return 0;
}
