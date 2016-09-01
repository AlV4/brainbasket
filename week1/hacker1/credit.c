#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool isCardLengthOk(long long num);
int *getArray(long long n);
bool checkEvenOdd();
void checkCardType();
int numPlaces(long long n);

long long cardNumber;
int length;
int *array;

int main(void)
{
    do
    {
        printf("Please enter the number of card.\n");
        cardNumber = GetLongLong();        
    }while(cardNumber < 0);
    
    if(!isCardLengthOk(cardNumber)){
        printf("INVALID\n");
        
        return 0;
    }
    array = getArray(cardNumber);
    
    if(!checkEvenOdd())
    {
        printf("INVALID\n");
    }
    else
    {
        checkCardType();    
    }
}

void checkCardType()
{
    if((length == 13 || length == 16) && array[0] == 4)
    {
        printf("VISA\n");
        return;
    }
    if(length == 16 && array[0] == 5 && array[1] > 0 && array[1] < 6)
    {
        printf("MASTERCARD\n");
        return;
    }
    if(length == 15 && array[0] == 3 && (array[1] == 4 || array[1] == 7))
    {
        printf("AMEX\n");
        return;
    }
}


int *getArray(long long n)
{
    int *nums = malloc(length);
    for(int i = length - 1; i >= 0; i--)
    {
        nums[i] = n % 10;
        n /= 10;
    }
    return nums;
}

bool isCardLengthOk(long long num)
{
length = numPlaces(num);  

    if( length < 13 || length > 16 || length == 14)
    {
        return false;
    }else{
    return true;    
    }
}

int numPlaces (long long n) {
    if (n < 10)
    {
        return 1;
    }else{
        return 1 + numPlaces (n / 10);
    }
}

bool checkEvenOdd()
{
    int res = 0;
    int odd = 0;
    for(int i = 0; i < length; i++)
    {
        int temp = 0;
        if(i % 2 == 0)
        {
        temp = array[i] * 2;
            if(temp >= 10)
            {
                temp-=9;
            }
        odd+=temp;
        }
        else
        {
           res+=array[i];
        }
        printf("%d",array[i]);
    }
    res+=odd;

        
    if(res % 10 == 0){
        return true;
    }
    return false;
}