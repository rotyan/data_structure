//【完成版】顺序表的逆序 
#include <stdio.h>
#define NUM 20

struct Array{
    int length; 
    int data[NUM + 1];    //数据域，注意设置比原本长度大1，方便之后插入一个数值
}L; 

void exchange(){
	int temp; 
    //主要的算法代码，进行交换
    for(int i = 0; i < (L.length)/2; i++){
         temp = L.data[i];      //中间变量temp存放要交换的数据
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
	for(int i = NUM; i > 3; i--){
        L.data[i] = L.data[i-1];    //从L.data[1]之后所有数据往后移动一格
 	}
	L.data[2] = 100; 
	for(int i = 0; i < NUM + 1; i++){
	    printf("%d\t",L.data[i]);  //输出所有数据
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
    return 0;
}