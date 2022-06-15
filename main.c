#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int maxsize;
    int len;
} List;

void Init_List(List *L, int size);
void IncreaseSize(List *L, int len);
void SetList(List *L, int i, int data);
void PrintfList(List *L);
int main(void)
{
    List L;
    Init_List(&L, 10);
    PrintfList(&L);
    SetList(&L, 5, 10);
    PrintfList(&L);
    IncreaseSize(&L, 5);
    PrintfList(&L);
    SetList(&L, 11, 4);
    PrintfList(&L);
    SetList(&L, 1, 9);
    PrintfList(&L);
    SetList(&L, 20, 5);
    PrintfList(&L);
    return 0;
}

void Init_List(List *L, int size)
{
    L->data = (int *)malloc(sizeof(int) * size);
    for(int i = 0; i < L->maxsize; i++)
    {
        L->data[i] = 0;
    }
    L->len = 0;
    L->maxsize = size;
}

void IncreaseSize(List *L, int len)
{
    int *p = L->data;
    L->data = (int *)malloc(sizeof(int) * (L->maxsize + len));
    for(int i = 0; i < L->len; i++)
    {
        L->data[i] = p[i];
    }
    L->maxsize = L->maxsize + len;
    for(int i = L->len; i < L->maxsize; i++)
    {
        L->data[i] = 0;
    }
    free(p);
}

void SetList(List *L, int i, int data)
{
    if(i <= L->maxsize)
    {
        L->data[i-1] = data;
        L->len < i? L->len = i:0;
    }
    else{
        printf("插入位置错误！\n");
    }
}

void PrintfList(List *L)
{
    for(int i = 0; i < L->len; i++)
    {
        printf("第%d位元素为%d\n",i+1, L->data[i]);
    }
    printf("\n");
}