//【完成版】单链表的查找、插入、删除
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
void nodeInsert(node* head, int n, int m){  //经过算法笔记对照，这里不需要返回值
    if (n < 1 || n > NUM){
        printf("插入位置错误！");
        return;
    }
    int count = 1;  //计数器从1开始，头节点不算
    node* pre = head;   //插入操作发生在pre为插入位置前驱节点处
    while(n != count){  //一共会比较n次（最后一次直接跳出循环），实际上执行了n-1次循环语句（可用for代替）
        pre = pre->next;
        count++;
    }
    node* p = new node;
    p->data = m;
    p->next = pre->next;
    pre->next = p;
}
//head为头节点地址，n为插入数据的位置
void nodeDelete(node* head, int n){//要改！！！
    if (n < 1 || n > NUM){
        printf("删除位置错误！");
        return;
    }
    int count = 1;
    node* pre = head;
    while (pre != NULL){
        if(n == count){
            printf("在第%d个位置删除\n",count);
            pre->next = pre->next->next;
        }
        pre = pre->next;
        count++;
    }
}
//head为头节点地址，m为查找数据的值
int nodeSearch(node* head, int m){  //经过算法笔记对照，改进为while和if嵌套实现对单一数据的多次查找
    int count = 1, num = 0;  //计数器从1开始，头节点不算
    node* pre = head->next;     //查询操作发生在pre为插入位置处（非前驱处，注意比较）
    while (pre != NULL){
        if(m == pre->data){
            printf("查找元素在第%d个位置\n",count);
            num++;
        }
        pre = pre->next;
        count++;
    }   
    return num;
}

int main(){
    int a[] = {123,234453,456,65};
    node* L = Create(a);
    nodeInsert(L,4,1000);
    printf("该查找元素出现了%d次",nodeSearch(L,65));
    printf("\n");
    nodeDelete(L,4);
    L = L->next;
    while(L->next != NULL){
        printf("%d  ",L->data);
        L = L->next;
    }
    getchar();
    return 0;
}