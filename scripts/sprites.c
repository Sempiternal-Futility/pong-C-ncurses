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

         else if (*posX == (posXright -1))
         {
            bool check_up = false; // If true, ball "bounces" diagonal up
            bool check_down = false; // If true, ball "bounces" diagonal down
            bool check_straight = false; // If true, ball "bounces" straight

            for (short i = 0, height_straight = height; i < height; i++)
            {
               if (*posY == (*posYbarright - 1) || *posY == (*posYbarright - 2))
               {
                  check_up = true;
                  break;
               }

               else if (*posY == (*posYbarright - height) || *posY == (*posYbarright - (height -1)))
               {
                  check_down = true;
                  break;
               }

               else if (*posY == (*posYbarright - height_straight))
               {
                  check_straight = true;
                  break;
               }

               height_straight -= 1;
            }
            
            if (check_up == true)
               ball_move(posY, posX, posYbarleft, posYbarright, height, up_left);

            else if (check_down == true)
               ball_move(posY, posX, posYbarleft, posYbarright, height, down_left);

            else if (check_straight == true)
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

         else if (*posX == (posXleft +2))
         {
            bool check_up = false; // If true, ball "bounces" diagonal up
            bool check_down = false; // If true, ball "bounces" diagonal down
            bool check_straight = false; // If true, ball "bounces" straight

            for (short i = 0, height_straight = height; i < height; i++)
            {
               if (*posY == (*posYbarleft - 1) || *posY == (*posYbarleft - 2))
               {
                  check_up = true;
                  break;
               }

               else if (*posY == (*posYbarleft - height) || *posY == (*posYbarleft - (height -1)))
               {
                  check_down = true;
                  break;
               }

               else if (*posY == (*posYbarleft - height_straight))
               {
                  check_straight = true;
                  break;
               }

               height_straight -= 1;
            }
            
            if (check_up == true)
               ball_move(posY, posX, posYbarleft, posYbarleft, height, up_right);

            else if (check_down == true)
               ball_move(posY, posX, posYbarleft, posYbarleft, height, down_right);

            else if (check_straight == true)
               ball_move(posY, posX, posYbarleft, posYbarleft, height, right);
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
