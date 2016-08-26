#include <stdio.h>
#include <cs50.h>
int main (void)
{
int step, idxOut, idxIn;
do 
{
   printf ("Please give me an int between 1 and 23:\n");
   step = GetInt ();
}
  while (step < 0 || step > 23);

    for (idxOut = step; idxOut > 0; idxOut--)
   {
       for (idxIn = 0; idxIn < step * 2 + 3 - idxOut; idxIn++)
       {
            if(idxIn < idxOut - 1 || idxIn > step * 2 + 2  - idxOut || idxIn == step || idxIn == step + 1)
            {
            printf (" ");
            }else{
            printf("#");
            }
       }
       
    printf ("\n");
       
   }

}