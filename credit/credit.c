#include <cs50.h>
#include <stdio.h>

bool check_VISA(long card_number);
bool check_AMEX(long card_number);
bool check_MASTERCARD(long card_number);



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
        if (check_VISA(credit_card_number))
        {
            printf("VISA\n");
        }
        else if (check_AMEX(credit_card_number))
        {
            printf("AMEX\n");
        }
        else if (check_MASTERCARD(credit_card_number))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n")
    }
}

bool check_VISA(long card_number)
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

bool check_MASTERCARD(long card_number)
{

    if (card_number / 1000000000000000 == 51 || card_number / 1000000000000000 == 52 || card_number / 1000000000000000 == 53 || card_number / 1000000000000000 == 53 || card_number / 1000000000000000 == 54 || card_number / 1000000000000000 == 55)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_AMEX(long card_number)
{
    if (card_number / 1000000000000 == 4 || card_number / 1000000000000000 == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}