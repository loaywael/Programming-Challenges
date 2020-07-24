#include <stdio.h>
#include <math.h>
#include <cs50.h>


long int get_credit_card(void);
void identify_card(long int card_no);


int main(void)
{
    long int card_no = get_credit_card();
    printf("CARD NUMBER: %ld\n", card_no);
    identify_card(card_no);
}


long int get_credit_card(void)
{
    long int card_no = 0;
    
    do
    {
        card_no = get_long("Number: ");
    }
    while (card_no < 0);
    return card_no;
}


void identify_card(long int card_no)
{
    long int master_no = card_no / pow(10, 14);  //splits the 1st digit
    long int master_card_size = pow(10, 16);  // used to count the digits in card_no
    long int amex_no = card_no / pow(10, 13);
    long int amex_card_size = pow(10, 15);
    long int visa_no = card_no / pow(10, 12);
    long int visa_16_no = card_no / pow(10, 15);
    long int visa_card_size = pow(10, 13);
  
    // VISA 1st digit, size conditions
    if (card_no / visa_card_size == 0)
    {
        if (visa_no == 4)
        {
            printf("VISA\n"); // size = 13, 1st digit = 4
        }
        
        else 
        {
            printf("INVALID\n");  // invalid 1st digit
        }
    }
    
    // AMEXCARD 1st digit, size conditions
    else if (card_no / amex_card_size == 0)
    {
        if (amex_no == 34 || amex_no == 37)
        {
            printf("AMEX\n"); // size = 15, 1st digit = 3
        }
        else 
        {
            printf("INVALID\n");  // invalid 1st digit
        }
    }
    
    // MASTERCARD 1st digit, size conditions
    else if (card_no / master_card_size == 0)
    {
        if (master_no == 51 || master_no == 52 || master_no == 53 || master_no == 54 || master_no == 55)
        {
            printf("MASTERCARD\n"); // size = 16, 1st digit = 5
        }
        else if (visa_16_no == 4)
        {
            printf("VISA\n"); // size = 16, 1st digit = 4
        }
        
        else 
        {
            printf("INVALID\n");  // invalid 1st digit
        }
    }
    
    else 
    {
        printf("INVALID\n");  // None size
    }
}