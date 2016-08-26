#include <stdio.h>
#include <cs50.h>
#include <math.h>

void countCounter(int amount);
void pickCoinAmount();

float input;
int sum = 0;
int coinsTotal = 0;
int coins[] = {25,10,5,1};
    
int main(void)
{
    do
    {
        printf("O hai! How much change is owed?\n");
        input = GetFloat();
        
    }while( input < 0 || input > 100 );
    
    sum = (int)round(input * 100);
    
    pickCoinAmount();
    
    printf("%d\n", coinsTotal);
}

void coinCounter(int amount)
{
    while(sum >= amount)
    {
        if(sum / amount > 0)
        {
        int crntCoins = sum / amount;
        sum = sum % amount;
        coinsTotal+=crntCoins;
        }
    }
    return;
}

void pickCoinAmount()
{
     for(int idx = 0; idx < 4; idx++)
     {
        int n = coins[idx];
        coinCounter(n);
    }
}