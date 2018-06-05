#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Status;
typedef int TElemType;


typedef struct bitNode{
	TElemType data;
	struct bitNode *lchild,*rchild;
}bitNode,BiTree;

//创建一棵二叉树
Status creatBiTree(BiTree *T){
	TElemType e;
	scanf("%d",&e);
	if (e==0)
	{
		T=NULL;
	}
	else{
		T=(BiTree*)malloc(sizeof(BiTree));
		if (!T)
		{
			exit(OVERFLOW);
		}
		T->data=e;
		creatBiTree(T->lchild);
		creatBiTree(T->rchild);
	}
	return OK;
}
void visit(TElemType e)
{
    printf("%d ", e);
}
//先序递归遍历
void PreOrderTraverse(BiTree *T){
	if (T)
	{
		visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
/*
* 中序遍历二叉树：指先访问左（右）孩子，然后访问根，最后访问右（左）孩子的遍历方式
*/
void InOrderTraverse(BiTree *T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        visit(T->data);
        InOrderTraverse(T->rchild);
    }
}

/*
* 后序遍历二叉树：指先访问孩子，然后访问根的遍历方式
*/
void PostOrderTraverse(BiTree *T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        visit(T->data);
    }
}




						
					
