#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>

int isPrime(long num)
{
	if (num < 2)
		return 0;
	if (num < 4)
		return 1;
	if (num % 2 == 0 || num % 3 == 0)
		return 0;
	long max = (long)(sqrt(num));
	for (long i = 5; i <= max; i = i + 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int minimum, maximum, flag, count = 0, i, j;
	/* Inputs */
	printf("Enter a: ");
	scanf("%d", &minimum);
	printf("Enter b: ");
	scanf("%d", &maximum);

	clock_t t;
	t = clock();

	/* Generating and counting prime numbers */
	for (i = minimum; i <= maximum; i++)
	{
		if (isPrime(i) == 1)
		{
			// printf("%d ", i);
			count++;
		}
	}
	printf("\n Prime Count = %d", count);
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf(" Total time: %f sec\n", time_taken);

	return (0);
}