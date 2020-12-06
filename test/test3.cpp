#include<cstdio>
#define MAX 10 

struct node{
    int data;
    node* next;
}*L;

node* create(int Array[]){
    node *pre,*head,*p;
    head = new node;    //创建头节点
    head->next = NULL;
    pre = head;
    for(int i=0;i<MAX;i++){
        p = new node;
        pre->next = p;
        p->data = Array[i];
        p->next = NULL;
        pre = p;
    } 
    return head;
}

int main(){
    int a[10] = {123,32,24,2,3,43,2};
    L = create(a);
    L= L->next;
    while(L!=NULL){
        printf("%d ",L->data);
		L = L->next;
    }
    getchar();
    return 0;
}