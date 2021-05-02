// 助教面试问题一输出二维数组第一维结果为地址值
#include <stdio.h>
#include <windows.h>
int main() {
    int n[3][2] = { {0, 1}, {3, 4}, {4, 2}};
    printf("%d \n", n[2]);   //不可以n(0)//%d和之后换行符之间要有空格
    system("pause");
    return 0;
}