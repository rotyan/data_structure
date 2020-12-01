//三种交换方式，值传递、指针传递、引用传递
/*output: 
21,22  
22,21 
111,222  
111,222 
432,123  
432,123 
*/  
#include <stdio.h>  
void change(int* &p,int* &q){   //引用传递，交换地址，注意不能直接传入地址常量，要借助指针变量
    int* temp=p;     
    p=q;  
    q=temp; 
}  
void swap(int* p,int* q){     //指针传递，用指针交换值，本质还是值传递
    int temp = *p;     
    *p = *q;     
    *q = temp;      
}  
void nodec(int* a,int* b){      //指针传递，有两布多余的步骤
    int x;     
    int* temp = &x;     
    *temp = *a;     
    *a = *b;     
    *b = *temp; 
    } 
int main() {     
    int a=21,b=22;     
    int *p1=&a,*p2=&b;     
    change(p1,p2);   //不能用change(&a,&b);     
    printf("%d,%d\n %d,%d\n",a,b,*p1,*p2);          
    int x=111,y=222;     
    int *x1=&x,*x2=&y;     
    swap(x1,x2);     
    swap(&x,&y);     
    printf("%d,%d\n %d,%d\n",x,y,*x1,*x2);          
    int q=432,w=123;     
    int *w1=&q,*w2=&w;     
    nodec(&q,&w);     
    nodec(w1,w2);     
    printf("%d,%d\n %d,%d",q,w,*w1,*w2); 
    getchar();     	
    return 0; 
}