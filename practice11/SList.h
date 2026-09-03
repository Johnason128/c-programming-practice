#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int SLTDataType;

typedef struct SListNode
{
    SLTDataType data;
    struct SListNode* next;
}SLTNode;

//接口函数
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead, SLTDataType x);

