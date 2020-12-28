//【完成版】有待加深理解
#include<cstdio>
#include<queue>
using namespace std;

struct node {
    int data;  //数据域
    node* lchild;   //左指针
    node* rchild;   //右指针
};

node* newNode(int x);   //声明创建二叉树的函数
//search函数用于查找二叉树中数据域为x的节点
void search(node* root, int x) {
    if (root == NULL) { //空树，查找失败；递归边界；查找位置
        printf("查找失败！！！");
        return;
    }
    if (x == root->data) {  //节点数据值等于查找的数据，输出该数据
        printf("查找成功，该数据的值为：%d", root->data);
    } else if (x < root->data) {
        search(root->lchild, x);     //由二叉查找树的性质，输入数据值小于根节点时向左子树递归查找
    } else {
        search(root->rchild, x);    //由二叉查找树的性质，输入数据值大于根节点时向右子树递归查找
    }
}
//二叉排序树的插入【这里有重点，参数root要使用引用】
void insert(node* &root, int x) {
    if (root == NULL) { //空树，查找失败；递归边界；插入位置
       root = newNode(x);   //新建节点，其数据域值为x
        return;
    }
    if (x == root->data) {  //查找成功，节点已经存在
        printf("该值为%d的数据域节点已存在", x);    //输出已存在节点值
        return;
    } else if (x < root->data) {    //由二叉查找树的性质，输入数据值小于根节点时向左子树递归查找
        insert(root->lchild, x);
    } else {    //由二叉查找树的性质，输入数据值大于根节点时向右子树递归查找
        insert(root->rchild, x); 
    }
}
//二叉树的新建节点
node* newNode(int v) {   //生成一个新节点，v为节点权值（即数据域的值）
    node* Node = new node;  //新建节点Node
    Node->data = v; //节点权值为v
    Node->lchild = Node->rchild = NULL; //初始状态下左右节点指针均置空
    return Node;    //返回新节点地址
}
//二叉查找树的建立
node* Create(int data[], int n) {
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(root, data[i]);  //将数组data中元素插入二叉排序树中
    }
    return root;    //返回根节点
}
//运用中序遍历输出二叉树数据域
void inorder(node* root) {
    if(root == NULL) return;    //递归边界，到达空树
    //访问左指树
    inorder(root->lchild);
    //访问根节点root并将数据域输出
    printf("%d  ",root->data);
    //访问右指数
    inorder(root->rchild);
}
//简化对查找的输出格式
void doSearch(node* L,int x){
	printf("\n");
    printf("这棵二叉树查找X=%d的数据结果为：",x);
    search(L, x);
}
//主函数  
int main() {
    int data[]={12,3,15,6,1,8,19,20,33,24,17};  //测试集
    int n = sizeof(data)/4 + 1; //简化处理，取测试集data长度+1，使二叉树节点数目多1，目的在于方便后边的节点插入
    node* L = Create(data, n);
    printf("\n二叉树的中序遍历结果为：\n");
    inorder(L); //输出原始二叉树的中序遍历结果
    doSearch(L,53);	//输入查找的数据53，并输出原始二叉树的查找X=56的数据结果
    doSearch(L,1);	//输入查找的数据1，并输出原始二叉树的查找X=1的数据结果
    doSearch(L,13);	//输入查找的数据13，并输出原始二叉树的查找X=13的数据结果
    doSearch(L,18);	//输入查找的数据18，并输出原始二叉树的查找X=18的数据结果
    printf("\n在二叉排序中插入数据13这个结点后中序遍历结果为：\n");
    insert(L, 13);
    inorder(L);  //输出在二叉排序中插入数据13这个结点后中序遍历结果
    doSearch(L,13);	//输入查找的数据13，并输出原始二叉树的查找X=13的数据结果
    return 0;
}
