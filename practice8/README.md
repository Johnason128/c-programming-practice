# 练习 8：动态顺序表进阶操作（头插、头删与独立容量检查） | Practice 8: Advanced Dynamic Sequence List Operations (Head Insert, Head Delete, and Independent Capacity Check)

## 功能 | Function
- 实现顺序表的头插（PushFront）和头删（PopFront）功能。 | Implement head insert (PushFront) and head delete (PopFront) functions.
- 将容量检查逻辑抽离为独立的函数，提高代码复用性和可维护性。 | Extract capacity check logic into an independent function to improve code reusability and maintainability.
- 实现动态扩容机制（初始容量为 4，之后每次翻倍）。 | Implement dynamic capacity expansion mechanism (initial capacity 4, then doubles each time).

## 代码结构 | Code Structure
- `SeqList.h`：头文件，包含顺序表结构体定义及函数接口声明。 | Header file, contains sequence list struct definition and function interface declarations.
- `SeqList.c`：源文件，包含各个功能函数的具体实现。 | Source file, contains specific implementations of each function.
- `test.c`：测试文件，包含 `main` 函数及功能测试用例。 | Test file, contains `main` function and functional test cases.

## 核心逻辑说明 | Core Logic Description

### 1. 独立容量检查 (Independent Capacity Check)
- **逻辑**：在每次插入数据前调用 `SeqListCheckCapacity`。当 `size == capacity` 时触发扩容。
- **策略**：若当前 `capacity == 0`，则初始分配 4 个空间；否则，将容量扩大为原来的 2 倍 (`capacity * 2`)。
- **优势**：避免了在每个插入函数中重复编写扩容代码，符合 DRY (Don't Repeat Yourself) 原则。

### 2. 头插操作 (Head Insert - `SeqListPushFront`)
- **逻辑**：先将现有数据从后向前整体向后移动一位，腾出 `a[0]` 的位置，再将新数据放入 `a[0]`，最后 `size++`。
- **时间复杂度**：O(N)，因为需要搬移所有现有元素。

### 3. 头删操作 (Head Delete - `SeqListPopFront`)
- **逻辑**：先检查表是否为空。若不为空，则将 `a[1]` 到 `a[size-1]` 的数据整体向前移动一位，覆盖 `a[0]`，最后 `size--`。
- **时间复杂度**：O(N)，同样需要搬移元素。

## 注意事项 | Notes
- **边界条件**：在执行头删或尾删前，必须检查 `size == 0`，防止越界访问或 `size` 变为负数。
- **性能考量**：顺序表的头插和头删涉及大量数据搬移，时间复杂度较高。在需要频繁在头部进行插入/删除的场景下，**链表 (Linked List)** 是更好的数据结构选择。
- **内存安全**：使用 `realloc` 时，必须使用临时指针 `tmp` 接收返回值，防止内存分配失败时丢失原指针导致内存泄漏。