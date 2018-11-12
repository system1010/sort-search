#include <stdio.h>
#include <math.h>

//gcc fema.c -lm
int main() 
{
//a^n + b^n = c^n
	   
int a, b, c, n;
	   
for (n = 3; n < 1000; n++)
for (a = 1; a < 1000; a++)
for (b = 1; b < 100; b++)
for (c = 1; c < 1000; c++)
{
if (a != b && b != c && a != c)
{
if (pow(a,n) + pow(b,n) == pow(c,n))
{
printf("%i+%i=%i", pow(a,n),pow(b,n),pow(c,n));
}
}
}
}
