#include<stdio.h>
#include<time.h>
void selection(int*,int);
int binarySearch(int*,int,int,int);
int main()
{
    FILE *ptr;
    int n,i,m,c;
    clock_t t1,t2;
    double t;
    ptr = fopen("C:/TaniyaP/numbers.txt","r");
    printf("Enter the number of elements you want to have in array: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        fscanf(ptr,"%d",&a[i]);
    }
    selection(a,n);
    printf("Enter the number you want to search: ");
    scanf("%d",&m);
    t1 = clock();
    c = binarySearch(a,0,n-1,m);
    if(c!=-1)
    {
        printf("\nElement found.");
        printf("\nNumber of iterations = %d",c);
    }
    else
    {
        printf("\nElement not found.");
    }
}
void selection(int *a, int n)
{
    int i,j,minind,temp;
    for(i=0;i<n-1;i++)
    {
        minind = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[minind])
            {
                minind = j;
            }
        }
        if (minind != i)
        {
            temp = a[i];
            a[i]=a[minind];
            a[minind]=temp;
        }
    }
}
int binarySearch(int *arr, int low, int high, int x)
{
    int c = 0;
    while (low <= high) 
    {
        c++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            return c;
        }
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}