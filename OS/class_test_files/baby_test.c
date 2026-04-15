#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    int x = 10;
    int *ptr;
    ptr = (int*) malloc(100 * sizeof(int));
    printf("Address of variable x: %p\n", &x);
    printf("Address of allocated memory (ptr): %p\n", ptr);
    printf("Process ID (PID): %d\n", getpid());
    printf("Press Enter to continue...");
    getchar();
    free(ptr);
    return 0;
}

