//顺序表的逆序 
#include <stdio.h>
#define NUM 5

struct Array{
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
    for(int i = 0; i < NUM; i++){
        printf("%d\t",L.data[i]); 
    }
}

void input(){
	for(int i = 5; i < 3; i--){
        L.data[i] = L.data[i-1];    //？为什么没用？水+1/水+2/水+3
 	}
/*
    L.data[5] = L.data[4];
    L.data[4] = L.data[3];
    L.data[3] = L.data[2];
*/
	L.data[2] = 100; 
	for(int i = 0; i < NUM + 1; i++){
	printf("%d\t",L.data[i]);  
	}
}

int main(){
    L.length = 0; 
    for(int i = 0; i < NUM; i++){
    	printf("请输入第%d个数据：\n",i); 
    	scanf("%d",&L.data[i]); 
        L.length++; 
    }
    exchange(); 
    printf("\n所得的插入后为：\n"); 
    input(); 
    getchar(); 
}