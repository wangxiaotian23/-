#include<stdio.h>  
#include<stdlib.h>  
  
  
#define LIST_INIT_SIZE 100  
#define LIST_INCREASMENT 10  
#define FALSE 0  
#define TRUE 1  
#define ERROR 0  
#define OK 1  
  
typedef int ElemType;   //���������Ԫ�ص�����,֮��������ΪElemType�ǿ��ǵ�����չ�е�ԭ��,����������Ԫ�ص������޸ĳ������Ļ�,ֻ��Ҫ�������޸�һ�ξݺ���,�ȽϷ���  
typedef int Status;  
/* 
**�������Ա�����ݽṹ 
*/  
typedef struct{  
    ElemType *base;     //baseΪ���Ա�ָ�����Ա���ʼ��ַ��ָ��  
    int length;         //lengthΪ��ǰ���Ա�ĳ���  
    int listSize;       //listSizeΪ���Ա���ܳ���  
} SqList;  
  
/*�������Ա� 
*/  
void initList(SqList *L){  
    L->listSize = LIST_INIT_SIZE;  //��ʼ�����Ա���ܳ���Ϊ�������ȶ���õ�LIST_INIT_SIZE,Ҳ����100  
    L->base = (ElemType *)malloc(L->listSize * sizeof(ElemType));  //Ϊ���Ա������ڴ�ռ�,��СΪ���Ա���ܳ��� ���� ÿһ��Ԫ����ռ�ռ�Ĵ�С  
    L->length = 0;   //�������Ա��ʱ��û������Ԫ��,����Ĭ��Ϊ0   
}  
  
/* 
**�ж�˳����Ƿ�Ϊ�� 
*/  
bool listEmpty(SqList *L){  
    return L->length == 0;  
}  
  
/* 
**�õ����Ա�ǰ�ĳ��� 
*/  
int listLength(SqList *L){  
    if(L->length >= 0 && L->length <= L->listSize){  
        return L->length;  
    } else{  
        return -1;  
    }  
}  
  
/* 
**���Ա�Ĳ������ 
*/  
Status listInsert(SqList *L, int i, ElemType e){  
    //�������ﴫ���i���û����е�λ��,��˼���Ǵ�1��ʼ,�����Ǵӳ���Ա��Ϥ��0��ʼ  
    int k;  
    if(L->length == L->listSize){  
        printf("���Ա�����,���ܲ���");  
        return ERROR;  
    }  
    if(i<1 || i>L->length + 1){  
        printf("�����λ�ò���ȷ");  
        return ERROR;  
    }  
    if(i <= L->length){  //�������λ�ò��ڱ�β  
        for(k=L->length - 1; k>i - 1; k--){  
            L->base[k + 1] = L->base[k];  
        }  
    }  
    L->base[i - 1] = e;  
    L->length = L->length + 1;  
  
    return OK;  
}  
  
/* 
**ɾ��һ�����е�Ԫ�� 
*/  
Status listDelete(SqList *L, int i, ElemType *e){  
    int k;  
    //�����e�������ݴ汻ɾ����Ԫ�ص�  
    if(L->length == 0){  //�����Ϊ�յĻ�,�򷵻ش���  
        return ERROR;  
    }  
    if(i<1 || i>L->length){    //���ɾ����λ�ò���ȷ  
        return ERROR;  
    }  
    *e = L->base[i - 1];   
    if(i < L->length){  
        for(k=i; k<L->length; k++){  
            L->base[k - 1] = L->base[k];  
        }  
    }  
    L->length = L->length - 1;  
      
    return OK;  
}  
/* 
**�õ�ָ��λ�õ�Ԫ�ص�ֵ 
*/  
ElemType getElem(SqList *L, int i){  
    if(i<1 || i>L->length){        //�������  
        return ERROR;  
    }  
    return L->base[i - 1];   //���һ����ֵ����ʽ�õ�  
}  
/* 
**�õ�ָ��λ��Ԫ�ص�ǰ�� 
*/  
ElemType priorElem(SqList *L, int i){  
    if(i<1 || i>L->length){        //�������  
        return ERROR;  
    }  
    if(i != 1){  
        return L->base[i-2];  
    } else {  
        printf("���Ա�ĵ�һ��Ԫ��û��ǰ��,��������!");  
        return ERROR;  
    }  
}  
/* 
**�õ�ָ��λ��Ԫ�صĺ�� 
*/  
ElemType nextElem(SqList *L, int i){  
    if(i<1 || i>L->length){        //�������  
        return ERROR;  
    }  
    if(i != L->length){  
        return L->base[i];  
    } else {  
        printf("���Ա�����һ��Ԫ��û�к��,��������!");  
        return ERROR;  
    }  
}  
  
