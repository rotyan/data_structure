#include<cstdio>
#define MAX 10 

struct node{
    int data;
    node* next;
}*L;
//创建链表
node* create(int Array[]){
    node *pre,*head,*p;
    head = new node;    //创建头节点
    //无前驱节点
    //数据域为空
    head->next = NULL;
    pre = head;
    for(int i = 0; i < MAX; i++){
        p = new node;
        pre->next = p;
        p->data = Array[i];
        p->next = NULL;
        pre = p;
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

int big(node* head,int x){
    int temp = -1;
    node* p = head->next;
    while(p != NULL){
        if()
    }
}

int main(){
    int a[10] = {123, 32, 24, 2, 3, 43, 2};
    L = create(a);
    L = L->next;
//计数1    int count = 0;
    while(L != NULL){
        printf("%d ", L->data);
		L = L->next;
//计数2        count++;
    }
//计数3    printf("\n%d",count);

    printf("\n");
    swap(L);
    while(L != NULL){
        printf("%d ", L->data);
		L = L->next;
    }
    getchar();
    return 0;
}