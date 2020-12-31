//单链表的查找、插入、删除
#include <cstdio>
#define NUM 5   //新建的单链表节点个数

struct  node{
    int data;
    node* next;
};
//array为初始化时输入数据域所在数组
node* Create(int array[]){
    node *pre, *p, *head;
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
//head为头节点地址，n为插入数据的位置，m为插入数据的值
node* nodeInsert(node* head, int n, int m){ //没有对初始输入数据位置进行判断！！！
    int count = 1;  //计数器，头节点不算
    node *pre, *p;
    pre = head;
    while(n != count){
        pre = pre->next;
        count++;
    }
    p = new node;
    p->data = m;
    p->next = pre->next;
    pre->next = p;
    return head;
}
//head为头节点地址，n为插入数据的位置
node* nodeDelete(node* head, int n){
    int count = 1;
    node *pre;
    pre = head;
    while(n != count){
        pre = pre->next;
        count++;
    }
    pre->next = pre->next->next;
    return head;
}
//head为头节点地址，m为查找数据的值
node* nodeSearch(node* head, int m){
    int count = 0;  //这里算上了头节点，所以为计数器为零
    node *pre;
    pre = head;
    while(m != pre->data){
        pre = pre->next;
        count++;
    }
    printf("在第%d个位置",count);
    return head;
}

int main(){
    int a[] = {123,234453,456,65};
    node* L = Create(a);
    nodeInsert(L,5,1000);
    nodeSearch(L,65);
    printf("\n");
//    nodeDelete(L,3);
    L = L->next;
    while(L->next != NULL){
        printf("%d  ",L->data);
        L = L->next;
    }
    getchar();
    return 0;
}