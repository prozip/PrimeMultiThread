#include <pthread.h>
#include <math.h>
#include <time.h>

int number = 0;
long a, b;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

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

void *check(void *threadid)
{
    long tid;
    tid = (long)threadid;
    while (a < b)
    {
        pthread_mutex_lock(&mutex);

        ++a;

        pthread_mutex_unlock(&mutex);

        int primeCheck = isPrime(a);
        if (primeCheck == 1)
        {
            pthread_mutex_lock(&mutex);
            number++;
            pthread_mutex_unlock(&mutex);
        }

        // printf("Thread: %d, num: %d, isPrime: %d \n", tid, a, primeCheck);
    }
    pthread_exit(NULL);
}
void run(int n)
{
    pthread_t threads[n];
    int error;
    int i;
    clock_t t;
    t = clock();

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

    printf("\n Number: %d\n", number);

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf(" Total time: %f sec\n", time_taken);

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