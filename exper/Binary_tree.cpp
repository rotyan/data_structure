//水+1！
#include<cstdio>
#include<queue>
using namespace std;

struct node {
    char data;
    node* lchild;
    node* rchild;
};

//先序遍历
void preorder(node* root) {
    if(root == NULL) return;    //递归边界，到达空树
    //访问根节点root并将数据域输出
    printf("%d\n",root->data);
    //访问左指树
    preorder(root->lchild);
    //访问右指数
    preorder(root->rchild);
}
//中序遍历
void inorder(node* root) {
    if(root == NULL) return;    //递归边界，到达空树
    //访问左指树
    inorder(root->lchild);
    //访问根节点root并将数据域输出
    printf("%d\n",root->data);
    //访问右指数
    inorder(root->rchild);
}
//后序遍历
void postorder(node* root) {
    if(root == NULL) return;    //递归边界，到达空树
    //访问左指树
    postorder(root->lchild);
    //访问右指数
    postorder(root->rchild);
    //访问根节点root并将数据域输出
    printf("%d\n",root->data);
}

//层序遍历
void LayerOrder(node* root) {
    queue<node*> q; //队列里存地址
    q.push(root);   //将根节点入队列
    while(!q.empty()) {
        node* now = q.front();  //取处队首元素
        q.pop();
        printf("%d\n",now->data);
        if(now->lchild != NULL) q.push(now->lchild);    //左子树非空
        if(now->rchild != NULL) q.push(now->rchild);    //右子树非空
    }
}

//二叉树的新建节点
node* newNode(int v) {   //生成一个新节点，v为节点权值
    node* Node = new node;
    Node->data = v; //节点权值为v
    Node->lchild = Node->rchild = NULL;
    return Node;
}

//二叉树节点的插入
void insert(node* &root, int x) {
    
}

//二叉树的建立
node* Create(char data[], int n) {
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}

int main() {
    //好几天没动笔了，烂了么？
    getchar();
    return 0;
}