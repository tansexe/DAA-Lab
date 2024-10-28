#include <stdio.h>

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j <= right - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;

        int partitionIndex = i + 1;

        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, right);
    }
}

int main() {
    char *filename = "C:/TaniyaP/numbers.txt";
    FILE *fp = fopen(filename, "r");
    
   if (fp == NULL) {
     printf("Error opening file: %s\n", filename);
    	return 1; 
   }
        
    int arr[10000]; 
    int count = 0; 

    int num;
    while (fscanf(fp, "%d", &num) == 1 && count < 1000) {
        arr[count] = num; 
        //printf("\n%d\n", arr[count]);  
        count++; 
    }
    
    fclose(fp);  

    quickSort(arr, 0, count - 1);
    int second_smallest = arr[1];
    int second_largest = arr[count - 2];
    

    printf("Second smallest element: %d\n", second_smallest);
    printf("Second largest element: %d\n", second_largest);
    
    return 0;
} 
