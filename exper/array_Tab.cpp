//顺序表的插入、逆序 
#include<stdio.h>
#define MAX 20
struct Sorder{
    int length;
    int data[MAX];
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

void input(){
	int a[MAX+1],temp;
	for(int i=0;i<2;i++){
		a[i]=L.data[i];
	}
	for(int i=2;i<MAX+1;i++){
		a[i]=L.data[i-1];
	}
	a[2]=100;
	for(int i=0;i<MAX+1;i++){
	printf("%d\t",a[i]);
	}

}

int main(){
	int c;
    L.length=0;
    for(int i=0;i<MAX;i++){
    	printf("请输入第%d个数据：\n",i);
    	scanf("%d",&L.data[i]);
        L.length++;
    }
    do{ 
	    printf("\n1.输出线性表的逆序\n") ;
	    printf("2.输线性表里插入一个数据\n") ;
	    printf("0.退出程序\n") ;
		printf("\n请输入你的选择：");
	    scanf("%d",&c);
	   switch(c){
	   	case 1:{
	   		exchange();
			for(int i=0;i<MAX;i++){
        printf("%d\t",L.data[i]);
    }
	   		break;
	   	}
	   	case 2:{
	   		input();
	   		break;
	   	}
	   	case 0:{
	   		break;
	   	}
	   }
	   }while(c);
    return 0;
}
