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

int main() {
    //TestSeqList1();
    TestSeqList2();
    
    return 0;
}