#include <pthread.h>
#include <math.h>

int number = 0;
long a, b;

int isPrime(long num)
{
    if (num < 2)
        return 0;
    if (num < 4)
        return 1;
    if (num % 2 == 0 || num % 3 == 0)
        return 0;
    long max = (long)(sqrt(num) / 6);
    for (long i = 5; i <= max; i = i + 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return 0;
        }
    }
    return 1;
}
void *check(void *threadid)
{
    long tid;
    tid = (long)threadid;
    while (a < b)
    {
        a++;
        int primeCheck = isPrime(a);
        if (primeCheck == 1)
            number++;
        printf("Thread: %d, num: %d, isPrime: %d \n", tid, a, primeCheck);
    }
    pthread_exit(NULL);
}
void run(int n)
{
    pthread_t threads[n];
    int error;
    int i;

    // create and run n thread
    for (i = 0; i < n; i++)
    {
        printf("run() : creating thread, %d\n", i);
        error = pthread_create(&threads[i], NULL, check, (void *)i);
        if (error)
        {
            printf("Error:unable to create thread, %d\n", error);
            exit(-1);
        }
    }

    // wait for n thread done
    for (int i = 0; i < n; i++)
        pthread_join(threads[i], NULL);

    printf("\n Number: %d", number);
    return 0;
    pthread_exit(NULL);
}
int main()
{
    int n;
    printf("Nhap a: ");
    scanf("%d", &a);
    a--;
    printf("Nhap b: ");
    scanf("%d", &b);
    printf("Nhap n: ");
    scanf("%d", &n);

    run(n);
}