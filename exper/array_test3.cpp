//顺序表的逆序 
#include<stdio.h>
#define NUM 2

struct Sorder{
    int length;
    int data[NUM+1];   //数据域
}L;

void exchange(){
	int temp;
    //主要的算法代码，进行交换
     for(int i=0;i<(L.length)/2;i++){
         temp=L.data[i];
         L.data[i]=L.data[L.length-i-1];
         L.data[L.length-i-1]=temp;
    }
    //输出即为逆序
    printf("所得到的逆序输出为：\n");
}

int main(){
	int c;
    L.length=0;
       for(int i=0;i<NUM;i++){
    	printf("请输入第%d个数据：\n",i);
    	scanf("%d",&L.data[i]);
        L.length++;
    }
    exchange();
    for(int i=0;i<NUM;i++){
        printf("%d\n",L.data[i]);
    }
    getchar();
}