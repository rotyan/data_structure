#include <stdio.h>
#include <windows.h>
int main() {
    int n[3][2] = { {0, 1}, {3, 4}, {4, 2}};
    printf("%d \n", n[2]);   //不可以n(0)
    system("pause");
    return 0;
}