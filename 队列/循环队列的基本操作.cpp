 #include <stdio.h>
 #include <stdlib.h>
 #define OK 1
 #define ERROR 0
 #define OVERFLOW -2
 #define MAXQSIZE 100
 typedef int Status;
 typedef int QElemType;
 typedef struct node{
	 QElemType *base;
	 int front;
	 int rear;
 }sqQueue;
 //��ʼ������һ��ѭ������
 Status initqueue(sqQueue* q){
	q->base=(QElemType*)malloc(sizeof(QElemType));
	if(!q->base){
		exit(OVERFLOW);
	}
	q->front=q->rear=0;
	return OK;
 }
/*
��������������rear+1)%MaxSize=front
���п�������rear=front
*/
 //ѭ�����н�Ԫ��
 Status enqueue(sqQueue *q,QElemType elem){
	 //����Ϊ��ʱ 1%100==1,������ʱ(99+1)%100==0,�������99��Ԫ��
	if ((q->rear+1)%MAXQSIZE==q->front)
	{
		return ERROR;
	}
	q->base[q->rear]=elem;
	q->rear=(q->rear+1)%MAXQSIZE;//rearʼ����0-100��ѭ��
	return OK;
 }
 //ѭ�����г�Ԫ��

 Status dequeue(sqQueue *q,QElemType &elem){
	if (q->rear==q->front)
	{
		return ERROR;
	}
	elem=q->base[q->front];
	q->front=(q->front+1)%MAXQSIZE;
	return OK;
 }

//����ѭ������
 Status printqueue(sqQueue q){
	printf("the queue is:");
	for (int i=q.front;i<q.rear;++i)
	{
		printf("%d ",q.base[i]);
	}
	return OK;
 }