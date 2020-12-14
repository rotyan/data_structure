//顺序表的逆序 
#include <stdio.h>
#define NUM 20

struct Sorder{
    int length; 
    int data[NUM + 1];    //数据域
}L; 

void exchange(){
	int temp; 
    //主要的算法代码，进行交换
     for(int i = 0; i < (L.length)/2; i++){
         temp = L.data[i]; 
         L.data[i] = L.data[L.length-i-1]; 
         L.data[L.length-i-1] = temp; 
    }
    //输出即为逆序
    printf("所得到的逆序输出为：\n"); 
}

void input(){
	int temp; 
	for(int i = NUM ; i <= 3; i--){
        L.data[i] = L.data[i-1];
	}
	L.data[2] = 100; 
	for(int i = 0; i < NUM + 1; i++){
	printf("%d\t",L.data[i]); 
	}
}

int main(){
	int c; 
    L.length = 0; 
       for(int i = 0; i < NUM; i++){
    	printf("请输入第%d个数据：\n",i); 
    	scanf("%d",&L.data[i]); 
        L.length++; 
    }
    exchange(); 
    for(int i = 0; i < NUM; i++){
        printf("%d  ",L.data[i]); 
    }
    printf("\n所得的插入后为：\n"); 
    input(); 
    getchar(); 
}