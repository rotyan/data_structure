// 二叉查找树的递归查找、插入、创建
#include<cstdio>

struct node{
    int data;
    node* lchild;
    node* rchild;
};

node* Create(int array[], int n) {
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(root, array[i]);
    }
    return root;
}
// 注意这里是创建节点；错+1
node* newNode(int v) {
    node* root = new node;
    root->data = v;
    root->lchild = root->rchild = NULL;
    return root;
}
//注意这里是插入节点；而且是void型；错+1
void insert(node* &root, int x) {
    if (root == NULL) {
        root = newNode(x);
        return;    
    }
    if (x == root->data) {
        printf("已存在！");
        return;
    } else if (x < root->data) {
        insert(root->lchild, x);
    } else {
        insert(root->rchild, x);
    }
}
// 在以root为根节点的二叉树中查找数据值为x的节点
node* search(node* root, int x) {
    if (root == NULL) {
        printf("查找失败！！！");
        return;
    }
    if (x == root->data) {
        printf("查找成功，该数据的值为：%d", root->data);
        return;
    } else if (x < root->data) {
        search(root->lchild, x);
    } else {
        search(root->rchild, x);
    }
}