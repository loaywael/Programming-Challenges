#include <cs50.h>
#include <stdio.h>


int get_height(void);
void make_right_brick(int no_steps);
void make_left_brick(int no_steps);

    
int main(void)
{
    int height = 0;

    height = get_height();
    make_right_brick(height);
}


int get_height(void)
{    
    // initialize user input
    int input = 0;
    do 
    {
        // prompt the user to enter a height
        input = get_int("Height: ");
    }
    while (input <= 0 || input > 8);
    return input;
}


void make_right_brick(int no_steps)
{
    for (int i = 1; i <= no_steps; i++)
    {
        // shift right
        for (int j = no_steps - i; j > 0; j--)
        {
            printf(" ");
        }
        // increase bricks
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}


void make_left_brick(int no_steps)
{
    for (int i = 1; i <= no_steps; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}