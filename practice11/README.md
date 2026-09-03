# 练习 11：单链表基础操作（尾插与打印） | Practice 11: Singly Linked List Basic Operations (PushBack and Print)

## 功能 | Function
- 掌握单链表的基本结构和节点定义。 | Master the basic structure and node definition of singly linked list.
- 实现单链表的尾插操作（`SListPushBack`）。 | Implement tail insert operation (`SListPushBack`) for singly linked list.
- 实现单链表的遍历打印功能（`SListPrint`）。 | Implement traversal and print function (`SListPrint`) for singly linked list.

## 代码结构 | Code Structure
- `SList.h`：头文件，包含链表节点结构体定义及函数接口声明。 | Header file, contains linked list node struct definition and function interface declarations.
- `SList.c`：源文件，包含各个功能函数的具体实现。 | Source file, contains specific implementations of each function.
- `test.c`：测试文件，包含 `TestSList1` 测试函数及 `main` 函数。 | Test file, contains `TestSList1` test function and `main` function.

## 核心逻辑说明 | Core Logic Description

### 1. 单链表节点结构 (Singly Linked List Node Structure)
```c
typedef int SLTDataType;

typedef struct SListNode
{
    SLTDataType data;           // 数据域
    struct SListNode* next;     // 指针域（指向下一个节点）
} SLTNode;