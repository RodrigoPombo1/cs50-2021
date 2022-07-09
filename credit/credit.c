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
    // while loop to get the number of digits
    long aux = credit_card_number;
    int sum = 0;
    int sum2 = 0;
    int digit;
    int aux3 = 0;
    while (aux > 0)
    {
        //chooses last digit (always never the second to last)
        digit = aux % 10;
        //sum2 of the digits that weren't multiplied by 2
        sum2 += digit;
        //no longer need the digit from the credit card number, so remove it
        aux = aux / 10;
        //get only the digit because it's the one that needs to be multiplied by 2
        digit = aux % 10;
        //multiplies digit by 2
        aux3 = digit * 2;
        //gets the last digit of the sum
        sum += aux3 % 10;
        //if by multiplying by 2 the digit became a number with 2 digits, than we need to get the second digit, then it need to execute the code inside the if statement
        if (aux3 >= 10)
        {
            aux3 = aux3 / 10; //remove unit digit from the number (no longer needed)
            sum += aux3; //gets the remaining digit
        }
        aux = aux / 10;
    }
    int aux2 = sum + sum2;
    if (aux2 % 10 == 0)
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
        printf("INVALID\n");
    }
}

bool check_AMEX(long card_number)
{
    if (card_number / 10000000000000 == 34 || card_number / 10000000000000 == 37)
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
    if (card_number / 100000000000000 == 51 || card_number / 100000000000000 == 52 || card_number / 100000000000000 == 53
         || card_number / 100000000000000 == 53 || card_number / 100000000000000 == 54 || card_number / 100000000000000 == 55)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_VISA(long card_number)
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