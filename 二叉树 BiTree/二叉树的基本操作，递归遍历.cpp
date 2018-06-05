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

//����һ�ö�����
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
//����ݹ����
void PreOrderTraverse(BiTree *T){
	if (T)
	{
		visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
/*
* ���������������ָ�ȷ������ң����ӣ�Ȼ����ʸ����������ң��󣩺��ӵı�����ʽ
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
* ���������������ָ�ȷ��ʺ��ӣ�Ȼ����ʸ��ı�����ʽ
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




						
					
