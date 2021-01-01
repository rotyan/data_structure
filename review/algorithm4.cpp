// 三种二叉树的遍历和深度计算
#include<cstdio>

struct node{
    int data;
    node* lchild;
    node* rchild;
};

void preOrder(node* root) {
    if (root == NULL)   return;
    printf("%d  ",root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void inOrder(node* root) {
    if (root == NULL)   return;
    inOrder(root->lchild);
    printf("%d  ",root->data);
    inOrder(root->rchild);
}

void postOrder(node* root) {
    if (root == NULL)   return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d  ",root->data);
}

int Depth(node* root) {
    if (root == NULL) return 0;
    int m = Depth(root->lchild);
    int n = Depth(root->rchild);
    if (m > n) return m + 1;
    else return n + 1;
}

int main() {
    int n = 2;
    getchar();
    return n + 1;   //返回值是3，不用加括号
}