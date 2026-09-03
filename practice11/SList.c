#include "SList.h"   // 必须包含头文件
#include <stdlib.h>    // 用于 malloc/realloc/free
#include <stdio.h>   

void SListPrint(SLTNode* phead)
{
    SLTNode* cur = phead;
    while(cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
    //创建新节点
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    if(newnode == NULL)
    {
        perror("malloc fail"); //和printf一样但系统会提示错误原因
        return;
    }
    newnode->data = x;
    newnode->next = NULL;

    //如果链表为空，直接让头指针指向新节点
    if(*pphead == NULL)
    {
        *pphead = newnode;
        return;
    }

    //寻找尾节点
    SLTNode* tail = *pphead;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = newnode;
}
