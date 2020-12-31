//栈的出入、队列的出入、汉诺塔的递归
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
#define NUM 5

void stackPush(stack<int> p, int n) {
    p.push(n);
}

void stackPop(stack<int> p) {
    p.pop();
}

void queuePush(queue<int> p, int n) {
    p.push(n);
}

void queuePop(queue<int> p) {
    p.pop();
}

int m = 0;
void move(char A, int n, char C) {
    printf("%d,%d,%c,%c\n",++m,n,A,C);
}
void haNoi(int n, char A, char B, char C) {
    if (n == 1) move(A, 1, C);  //将编号为1的从A搬到C
    else {
        haNoi(n-1, A, C, B);    //将A上边1~n-1的圆盘移到B，C做辅助塔
        move(A, n, C);  //将编号为n的圆盘从A移到C
        haNoi(n-1, B, A, C);    //将B上边1~n-1的圆盘移到A，C做辅助塔
    }
}

int main() {

    getchar();
    return 0;
}
