#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

/*
 * 存储结构
 */
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//初始化链表
void Initlist(LinkList &l){//尽量写&符号
	l=(LinkList)malloc(sizeof(LNode));
	if (!l)
	{
		exit(OVERFLOW);
	}
	l->next=NULL;
}
//判断是否为空
Status isEmpty(LinkList l){
	if (l->next)
	{
		return FALSE;
	}
	return TRUE;
}
//按照尾插法建立单链表,王道书p27
LinkList createList1(LinkList &l){
	LNode *s;int x;

	l=(LinkList)malloc(sizeof(LNode));

	scanf("%d",&x);
	while(x!=9999){
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		s->next=l->next;
		l->next=s;
		scanf("%d",&x);
	}
	return l;
}
//按照头插法建立单链表,王道书p28
LinkList createList2(LinkList &l){
	LNode *s,*r=l;
	int x;
	l=(LinkList)malloc(sizeof(LNode));
			
	scanf("%d",&x);
	
	while(x!=9999){
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		
		r->next=s;
		r=s;

		scanf("%d",&x);
	}

	return l;
}


