#include <stdio.h>
void EXCHANGE(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void ROTATE_RIGHT(int *p1, int p2, int N)
{
    int last = p1[p2 - 1];
    for (int i = p2 - 1; i > 0; i--)
    {
        EXCHANGE(&p1[i], &p1[i - 1]);
    }
    p1[0] = last;
}
int main()
{
    int N, p2;
    printf("Enter the size of the array : ");
    scanf("%d", &N);
    int A[N];
    printf("Enter the element of the array : ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter value of p2 : ");
    scanf("%d", &p2);
    printf("Before ROTATE : ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    ROTATE_RIGHT(A, p2, N);
    printf("\nAfter ROTATE : ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}