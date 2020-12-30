//单链表的查找、插入、删除
#include <cstdio>
#define NUM 5

struct  node{
    int data;
    node* next;
};

node* Create(int array[]){
    node *pre,*p,*head;
    head = new node;
    //头节点root没有数据域
    head->next = NULL;
    pre = head;
    for(int i = 0; i < NUM; i++){
        p =new node;
        p->data = array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}

/*node* insert(node* root){
    return;
}*/

int main(){
    int a[] = {123,234453,456,65};
    node* L = Create(a);
    L = L->next;
    while(L->next != NULL){
        printf("%d  ",L->data);
        L = L->next;
    }
    getchar();
    return 0;
}