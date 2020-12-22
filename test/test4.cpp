#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
	{
		int data;
		struct Node *pleft;
		struct Node *pright;
	}Node;

    struct Node *createnode(int value)
	{
		struct Node *pnode = (struct Node *)malloc(sizeof(struct Node));
		pnode->data = value;
		pnode->pleft = pnode->pright = NULL;
		return pnode;
	}	

    struct Node *addnode(int value, struct Node *pnode)
	{
		if(pnode == NULL)
			return createnode(value);

		if(value == pnode->data)
		{
			return pnode;
		}

		if(value < pnode->data)
		{
			if(pnode->pleft == NULL)
			{
				pnode->pleft = createnode(value);
				return pnode->pleft;
			}
			else
			{
				return addnode(value, pnode->pleft);
			}
		}
		else
		{
			if(pnode->pright == NULL)
			{
				pnode->pright = createnode(value);
				return pnode->pright;
			}
			else
			{
				return addnode(value, pnode->pright);
			}

		}
	}

    void listnodes(struct Node *pnode)
{
	if(pnode != NULL)
	{
		listnodes(pnode->pleft);
		printf("%d\n", pnode->data);
		listnodes(pnode->pright);
	}
}
//求二叉树的深度，递归：
int Treeheight(struct Node *pnode)
{
	int LD, RD;
	if(pnode == NULL)
	{
		return 0;
	}
	else
	{
		LD = Treeheight(pnode->pleft);
		RD = Treeheight(pnode->pright);
		return (LD >= RD? LD:RD) + 1;
	}
}

int main(void)
{
	int newvalue = 0;
	struct Node *proot = NULL;
	char answer = 'n';
	do
	{
		printf("Enter the node value:\n");
		scanf("%d", &newvalue);
		if(proot == NULL)
		{
			proot = createnode(newvalue);
		}
		else
		{
			addnode(newvalue, proot);
		}
		printf("\nDo you want to enter another (y or n)? ");
		scanf(" %c", &answer);
	} while(tolower(answer) == 'y');

	listnodes(proot);
	printf("\nThe height of tree is %d!", Treeheight(proot));

	return 0;
}