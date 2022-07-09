#include <cs50.h>
#include <stdio.h>

bool check_VISA(int card_number);
bool check_AMEX(int card_number);
bool check_MASTERCARD(int card_number);



int main(void)
{
    long credit_card_number;
    do
    {
        credit_card_number = get_long("Number: ");
    }
    while (credit_card_number < 0);
    if
    {
        
    }
    else
    {
        printf("INVALID\n")
    }
}

bool check_VISA(int card_number)
{

    if ()
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_MASTERCARD(int card_number)
{

    if ()
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_AMEX(int card_number)
{

    if ()
    {
        return true;
    }
    else
    {
        return false;
    }
}