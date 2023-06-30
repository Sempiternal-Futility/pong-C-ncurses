// This header file contains all the stuff used within "sprites.c"

#define SPRITE "\u2588"

void draw_bar(short height, int *posY, int posX); // Draws the bar that the player can control
void erase_bar(short height, int *posY, int posX); // Erases the bar
void draw_ball(int *posY, int *posX); // Draws the ball
void erase_ball(int *posY, int *posX); // Erases the ball
void ball_move(int *posY, int *posX, int *posYbarleft, int *posYbarright, short dir); // Makes the ball move (last arg is the direction)
void game_over_msg(); // Prints to the screen a GAME OVER message

enum directions // These directions are used alongside the "ball_move" func.
{
   // Straight directions
   right = 0,
   left = 1,

   // Diagonal directions
   up_right = 2,
   up_left = 3,
   down_right = 4,
   down_left = 5
};
