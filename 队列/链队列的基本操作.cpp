#include <stdio.h>
#include <malloc.h>

typedef enum{
    OK=0;
    ERROR=1;
    TRUE=2;
    FALSE=3;

}status;
typedef int elemtype;

typedef struct node{
    node *next;
    elemtype data;
}lqnode;

typedef struct{
    lqnode *front;
    lqnode *rear;
}linkqueue;
//����һ��������
status initqueue(linkqueue *phead){
    phead->front=phead->rear=(lqnode*)malloc(sizeof(lqnode));
    if (!phead->front)
    {
        printf("pQHead->front malloc error!\n");
        return ERROR;
    }
    phead->front->next = NULL;
    
    return OK;
	
} 
//����������
void destoryqueue(linkqueue *phead){
    free(phead->front);
    free(phead->rear);
    phead->front=phead->rear=NULL;
} 
//���������
void clearQueue(linkqueue *phead){
    phead->front=phead->rear;   
} 
//�ж��Ƿ�Ϊ��
status isEmpty(linkqueue *phead){
    if (phead->front=phead->rear)
    {
        return TRUE;
    }
    return FALSE;
}
int getQueLen(linkqueue *phead){
    lqnode *temp=phead->front;
    int length=0;
    while(temp!=phead->rear){
        ++length;
        temp=temp->next;
    }
    return length;
}
//������
status enqueue(linkqueue *phead,elemtype element){
    lqnode *temp=(lqnode*)malloc(sizeof(lqnode));
    if(!temp)
    {
        printf("temp malloc error!\n");
        return ERROR;
    }
    temp->data=element;
    temp->next= NULL;
    
    phead->rear->next=temp;
	
    phead->rear=temp;
	
}
//������
status dequeue(linkqueue *phead,elemtype &element){
    lqnode *temp=phead->front->next;
    if (isEmpty(phead)==TRUE)
    {
        printf("queue is NULL!\n");
        return ERROR;
    }
    if (phead->front->next=phead->rear)
    {
        phead->rear=phead->front;//��ֹβָ��ָ��գ�������ǰ����ָ��ͷָ��
    }
    element=temp->data;
    phead->front->next=temp->next;
    free(temp);
    temp=NULL;
	
    return OK;
}