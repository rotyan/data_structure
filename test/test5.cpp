//还有问题，两个输出函数不对
#include<cstdio>
#define MAX 10

struct node{
    char data;  //数据域
    node* lchild;   //左指针
    node* rchild;   //右指针
};
char pre[MAX], in[MAX];   //储存先序、中序的数据
int n;  //n为节点个数
//二叉树的建立
node* create(int preL, int preR, int inL, int inR){
    if(preL > preR){
        return NULL; //先序序列长度小于等于0时直接返回
    }
    node* root = new node;  //新建一个节点，用来存放当前二叉树的根节点
    root->data = pre[preL]; ////新节点数据域的值为根节点的值
    int k;
    for(k = inL; k <= inL;k++){ 
        if(in[k] = pre[preL])   break;  //在中序中找到in[k]==ore[L]的节点，之后用于得左子树节点的个数
    }
    int numLeft = k - inL;  //左子树节点的个数

    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    //返回左子树的根节点地址，赋值给root的左指针。同时注意左子树的先序区间和中序区间。
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    //返回右子树的根节点地址，赋值给root的右指针。同时注意右子树的先序区间和中序区间。
    return root;    //返回根节点地址
}

//求二叉树叶节点的个数
int LeafCount(node* root){
 	if(root == NULL) 	//如果是空树返回0
		return 0;
	if (root->lchild == NULL && root->rchild == NULL)
		return 1;      //如果是叶子结点返回1
	else return LeafCount(root->lchild) + LeafCount(root->rchild);  //递归
}

//求二叉树的深度，递归：
int Treeheight(node *root){
	int LD, RD;
	if(root == NULL){
		return 0;
	}
	else{
		LD = Treeheight(root->lchild);
		RD = Treeheight(root->rchild);
		return (LD >= RD? LD:RD) + 1;   //比较左右子树高度，取大的一方并加1（root）
	}
}
//主函数
int main(){
    scanf("%d",&n); //设置节点数目
    for(int i = 0; i < n; i++){
        scanf("%c",&pre[i]);    //输入数据到先序遍历序列对应数组中
    }
    for(int i = 0; i < n; i++){
        scanf("%c",&in[i]);     //输入数据到中序遍历序列对应数组中
    }
    node* root = create(0, n - 1, 0, n - 1);    //取根节点
    printf("树的叶节点个数为%d\n",LeafCount(root)); //输出树的叶节点个数
    printf("树的高度为%d\n",Treeheight(root));  //输出树的高度
    return 0;
}