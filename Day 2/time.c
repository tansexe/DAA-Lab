#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// swapping function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// selection sort
int selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}

int main()
{
    int size = 100000;
    int arr[size], i;
    for (i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    clock_t start = clock();
    selectionSort(arr, size);
    clock_t end = clock();
    double exec_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %lf seconds\n", exec_time);

    return 0;
}