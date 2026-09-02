#include "SeqList.h"   // 必须包含头文件
#include <stdlib.h>    // 用于 malloc/realloc/free
#include <stdio.h>   

// 初始化
void SeqListInit(SL* ps) {
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

//容量检查
void SeqListCheckCapacity(SL* ps)
{
    //检查容量，扩容
    if(ps->size == ps->capacity)
    {
        int newcapacity = (ps->capacity == 0) ? 4 : ps->capacity * 2;
        SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
        if(tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newcapacity;
    }
}

//打印
void SeqListPrint(SL* ps)
{
    for(int i = 0; i < ps->size; i++)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

// 尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
    SeqListCheckCapacity(ps);
    ps->a[ps->size] = x;
    ps->size++;
}

//释放空间，销毁
void SeqListDestroy(SL* ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

//尾删
void SeqListPopBack(SL* ps)
{
    if(ps->size == 0)
    {
        return;
    }
    ps->size--;
}

//头插
void SeqListPushFront(SL* ps, SLDataType x)
{
    SeqListCheckCapacity(ps);
    //挪动数据
    int end = ps->size-1;
    while(end >= 0)
    {
        ps->a[end+1] = ps->a[end];
        end--;
    }
    ps->a[0] = x;
    ps->size++;//更新表长
}

//头删
void SeqListPopFront(SL* ps)
{
    //检查是否为空表
    if(ps->size == 0)
    {
        return;
    }
    for(int begin = 0; begin < ps->size-1; begin++)
    {
        ps->a[begin] = ps->a[begin+1];
    }
    ps->size--;  //更新表长
}

// 查找
int SeqListFind(SL* ps, SLDataType x)
{
    if(ps == NULL)
    {
        return -2;    // 返回一个非法的下标，表示“传入空指针”
    }
    for (int pos = 0; pos < ps->size; pos++)
    {
        if(ps->a[pos] == x)
        {
            return pos; //找到了，返回下标
        }
    }
    return -1;   //未找到
}

//在下标pos位置插入数据
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
    //检查是否为空指针
    if (ps == NULL) 
    {
        return; 
    }
    //检查下标是否合法
    if(pos > ps->size || pos < 0)
    {
        printf("pos invalid\n");
        return;
    }
    SeqListCheckCapacity(ps);   //检查容量
    //挪动数据
    for(int i = ps->size-1; i > pos-1; i--)
    {
        ps->a[i+1] = ps->a[i];
    }
    ps->a[pos] = x; //插入数据
    ps->size++; //更新表长
}

//在下标pos位置删除数据
void SeqListErase(SL* ps, int pos)
{
    //检查是否为空指针
    if (ps == NULL) 
    {
        return; 
    }
    //检查下标是否合法
    if(pos >= ps->size || pos < 0) //注意最后一个数据的下标是ps->size - 1
    {
        printf("pos invalid\n");
        return;
    }
    //挪动数据
    for(int i = pos; i < ps->size-1; i++)
    {
        ps->a[i] = ps->a[i+1];
    }
    ps->size--; //更新表长
}