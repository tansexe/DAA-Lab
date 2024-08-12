#include <stdio.h>
#include <time.h>
void selection(int *, int);
void insertion(int *, int);
void revselection(int *, int);
int main()
{
    FILE *ptr;
    int n, i;
    clock_t t1, t2;
    double t;
    ptr = fopen("C:/TaniyaP/numbers.txt", "r");
    printf("Enter the number of elements you want to have in array : ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        fscanf(ptr, "%d", &a[i]);
    }
    selection(a, n);
    t1 = clock();
    insertion(a, n);
    t2 = clock();
    t = (double)((t2 - t1) / CLOCKS_PER_SEC * 1e9); //nanosecods 
    printf("\nBest case time is %lf", t);
    revselection(a, n);
    t1 = clock();
    insertion(a, n);
    t2 = clock();
    t = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
    printf("\nWorst case time is %lf", t);
}
void selection(int *a, int n)
{
    int i, j, minind, temp;
    for (i = 0; i < n - 1; i++)
    {
        minind = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[minind])
            {
                minind = j;
            }
        }
        if (minind != i)
        {
            temp = a[i];
            a[i] = a[minind];
            a[minind] = temp;
        }
    }
}
void insertion(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void revselection(int *a, int n)
{
    int i, j, minind, temp;
    for (i = 0; i < n - 1; i++)
    {
        minind = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[minind])
            {
                minind = j;
            }
        }
        if (minind != i)
        {
            temp = a[i];
            a[i] = a[minind];
            a[minind] = temp;
        }
    }
}