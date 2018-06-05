#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;

typedef struct treeNode{
	ElemType element;
	struct treeNode *lchild;
	struct treeNode *rchild;

}BsTree;

//递归查找关键字为data的元素，时间复杂度为O(h)，h是树的高度
BsTree *find(ElemType data,BsTree *t){
	if (t==NULL)
	{
		return NULL;
	}
	if (data < t->element)
	{
		return find(data,t->lchild);
	}
	else if (data > t->element)
	{
		return find(data,t->rchild);
	}
	else
	{
		return t;
	}
}
//非递归查找关键字为data的元素
BsTree *find2(ElemType data,BsTree *t){
	if (t==NULL)
	{
		return NULL;
	}
	BsTree *p=t;
	while(p!=NULL){
		if (data == p->element)
		{
			return p;
		}
		else if (data > p->element)
		{
			p=p->rchild;
		}
		else{
			p=p->lchild;
		}
	}	
}
/*
	如果data不存在，则插入，根据二叉查找树的性质，
	如果大于根节点元素，进入右子树，如果小于根节点元素则进入左子树
*/
BsTree *Insert(ElemType data,BsTree *t){
	if (t=NULL)
	{
		t=(BsTree*)malloc(sizeof(BsTree));
		t->element=data;
		t->lchild=NULL;
		t->rchild=NULL;
	}
	else if(data < t->element){
		t->lchild=Insert(data,t->lchild);
	}
	else if(data > t->element){
		t->rchild=Insert(data,t->rchild);
	}
	return t;
}