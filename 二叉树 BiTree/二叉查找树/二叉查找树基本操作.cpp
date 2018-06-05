#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;

typedef struct treeNode{
	ElemType element;
	struct treeNode *lchild;
	struct treeNode *rchild;

}BsTree;

//�ݹ���ҹؼ���Ϊdata��Ԫ�أ�ʱ�临�Ӷ�ΪO(h)��h�����ĸ߶�
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
//�ǵݹ���ҹؼ���Ϊdata��Ԫ��
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
	���data�����ڣ�����룬���ݶ�������������ʣ�
	������ڸ��ڵ�Ԫ�أ����������������С�ڸ��ڵ�Ԫ�������������
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