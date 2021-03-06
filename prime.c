#include <stdio.h>
#include <math.h>

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
    printf("%d", isPrime(500000));
    getch();
}
