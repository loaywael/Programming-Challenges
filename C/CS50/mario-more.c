#include <cs50.h>
#include <stdio.h>


int get_height(void);
void make_pyramid(int no_steps);
void make_left_brick(int step_index, int no_steps);
void make_right_brick(int step_index, int no_steps);


int main(void)
{
    // initialize height
    int height = 0;
    // enter hill height
    height = get_height();
    // plot pyramid
    make_pyramid(height);
}


int get_height(void)
{    
    int input = 0;
    do 
    {
        input = get_int("Height: ");
    }
    while (input <= 0 || input > 8);
    return input;
}


void make_pyramid(int no_steps)
{
    for (int step_index = 1; step_index <= no_steps; step_index++)
    {
        make_right_brick(step_index, no_steps);
        printf("  ");
        make_left_brick(step_index, no_steps);
        printf("\n");
    }
}


void make_right_brick(int step_index, int no_steps)
{
    // shift right
    for (int j = no_steps - step_index; j > 0; j--)
    {
        printf(" ");
    }
    // increase bricks
    for (int j = 1; j <= step_index; j++)
    {
        printf("#");
    }
}


void make_left_brick(int step_index, int no_steps)
{
    for (int j = 0; j < step_index; j++)
    {
        printf("#");
    }
}