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

void menu1()
{
    printf("*************************************\n");
    printf("请选择你的操作：>\n");
    printf("1.尾插   2.尾删\n");
    printf("3.头插   4.头删\n");
    printf("5.打印   -1.退出\n");
    printf("6.进入操作数据的界面\n");
    printf("*************************************\n");
}

void menu2()
{
    printf("*************************************\n");
    printf("请选择你的操作：>\n");
    printf("7.查询数据位置\n");
    printf("8.插入     9.删除\n");
    printf("-1.退回上一个菜单\n");
    printf("*************************************\n");
}

void MenuTest()
{
    int input1 = 0;
    int input2 = 0;
    SL s4;
    SeqListInit(&s4);
    int x = 0;
    int pos3 = 0;
    int pos4 = 0;
    int num = 0;

    while(1)
    {
        menu1();
        scanf("%d", &input1);

        if (input1 == -1)
        {
            printf("退出程序\n");
            break;
        }

        switch(input1)
        {
            case 1:
                printf("请输入你要插入的数据，以-1结束\n");
                scanf("%d", &x);
                while(x != -1)
                {
                    SeqListPushBack(&s4, x);
                    scanf("%d", &x);
                }
                break;
            case 2:
                SeqListPopBack(&s4);
                break;
            case 3:
                printf("请输入你要插入的数据，以-1结束\n");
                scanf("%d", &x);
                while(x != -1)
                {
                    SeqListPushFront(&s4, x);
                    scanf("%d", &x);
                }
                break;
            case 4:  
                SeqListPopFront(&s4);
                break;
            case 5:
                SeqListPrint(&s4);
                break;
            case 6:
                while(1)
                {
                    menu2();
                    scanf("%d", &input2);

                    if (input2 == -1)
                    {
                        printf("退回主菜单\n");
                        break;
                    }

                    switch(input2)
                    {
                        case 7:
                        {
                            printf("请输入需查询的数据\n");
                            scanf("%d", &num);
                            int pos5 = SeqListFind(&s4, num);
                            printf("pos = %d\n", pos5);
                            break;
                        }
                        case 8:
                            printf("请输入需插入数据的位置\n");
                            scanf("%d", &pos3);
                            printf("请输入需插入的数据\n");
                            scanf("%d", &num);
                            SeqListInsert(&s4, pos3, num);
                            break;
                        case 9:
                            printf("请输入需删除数据的位置\n");
                            scanf("%d", &pos4);
                            SeqListErase(&s4, pos4);
                            break;
                        default:
                            printf("无此选项，请重新输入\n");
                    }
                }
                break;
            default:
                printf("无此选项，请重新输入\n");

        }
    }

    SeqListDestroy(&s4);
}

int main() {
    //TestSeqList1();    //验证初始化顺序表、尾插函数、尾删函数、内存销毁函数
    //TestSeqList2();   //验证头插函数、头删函数
    //TestSeqList3();     //验证查找函数、任意下标插入函数、任意下标删除函数
    MenuTest();
    
    return 0;
}