#include "SeqList.h"   // 必须包含头文件
#include <stdlib.h>    // 用于 malloc/realloc/free
#include <assert.h>    //用于断言

// 初始化
void SeqListInit(SL* ps) {
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

void SeqListPrint(SL* ps)
{
    for(int i = 0; i < ps->size; i++)
    {
        printf("%d", ps->a[i]);
    }
    printf("\n");
}

// 尾插
void SeqListPushBack(SL* ps, SLDataType x)
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
    ps->a[ps->size] = x;
    ps->size++;
}

//释放空间，销毁
void SeqListDestory(SL* ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

void SeqListPopBack(SL* ps)
{
    assert(ps->size > 0);
    ps->size--;
}

// // 尾插
// void SeqListPushBack(SL* ps, SLDataType x) {
//     // 简单的实现：检查容量，扩容
//     if (ps->size == ps->capacity) {
//         int newCapacity = (ps->capacity == 0) ? 4 : ps->capacity * 2;
//         SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
//         if (tmp == NULL) {
//             perror("realloc failed");
//             return;
//         }
//         ps->a = tmp;
//         ps->capacity = newCapacity;
//     }
//     ps->a[ps->size] = x;
//     ps->size++;
// }

// // 尾删
// void SeqListPopBack(SL* ps) {
//     if (ps->size > 0) {
//         ps->size--;
//     }
// }

// // 头插
// void SeqListPushFront(SL* ps, SLDataType x) {
//     // 先检查容量（同尾插）
//     if (ps->size == ps->capacity) {
//         int newCapacity = (ps->capacity == 0) ? 4 : ps->capacity * 2;
//         SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
//         if (tmp == NULL) {
//             perror("realloc failed");
//             return;
//         }
//         ps->a = tmp;
//         ps->capacity = newCapacity;
//     }
//     // 将所有元素后移一位
//     for (int i = ps->size; i > 0; i--) {
//         ps->a[i] = ps->a[i - 1];
//     }
//     ps->a[0] = x;
//     ps->size++;
// }

// // 头删
// void SeqListPopFront(SL* ps) {
//     if (ps->size == 0) return;
//     // 将所有元素前移一位
//     for (int i = 0; i < ps->size - 1; i++) {
//         ps->a[i] = ps->a[i + 1];
//     }
//     ps->size--;
// }