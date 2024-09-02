#include <stdio.h>

int binarySearch(int arr[], int target, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) 
    {
        return mid;
    }

    else if (arr[mid] > target)
    {
        return binarySearch(arr, target, low, mid - 1);
    }
    else
    {
        return binarySearch(arr, target, mid + 1, high);
    } 
}

int main()
{
    int n, targetValue;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int sortedArray[n];

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sortedArray[i]);
    }

    printf("Enter the target value to search for: ");
    scanf("%d", &targetValue);

    int result = binarySearch(sortedArray, targetValue, 0, n - 1);

    if (result != -1)
    {
        printf("Element found at index: %d\n", result);
    }
    else
    {
        printf("Element not found in the array.\n");
    }

    return 0;
}