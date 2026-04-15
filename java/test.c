#include <stdio.h>

int main(void)
{
    int num;

    printf("Enter a number:  ");
    if (scanf("%d", &num) == 1)
        printf("U entered %d\n", num);
    else
        printf("Invalid Input\n");

    return 0;
}
