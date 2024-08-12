#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500

// Global variable to count comparisons
int comp_count = 0;

// Function prototypes
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
void read_file(const char *filename, int arr[], int *size);
void write_file(const char *filename, int arr[], int size);
void print_array(int arr[], int size);
void analyze_partitioning(int low, int high, int pivot_position);

int main()
{
    int arr[MAX_SIZE];
    int size;
    int option;
    clock_t start, end;
    double execution_time;

    while (1)
    {
        printf("\nMAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");

        printf("Enter option: ");
        scanf("%d", &option);

        const char *input_file;
        const char *output_file;

        switch (option)
        {
        case 1:
            input_file = "C:/TaniyaP/5th Semester/DAA-Lab/Day-3/inAsce.dat";
            output_file = "C:/TaniyaP/5th Semester/DAA-Lab/Day-3/outMergeAsce.dat";
            break;
        case 2:
            input_file = "C:/TaniyaP/5th Semester/DAA-Lab/Day-3/inDesc.dat";
            output_file = "C:/TaniyaP/5th Semester/DAA-Lab/Day-3/outMergeDesc.dat";
            break;
        case 3:
            input_file = "C:/TaniyaP/5th Semester/DAA-Lab/Day-3/inRand.dat";
            output_file = "C:/TaniyaP/5th Semester/DAA-Lab/Day-3/outMergeRand.dat";
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
            continue;
        }

        read_file(input_file, arr, &size);

        printf("Before Sorting:\n");
        print_array(arr, size);

        start = clock();
        comp_count = 0;
        quick_sort(arr, 0, size - 1);
        end = clock();

        printf("After Sorting:\n");
        print_array(arr, size);

        execution_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1e9; // in nanoseconds

        printf("Number of Comparisons: %d\n", comp_count);
        printf("Execution Time: %.0f nanoseconds\n", execution_time);

        write_file(output_file, arr, size);

        analyze_partitioning(0, size - 1, size / 2); // Example pivot position
    }

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        comp_count++;
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void read_file(const char *filename, int arr[], int *size)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fscanf(file, "%d", &arr[i]) != EOF)
    {
        i++;
    }
    *size = i;
    fclose(file);
}

void write_file(const char *filename, int arr[], int size)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void analyze_partitioning(int low, int high, int pivot_position)
{
    if (high - low <= 1)
    {
        printf("Partitioning scenario: Best-case (small problem size)\n");
        return;
    }

    int size = high - low + 1;
    if (pivot_position == (low + high) / 2)
    {
        printf("Partitioning scenario: Best-case (balanced partitioning)\n");
    }
    else if (pivot_position == low || pivot_position == high)
    {
        printf("Partitioning scenario: Worst-case (unbalanced partitioning)\n");
    }
    else
    {
        printf("Partitioning scenario: Unclear (not a standard partitioning)\n");
    }
}
