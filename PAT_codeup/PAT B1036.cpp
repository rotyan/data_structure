//四舍五入判断方法：以2为除数取余后根据结果是否为1，返回不同值
#include<stdio.h>
//题目：输入正方形边长3<=N=<20，以及组成元素（eg：a），中间间隔一个空格。输出：列元素数目是行的一半，画出一个正方形
/*
分析：俩函数，第一个打印第一行和最后一行，第二个打印中间几行。
*/
void drawF(int x,char a){
    for(int i=0;i<x;i++){
        printf("%c",a);
    }
    printf("\n");
}
void drawM(int a,char b){
    printf("%c",b);
    for(int i=1;i<a-1;i++){
        printf(" ");
    }
    printf("%c\n",b);
}

int FtoF(int x){
    if(x%2==1) return x/2+1;
    else return x/2;
}   //*【1】注意读题（四舍五入取整），四舍五入判断方法：以2为除数取余后根据结果是否为1，返回不同值

int main( ){
    int x;
    char a;
    scanf("%d %c",&x,&a);
    drawF(x,a);
    for(int i=0;i<FtoF(x)-2;i++){
        drawM(x,a);
    }
    drawF(x,a);
    return 0;
}
