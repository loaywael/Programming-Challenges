#include <stdio.h>
#include <cs50.h>
#include <math.h>


int get_owed(void);
int count_coins(int owed_amt);


int main(void)
{
    int owed_amt = get_owed();
    int coins = count_coins(owed_amt);
    printf("%i\n", coins);
}


int get_owed(void)
{
    float owed_amt = 0.0;
    do
    {
        owed_amt = get_float("Change owed: "); 
    }
    while (owed_amt <= 0);
    return round(owed_amt * 100);
}

int count_coins(int owed_amt)
{
    int coins = 0, cache = owed_amt;
    int quarter = 25, dime = 10, nickel = 5, penny = 1;
    
    do
    {
        if (cache >= quarter)
        {
            cache -= quarter;
        }
        
        else if (cache >= dime)
        {
            cache -= dime;
        }
        
        else if (cache >= nickel)
        {
            cache -= nickel;
        }
        
        else
        {
            cache -= penny;
        }

        coins++;
    }
    while (cache > 0);

    return coins;
}