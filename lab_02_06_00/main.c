#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <sys/time.h>
#include <stdlib.h>
#define N 50000
#define INPUT_NUMBER -1
#define INPUT_SIZE -2


int output(float x)
{
    printf("%f\n", x);
    return 0;
}


int input(int *begin)
{
    for (int i = 0; i < N; i++)
        *(begin + i) = rand();
    return 0;
}


int process_2(int *end, int *arr)
{
    int maximum = *arr + *end;
    int n = end - arr + 1;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x-=2;
        if (*(arr + i) + *(end - i) > maximum)
            maximum = *(arr + i) + *(end - i);
    }
    return maximum;
}


int process_1(int *end, int arr[])
{
    int maximum = *arr + *end;
    int n = end - arr + 1;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x-=2;
        if (arr[i] + arr[n - i] > maximum)
            maximum = arr[i] + arr[n - i];
    }
    return maximum;
}


int process_3(int *end, int *arr)
{
    int maximum = *arr + *end;
    int n = end - arr + 1;
    for (int *i = arr; i < end; i++)
    {
        if (*(i + n) + *i > maximum)
            maximum = *(i + n) + *i;
        n -= 2;
    }
    return maximum;
}


int main()
{
    int arr[N] = { 0 }, num = 50;
    struct timeval start, end;
    int64_t sum = 0;
    input(arr);
    for (int j = num; j < 50000; j *= 10)
    {
        sum = 0;
        for (int i = 0; i < j; i++)
        {
            gettimeofday(&start, NULL);
            process_1(arr + N, arr);
            gettimeofday(&end, NULL);
            sum += (end.tv_sec - start.tv_sec) * 1000000LL +
                    (end.tv_usec - start.tv_usec);
        }
        printf("%" PRId64 " us\n", sum / j);
        sum = 0;
        for (int i = 0; i < j; i++)
        {
            gettimeofday(&start, NULL);
            process_2(arr + N, arr);
            gettimeofday(&end, NULL);
            sum += (end.tv_sec - start.tv_sec) * 1000000LL +
                    (end.tv_usec - start.tv_usec);
        }
        printf("%" PRId64 " us\n", sum / j);
        sum = 0;
        for (int i = 0; i < j; i++)
        {
            gettimeofday(&start, NULL);
            process_3(arr + N, arr);
            gettimeofday(&end, NULL);
            sum += (end.tv_sec - start.tv_sec) * 1000000LL +
                    (end.tv_usec - start.tv_usec);
        }
        printf("%" PRId64 " us\n", sum / j);
    }

    return 0;
}
