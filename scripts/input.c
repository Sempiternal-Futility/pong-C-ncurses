#include <ncurses.h>
#include <stdlib.h>
#include "../headers/input.h"
#include "../headers/sprites.h"

int move_bar(char input, short height, int *posYleft, int posXleft, int *posYright, int posXright, int *posYball, int *posXball)
{
   if (input == 'w')
   {
      erase_bar(height, posYleft, posXleft);

      if (*posYleft > height) // Checks if the bar has hit the boundary (top) of the screen
         *posYleft -= (height +1);
      else
         *posYleft -= (height -1);

      draw_bar(height, posYleft, posXleft);
   }

   else if (input == 's')
   {
      erase_bar(height, posYleft, posXleft);

      if (*posYleft < LINES) // Checks if the bar has hit the boundary (bottom) of the screen
         *posYleft -= (height -1);
      else
         *posYleft -= (height +1);

      draw_bar(height, posYleft, posXleft);
   }

   else if (input == 'k')
   {
      erase_bar(height, posYright, posXright);
      
      if (*posYright > height)
         *posYright -= (height +1);
      else
         *posYright -= (height -1);

      draw_bar(height, posYright, posXright);
   }

   else if (input == 'j')
   {
      erase_bar(height, posYright, posXright);

      if (*posYright < LINES)
         *posYright -= (height -1);
      else
         *posYright -= (height +1);

      draw_bar(height, posYright, posXright);
   }

   else if (input == 'q')
   {
      free(posYball);
      free(posXball);
      return 1;
   }

   return 0;
}
