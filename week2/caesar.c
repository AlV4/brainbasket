#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encodeChar(int k, char c);

int main(int argc,  string argv[])
{
    if(argc != 2)
    {
        printf("Need a positive integer!\n");
        return 1;
    }
    int k = atoi(argv[1]) % 26;
    string in;
    do
    {
        in = get_string();

    }while(in == NULL || strlen(in) == 0);

    for(int i = 0, n = strlen(in); i < n; i++)
    {
        encodeChar(k, in[i]);
    }
    printf("\n");
}

void encodeChar(int k, char c)
{
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
    }
    else
    {
        printf("%c", c);
    }
}