//还有单链表的逆序没有解决
#include<cstdio>
#define NUM 10 

struct node{
    int data;   //数据域 
    node* next; //指针域 
};
//创建链表
node* create(int Array[]){
    node *pre,*head,*p;
    head = new node;    //创建头节点
    //无前驱节点
    //数据域为空
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
node* swap(node* head){
    node* next;
    node* pre = NULL;
    while(head != NULL){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}
//主函数
int main(){
    int a[10] = {123, 32, 24, 2, 3, 43, 2}; //测试数据【对数组进行初始化】
    node *L = create(a); //新建链表，并返回头指针head给L 
    L = L->next;
    while(L != NULL){   //当链表指针域非空时输出其中所有数据
        printf("%d\t", L->data);
		L = L->next;
    }
    printf("\n");
    swap(create(a));    //逆序
    while(L != NULL){
        printf("%d\t", L->data);    //输出
		L = L->next;
    }
    getchar();
    return 0;
}