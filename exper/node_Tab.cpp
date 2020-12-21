//单链表、顺序表的查找、插入、逆序
 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std; 
/*
单链表 
struct node {
	typename data; //数据域 
	node *next;	//指针域 
};

//typename* p=new typename;	//申请动态空间的运算符
//delete(p);	//释放内存空间 
//sort(首元素地址（必填），尾元素地址的下一个地址（必填），比较函数（非必填）） 
*/
   
struct node{
	int data;
	node *next;
};
//创建链表 
node* create(int Array[]){
	node *p,*pre,*head;	//head为头节点；pre保存当前节点之前的节点 
	head = new node;	//创建头节点 
	head->next = NULL;	//头节点无数据，指针域初始为NULL 
	pre = head;	//记录头节点为pre 
	for(int i=0;i<10;i++){
		p=new node;	//新建节点 
		p->data = Array[i];	//新建节点的 数据域被Array [i]数组赋值，也可通过scanf输入 
		p->next = NULL;	//新节点的指针域为NULL 
		pre->next = p;	//新建节点之前的节点的指针域地址为当前节点地址 
		pre = p;	//使当前节点成为下一个节点的之前节点 
	}
	return head;
}

//逆序
bool cmp(int a,int b){
	return a>b;	//当a>b的时候输出a 
}
  
int main(){    
	int a[10]={1,2,3,4,5,6,7,8,9,0};  //对数组进行初始化 
	sort(a,a+10,cmp);
    node *L = create(a);   	//新建链表，并返回头指针head给L 
	L = L->next; 	//从第一个节点开始有数据域 
	while(L!=NULL){
		printf("%d ",L->data);
		L = L->next;
	}
	printf("\nend"); 
    getchar();
	return 0;   
}

