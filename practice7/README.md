# 练习 7：动态顺序表基本操作 | Practice 7: Dynamic Sequence List Basic Operations

## 功能 | Function
- 实现动态顺序表的初始化。 | Implement dynamic sequence list initialization.
- 实现顺序表的尾插（PushBack）和尾删（PopBack）功能。 | Implement tail insert (PushBack) and tail delete (PopBack) functions.
- 实现顺序表的遍历打印与内存销毁。 | Implement sequence list traversal printing and memory destruction.

## 代码结构 | Code Structure
- `SeqList.h`：头文件，包含顺序表结构体定义及函数接口声明。 | Header file, contains sequence list struct definition and function interface declarations.
- `SeqList.c`：源文件，包含各个功能函数的具体实现（如动态扩容等）。 | Source file, contains specific implementations of each function (e.g., dynamic capacity expansion).
- `test.c`：测试文件，包含 `main` 函数及功能测试用例。 | Test file, contains `main` function and functional test cases.

## 测试说明 | Test Description
在 `TestSeqList1` 测试函数中，执行了以下流程：
1. **初始化**：调用 `SeqListInit` 初始化顺序表 `s1`。
   - **Initialize**: Call `SeqListInit` to initialize sequence list `s1`.
2. **尾插**：连续调用 5 次 `SeqListPushBack`，依次插入数据 1, 2, 3, 4, 5。
   - **Tail Insert**: Call `SeqListPushBack` 5 times consecutively, inserting data 1, 2, 3, 4, 5 in order.
3. **打印**：调用 `SeqListPrint` 打印当前顺序表（预期输出：1 2 3 4 5）。
   - **Print**: Call `SeqListPrint` to print the current list (Expected output: 1 2 3 4 5).
4. **尾删**：连续调用 2 次 `SeqListPopBack`，删除末尾的两个元素。
   - **Tail Delete**: Call `SeqListPopBack` 2 times consecutively to delete the last two elements.
5. **再次打印**：调用 `SeqListPrint` 验证删除结果（预期输出：1 2 3）。
   - **Print Again**: Call `SeqListPrint` to verify deletion result (Expected output: 1 2 3).
6. **销毁**：调用 `SeqListDestroy` 释放动态分配的内存，防止内存泄漏。
   - **Destroy**: Call `SeqListDestroy` to free dynamically allocated memory and prevent memory leaks.

## 注意事项 | Notes
- 动态顺序表在容量不足时会自动进行扩容（通常在 `SeqList.c` 的 `PushBack` 中实现）。
- 动态顺序表在不再使用时，必须调用销毁函数释放 `realloc` 申请的堆内存。

- The dynamic sequence list automatically expands its capacity when full (usually implemented in `PushBack` within `SeqList.c`).
- The sequence list must be destroyed to free the heap memory allocated by `realloc` when no longer in use.