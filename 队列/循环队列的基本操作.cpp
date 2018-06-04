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
 //初始化创建一个循环队列
 Status initqueue(sqQueue* q){
	q->base=(QElemType*)malloc(sizeof(QElemType));
	if(!q->base){
		exit(OVERFLOW);
	}
	q->front=q->rear=0;
	return OK;
 }
/*
队列满条件：（rear+1)%MaxSize=front
队列空条件：rear=front
*/
 //循环队列进元素
 Status enqueue(sqQueue *q,QElemType elem){
	 //队列为空时 1%100==1,队列满时(99+1)%100==0,最多容纳99个元素
	if ((q->rear+1)%MAXQSIZE==q->front)
	{
		return ERROR;
	}
	q->base[q->rear]=elem;
	q->rear=(q->rear+1)%MAXQSIZE;//rear始终在0-100中循环
	return OK;
 }
 //循环队列出元素

 Status dequeue(sqQueue *q,QElemType &elem){
	if (q->rear==q->front)
	{
		return ERROR;
	}
	elem=q->base[q->front];
	q->front=(q->front+1)%MAXQSIZE;
	return OK;
 }

//遍历循环队列
 Status printqueue(sqQueue q){
	printf("the queue is:");
	for (int i=q.front;i<q.rear;++i)
	{
		printf("%d ",q.base[i]);
	}
	return OK;
 }