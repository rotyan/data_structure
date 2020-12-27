#include<cstdio>
#include<queue>
using namespace std;

struct node {
    int data;  
    node* lchild;
    node* rchild;
};

node* newNode(int x);
//search函数用于查找二叉树中数据域为x的节点
void search(node* root, int x) {
    if (root == NULL) {
        printf("查找失败！！！\n");
        return;
    }
    if (x == root->data) {
        printf("%d\n", root->data);
    } else if (x < root->data) {
        search(root->lchild, x);
    } else {
        search(root->rchild, x);
    }
}
//二叉排序树的插入
void insert(node* &root, int x) {
    if (root == NULL) {
       root = newNode(x);
        return;
    }
    if (x == root->data) {
        printf("该值为%d的数据域节点存在\n", x);
        return;
    } else if (x < root->data) {
        insert(root->lchild, x);
    } else {
        insert(root->rchild, x);
    }
}
//二叉树的新建节点
node* newNode(int v) {   //生成一个新节点，v为节点权值
    node* Node = new node;
    Node->data = v; //节点权值为v
    Node->lchild = Node->rchild = NULL;
    return Node;
}
//二叉查找树的建立
node* Create(int data[], int n) {
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}
//运用广度优先遍历BFS遍历输出二叉树
void BFS(node* root) {
    queue<node*> q;
    q.push(root);
    int num(0), n(0);
    while (!q.empty()) {
        node* now = q.front();
        q.pop();
        printf("%d", now->data);
        num++;
        if (num < n) printf(" ");
        if (now->lchild != NULL) q.push(now->lchild);
        if (now->lchild != NULL) q.push(now->lchild);
    } 
}
//主函数
    int data[]={12,3,15,6,1,8,19,20,33,24,17};
    int n = sizeof(data)/4 + 1;
int main() {
    node* L = Create(data, n);
    search(L, 56);
    BFS(L);
    insert(L, 13);

    return 0;
}
