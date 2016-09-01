#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    bool lastprinted = true;
    string s;
    do{
        s = GetString();
    }while(s == NULL || strlen(s) == 0);
    
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        char c = s[i];
        if(isspace(c)){
            lastprinted = true;
            continue;
        }
        if(lastprinted){
        printf("%c", toupper(c));
        lastprinted = false;
        }
    }
    printf("\n");
}