#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("Enter the elements of the array : ");
    int arr[n], prefixSum[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        prefixSum[i] = 0;
        for (int j = 0; j <= i; j++)
        {
            prefixSum[i] = prefixSum[i] + arr[j];
        }
    }
    printf("Prefix sum of the array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", prefixSum[i]);
    }
    return 0;
}