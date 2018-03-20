#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool checkKeyWord(string k);
bool encodeChar(int k, char c);
int *getKeyArray(string k);
int *keyArr;

int main(int argc,  string argv[])
{
    if(argc != 2 || argv[1] == NULL)
    {
        printf("Need a keyword!\n");
        return 1;
    }
    string key = argv[1];

    if(!checkKeyWord(key))
    {
        printf("Keyword should contain only letters!\n")    ;
        return 1;
    }
    keyArr = getKeyArray(key);
    int keyLength = strlen(key);
    string in;

    do
    {
        in = get_string();

    }while(in == NULL || strlen(in) == 0);

    for(int i = 0, k = 0, n = strlen(in); i < n; i++)
    {
        k %= keyLength;
        bool encoded = encodeChar(keyArr[k], in[i]);
        if(encoded)
        {
            k++;
        }
    }
    printf("\n");
}

bool encodeChar(int k, char c)
{
    bool encoded;
    if(isalpha(c))
    {
        int temp = (int) c;
        int upOrLow;
        if(isupper(c))
        {
            upOrLow = 65;
        }
        else
        {
            upOrLow = 97;
        }
        temp -= upOrLow;
        temp = (temp + k) % 26;
        printf("%c", temp + upOrLow);
        encoded = true;
    }
    else
    {
        printf("%c", c);
        encoded = false;
    }
    return encoded;
}

bool checkKeyWord(string k)
{
    if(k != NULL)
    {
        for(int i = 0, n = strlen(k); i < n; i++)
        {
            char ltr = k[i];
            if(!isalpha(ltr))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

int *getKeyArray(string k)
{
    int *nums = malloc(strlen(k));
    for(int i = 0, n = strlen(k); i < n; i++)
    {
        nums[i] = (int)(toupper(k[i]) - 65);
    }
    return nums;
}