#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500

// Function prototypes
void merge(int arr[], int left, int mid, int right, int *comp_count);
void merge_sort(int arr[], int left, int right, int *comp_count);
void read_file(const char *filename, int arr[], int *size);
void write_file(const char *filename, int arr[], int size);
void print_array(int arr[], int size);

int main()
{
    int arr[MAX_SIZE];
    int size;
    int comp_count;
    int option;
    clock_t start, end;
    double execution_time;

    while (1)
    {
        printf("\nMAIN MENU (MERGE SORT)\n");
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
        merge_sort(arr, 0, size - 1, &comp_count);
        end = clock();

        printf("After Sorting:\n");
        print_array(arr, size);

        execution_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1e9; // in nanoseconds

        printf("Number of Comparisons: %d\n", comp_count);
        printf("Execution Time: %.0f nanoseconds\n", execution_time);

        write_file(output_file, arr, size);
    }

    return 0;
}

void merge(int arr[], int left, int mid, int right, int *comp_count)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        (*comp_count)++;
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right, int *comp_count)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid, comp_count);
        merge_sort(arr, mid + 1, right, comp_count);
        merge(arr, left, mid, right, comp_count);
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
