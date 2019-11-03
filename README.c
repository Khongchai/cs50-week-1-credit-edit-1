#include <stdio.h>
int arithResult(int CreditNumArr[], int sum, int count);
int main ()

{
    long creditnumber;
    int count = 0;
    long ten = 1;
    printf("Enter credit card number     ");
    scanf("%ld", &creditnumber);
    while (count != strlen(creditnumber)) 
        
    {
        count++;
        ten *=10; //get the divisor for the Array.
    }

    long checkcardtype = ten / 100; //copy ten value into cardtype
    ten /=10; //remove 1 zero.
    int CreditNumArr[count];

    for (int i = 0; count > i; i++)//get every value for the array
    {
        CreditNumArr[i] = creditnumber / ten % 10;
        ten /=10;
    }
    int sum = 0; //perform arithmetic

    sum = arithResult(CreditNumArr, sum, count);

    long firsttwodigits;
    firsttwodigits = creditnumber / checkcardtype;
    int firstdigit = firsttwodigits/10;
    if (sum % 10 == 0)
    {
        if (firsttwodigits/10 == 4)
        {
            printf("Your card is a valid VISA\n");
        }
        else
        {
            switch (firsttwodigits)
            {
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            case 22:
                printf("Your card is a valid mastercard\n");
                break;
            case 34:
            case 37:
                printf("Your card is a valid AMEX\n");
                break;
            default:
                printf("Your card is is of other type");
               break;
            }
        }
    }
    else
        {
            printf("Your card is invalid");
        }

    return 0;
}

int arithResult(int CreditNumArr[], int sum, int count)
{
    int productdigits[count];
    int digitmod;
    int digitdiv;

    for (int i = count - 2; i >= 0; i -=2)
    {
        productdigits[i] = CreditNumArr[i]*2;
        if (productdigits[i] >= 10)
        {
            digitmod = productdigits[i] % 10;
            digitdiv = productdigits[i] / 10;
            sum += digitmod + digitdiv;
        }

        else
        {
             sum += productdigits[i];
        }
    }

    for (int y = count - 1; y >= 0; y -=2)
    {
        sum += CreditNumArr[y];
    }
    return sum;
}