/* 
**������Ա� 
*/  
bool clearList(SqList *L){  
    if(L->length>0 && L->length<L->listSize){  
        L->length = 0;  
        return OK;  
    } else{  
        return ERROR;  
    }  
}  
  
/* 
**�������Ա� 
*/  
Status destroyList(SqList *L){  
    clearList(L);   //��������Ա�  
    L->listSize = 0; //�����Ա���ܳ��ȹ���  
    free(L->base);       //�ͷ��ڴ�ռ�  
    if(L->base == NULL && L->length == 0 && L->listSize == 0){ //����ٽ���ȷ��  
        return TRUE;  
    } else{  
        return FALSE;  
    }  
}  
/* 
**������ǰ���Ա�,��ӡ������е�Ԫ�� 
*/  
void listTraverse(SqList *L)    
{    
    ElemType *p;    
    int i;    
    p = L->base;    
    
    for(i = 1; i <= L->length; i++)    
    {    
        printf("%d ", *(L->base + i - 1));    
    }    
    
    printf("\n\n");    
}    
/* 
**��λһ��ָ����ֵ�����Ա���ľ���λ�� 
*/  
int LocateElem(SqList *L, int e)    
{    
    ElemType *p;    
    int i = 1; // i�ĳ�ֵΪ��1��Ԫ�ص�λ��    
    p = L->base; // p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��    
    
    while(i <= L->length && *(p++) != e){    
        ++i;    
    }    
    
    if(i <= L->length)    
    {    
        return i;    
    }    
    else    
    {    
        return 0;    
    }    
    
}    
int main()  
{  
    ElemType e;  
    char ch = NULL;  
    SqList L;  
    initList(&L);   //����һ����  
    printf("�������Ա��\n���Ա�ĵ�ǰ����:%d", L.length);  
    printf("\n���Ա���ܳ���:%d", L.listSize);  
    if(listEmpty(&L)){  //�жϱ��Ƿ�Ϊ��  
        printf("\n��ʱ���Ա�Ϊ��");  
    } else {  
        printf("\n��ʱ���Ա�Ϊ��");  
    }  
    //����һ��Ԫ��  
    if(listInsert(&L, 1, 500)){  
        printf("\n��һ��Ԫ�ص�ֵ:%d", getElem(&L, 1));  
    }  
    printf("\n���Ա�ĵ�ǰ����:%d", L.length);  
  
    if(listInsert(&L, 2, 1000)){  
        printf("\n�ڶ���Ԫ�ص�ֵ:%d", getElem(&L, 2));  
    }  
    printf("\n���Ա�ĵ�ǰ����:%d", L.length);  
  
    if(listInsert(&L, 3, 2000)){  
        printf("\n������Ԫ�ص�ֵ:%d", getElem(&L, 3));  
    }  
    printf("\n���Ա�ĵ�ǰ����:%d\n", L.length);  
  
    listTraverse(&L);  
      
    printf("\n�ڶ���Ԫ�ص�ǰ����:%d", priorElem(&L, 2));  
    printf("\n�ڶ���Ԫ�صĺ����:%d", nextElem(&L, 2));  
  
    if(listDelete(&L, 1, &e)){  
        printf("\n��ɾ����Ԫ�ص�ֵ:%d", e);  
    }  
  
    printf("\n���Ա�ĵ�ǰ����:%d\n", L.length);  
      
    listTraverse(&L);  
      
    scanf("%c", &ch);  
    return 0;  
}  
