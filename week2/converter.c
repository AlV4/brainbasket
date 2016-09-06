#include <stdio.h>
#include <cs50.h> 


int main()
{
	// create counters, base, input number vars
	int count, i, ncount, n, base;
	
	printf("Please give me the base from 2 to 10\n");
	
	// get base
	do{
	base = GetInt();
	}while(base < 2 || base > 10);
	
	int bits[32];
	// initialise each position in empty array as 0
	for(int k = 0; k < 32; k++){
	    bits[k] = 0;
	}
	int d = 1;
	
	// length of the number
	count = 0;
	printf("Please enter the decimal positive integer, which you want to convert\n");
	do{
	n = GetInt(); // in decimal 
	}while(n < 0);
	// calculating digits quantity
	do
	{
		d = d * base;
		count++;
	}
	while (d * base <= n);
	ncount = count;

	// filling array by desired digits
	while (count >= 0)
	{
		if (n / d > 0)
		{
			bits[count] = n / d;
			n = n % d;
		} 
		d = d / base;
		count--;
	}
	
	// printing out number
	for (i = ncount; i >= 0; i-- )
	{
		printf("%d", bits[i]);
	}
	printf("\n");

}