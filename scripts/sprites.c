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

void ball_move(int *posY, int *posX, int *posYbarleft, int *posYbarright, short height, short dir)
{
   bool quit_loop = false;
   int posXleft = COLS /8;
   int posXright = COLS /1.2;

   if (dir == right)
   {
      while(quit_loop == false)
      {
         draw_ball(posY, posX);
         system("sleep 0.03s");
         erase_ball(posY, posX);
         *posX += 1;

         if (*posX > COLS)
         {
            quit_loop = true;
            game_over_msg();
         }

         else if (*posX == posXright)
         {
            /*
            if (*posY == *posYbarright -1 || *posY == *posYbarright -2 || *posY == *posYbarright -3 || *posY == *posYbarright -4 || 
                *posY == *posYbarright -5 || *posY == *posYbarright -6)
               ball_move(posY, posX, posYbarleft, posYbarright, left);*/

            bool check = false;

            for (short i = -5; i < height; i++)
            {
               if (*posY == (*posYbarright - height))
               {
                  check = true;
                  break;
               }

               height -= 1;
            }

            height = 6; // Resets height to its standard value
            if (check == true)
               ball_move(posY, posX, posYbarleft, posYbarright, height, left);
         }
      }
   }

   else if (dir == left)
   {
      while (quit_loop == false)
      {
         draw_ball(posY, posX);
         system("sleep 0.03s");
         erase_ball(posY, posX);
         *posX -= 1;

         if (*posX < 1)
         {
            quit_loop = true;
            game_over_msg();
         }

         else if (*posX == posXleft)
         {
            if (*posY == *posYbarleft -1 || *posY == *posYbarleft -2 || *posY == *posYbarleft -3 || *posY == *posYbarleft -4 || 
                *posY == *posYbarleft -5 || *posY == *posYbarleft -6)
               ball_move(posY, posX, posYbarleft, posYbarright, height, right);
         }
      }
   }

   else if (dir == up_right)
   {
      while (quit_loop == false)
      {
         draw_ball(posY, posX);
         system("sleep 0.03s");
         erase_ball(posY, posX);
         *posX += 1;
         *posY -= 1;

         if (*posX > COLS)
         {
            quit_loop = true;
            game_over_msg();
         }

         else if (*posY < 1)
         {
            quit_loop = true;
            ball_move(posY, posX, posYbarleft, posYbarright, height, down_right);
         }
      }
   }

   else if (dir == up_left)
   {
      while (quit_loop == false)
      {
         draw_ball(posY, posX);
         system("sleep 0.03s");
         erase_ball(posY, posX);
         *posX -= 1;
         *posY -= 1;

         if (*posX < 1)
         {
            quit_loop = true;
            game_over_msg();
         }

         else if (*posY < 1)
         {
            quit_loop = true;
            ball_move(posY, posX, posYbarleft, posYbarright, height, down_left);
         }
      }
   }

   else if (dir == down_right)
   {
      while (quit_loop == false)
      {
         draw_ball(posY, posX);
         system("sleep 0.03s");
         erase_ball(posY, posX);
         *posX += 1;
         *posY += 1;

         if (*posX > COLS)
         {
            quit_loop = true;
            game_over_msg();
         }

         else if (*posY > (LINES -2))
         {
            quit_loop = true;
            ball_move(posY, posX, posYbarleft, posYbarright, height, up_right);
         }
      }
   }

   else if (dir == down_left)
   {
      while (quit_loop == false)
      {
         draw_ball(posY, posX);
         system("sleep 0.03s");
         erase_ball(posY, posX);
         *posX -= 1;
         *posY += 1;

         if (*posX < 1)
         {
            quit_loop = true;
            game_over_msg();
         }

         else if (*posY > (LINES -2))
         {
            quit_loop = true;
            ball_move(posY, posX, posYbarleft, posYbarright, height, up_left);
         }
      }
   }
}

void game_over_msg()
{
   clear();
   move(LINES /2, (COLS /2 -10));
   printw("GAME OVER");
   getch();
}
