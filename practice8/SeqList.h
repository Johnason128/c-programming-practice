#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int SLDataType;

//动态数据表
typedef struct SeqList
{
    SLDataType* a;
    int size;    //表示数组中存了多少个数据
    int capacity;//表示数组能存数据的空间容量有多大
}SL;

//接口函数
void SeqListCheckCapacity(SL* ps);
void SeqListPrint(SL* ps);
void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListDestroy(SL* ps);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
void SeqListFind(SL* ps, SLDataType x);
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);
