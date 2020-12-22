
#include<cstdio>
#define MAX 10

struct node{
    char data;
    node* lchild;
    node* rchild;
};

//二叉树的建立
node* create(int preL, int preR, int inL, int inR){
    if(preL > preR){
        return NULL; //先序序列长度小于等于0时直接返回
    }
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k = inL; k <= inL;k++){
        if(in[k] = pre[preL])   break;
    }
    int numLeft = k - inL;

    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);

    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);

    return root;
}

//求二叉树叶节点的个数
int LeafCount(node* root){
 	if(root == NULL) 	//如果是空树返回0
		return 0;
	if (root->lchild == NULL && root->rchild == NULL)
		return 1;      //如果是叶子结点返回1
	else return LeafCount(root->lchild) + LeafCount(root->rchild);
}

//求二叉树的深度，递归：
int Treeheight(node *root)
{
	int LD, RD;
	if(root == NULL){
		return 0;
	}
	else{
		LD = Treeheight(root->lchild);
		RD = Treeheight(root->rchild);
		return (LD >= RD? LD:RD) + 1;
	}
}
int pre[MAX], in[MAX], n;

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&pre[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d",&in[i]);
    }
    node* root = create(0, n - 1, 0, n - 1);
    printf("树的叶节点个数为%d\n",LeafCount(root));
    printf("树的高度为%d\n",Treeheight(root));
    return 0;
}