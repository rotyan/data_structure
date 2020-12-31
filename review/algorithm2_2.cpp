//【完成版】单链表的查找、插入、删除【教材版本，主要是增删查的函数返回值为node】
#include <cstdio>
#define NUM 5   //新建的单链表节点个数

struct  node{
    int data;
    node* next;
};
//array为初始化时输入数据域所在数组
node* Create(int array[]) {
    node *pre, *p, *head;
    head = new node;
    //头节点root没有数据域
    head->next = NULL;
    pre = head;
    for (int i = 0; i < NUM; i++) {
        p =new node;
        p->data = array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}
//head为头节点地址，n为插入数据的位置，m为插入数据的值
node* nodeInsert(node* head, int n, int m){     //教材为c++写法，没看
    if (n < 1 || n > NUM){
        printf("插入位置错误！");
        return 0;
    }
    int count = 1;  //计数器从1开始，头节点不算
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
node* nodeDelete(node* head, int n){    //教材为c++写法，没看
    if (n < 1 || n > NUM){
        printf("删除位置错误！");
        return 0;
    }
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
    node *p = head->next;
    while(p && p->data != m){
        p = p->next;
    }
    return p;   //查找成功返回值为m的节点地址p，查找失败为NULL
}

int main(){
    int a[] = {123,234453,456,65};
    node* L = Create(a);
    nodeInsert(L,4,1000);
    printf("该查找元素出现了%d次",nodeSearch(L,65));    //暂时没有改正
    printf("\n");
    nodeDelete(L,1000);
    L = L->next;
    while(L->next != NULL){
        printf("%d  ",L->data);
        L = L->next;
    }
    getchar();
    return 0;
}