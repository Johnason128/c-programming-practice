#include "SeqList.h"

void TestSeqList1() {
    SL s1;
    SeqListInit(&s1);
    SeqListPushBack(&s1, 1);
    SeqListPushBack(&s1, 2);
    SeqListPushBack(&s1, 3);
    SeqListPushBack(&s1, 4);
    SeqListPushBack(&s1, 5);
    
    SeqListPrint(&s1);

    SeqListPopBack(&s1);
    SeqListPopBack(&s1);

    SeqListPrint(&s1);

    SeqListDestroy(&s1);
}

void TestSeqList2() {
    SL s2;
    SeqListInit(&s2);
    SeqListPushBack(&s2, 1);
    SeqListPushBack(&s2, 2);
    SeqListPushBack(&s2, 3);
    SeqListPushBack(&s2, 4);
    SeqListPushBack(&s2, 5);
    
    SeqListPrint(&s2);

    SeqListPushFront(&s2, 10);
    SeqListPushFront(&s2, 20);
    SeqListPushFront(&s2, 30);
    SeqListPushFront(&s2, 40);
    SeqListPushFront(&s2, 50);
    SeqListPushFront(&s2, 60);

    SeqListPrint(&s2);
    
    SeqListPopFront(&s2);
    SeqListPopFront(&s2);

    SeqListPrint(&s2);

    SeqListDestroy(&s2);
}

void TestSeqList3() {
    SL s3;
    SeqListInit(&s3);
    SeqListPushBack(&s3, 1);
    SeqListPushBack(&s3, 2);
    SeqListPushBack(&s3, 3);
    SeqListPushBack(&s3, 4);
    SeqListPushBack(&s3, 5);
    
    SeqListPrint(&s3);

    int pos1 = SeqListFind(&s3, 3);
    printf("pos = %d\n", pos1);
    int pos2 = SeqListFind(&s3, 6);
    printf("pos = %d\n", pos2);

    SeqListInsert(&s3, 2, 20);
    SeqListInsert(&s3, 4, 40);
    SeqListInsert(&s3, 8, 80);

    SeqListPrint(&s3);
    
    SeqListErase(&s3, 4);
    SeqListErase(&s3, 0);
    SeqListErase(&s3, 9);

    SeqListPrint(&s3);

    SeqListDestroy(&s3);
}

int main() {
    //TestSeqList1();    //验证初始化顺序表、尾插函数、尾删函数、内存销毁函数
    //TestSeqList2();   //验证头插函数、头删函数
    TestSeqList3();     //验证查找函数、任意下标插入函数、任意下标删除函数
    
    return 0;
}