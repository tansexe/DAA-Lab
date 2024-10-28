#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter Number: ");
    scanf("%d", &n);

    int binary[32];
    int i = 0;
    while (n > 0)
    {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("Binary: ");
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    printf("\n");

    return 0;
}