# 练习 9：动态顺序表高级操作（查找、指定位置插入与删除） | Practice 9: Advanced Dynamic Sequence List Operations (Find, Insert at Position, Erase at Position)

## 功能 | Function
- 实现顺序表的查找功能（`SeqListFind`），返回元素首次出现的下标。 | Implement the find function (`SeqListFind`) to return the index of the first occurrence of an element.
- 实现在指定位置插入元素（`SeqListInsert`）。 | Implement inserting an element at a specified position (`SeqListInsert`).
- 实现删除指定位置的元素（`SeqListErase`）。 | Implement deleting an element at a specified position (`SeqListErase`).

## 代码结构 | Code Structure
- `SeqList.h`：头文件，包含顺序表结构体定义及函数接口声明。 | Header file, contains sequence list struct definition and function interface declarations.
- `SeqList.c`：源文件，包含各个功能函数的具体实现。 | Source file, contains specific implementations of each function.
- `test.c`：测试文件，包含 `main` 函数及功能测试用例。 | Test file, contains `main` function and functional test cases.

## 核心逻辑说明 | Core Logic Description

### 1. 查找功能 (Find - `SeqListFind`)
- **逻辑**：遍历顺序表，逐一比对元素。若找到目标值，返回其下标；若遍历结束未找到，返回 -1。
- **时间复杂度**：O(N)，最坏情况下需要遍历整个表。

### 2. 指定位置插入 (Insert at Position - `SeqListInsert`)
- **逻辑**：
  1. 检查插入位置 `pos` 的合法性（`0 <= pos <= size`）。
  2. 调用容量检查函数，确保空间足够。
  3. **从后向前**搬移数据：将 `pos` 及之后的元素依次向后移动一位，腾出空间。
  4. 将新数据放入 `a[pos]`，最后 `size++`。
- **时间复杂度**：O(N)，因为需要搬移 `pos` 之后的所有元素。

### 3. 指定位置删除 (Erase at Position - `SeqListErase`)
- **逻辑**：
  1. 检查删除位置 `pos` 的合法性（`0 <= pos < size`）。
  2. **从前向后**搬移数据：将 `pos + 1` 及之后的元素依次向前移动一位，覆盖目标位置。
  3. 最后 `size--`。
- **时间复杂度**：O(N)，因为需要搬移 `pos` 之后的所有元素。

## 注意事项 | Notes
- **位置合法性检查**：
  - 插入时 `pos` 的范围是 `[0, size]`（可以在尾部追加）。
  - 删除时 `pos` 的范围是 `[0, size-1]`（不能删除不存在的位置）。
- **数据搬移方向**：
  - 插入必须**从后向前**搬移，否则会覆盖后续数据。
  - 删除必须**从前向后**搬移，确保数据正确前移。
- **性能考量**：指定位置的插入和删除同样涉及大量数据搬移。若需频繁在中间位置操作，**链表 (Linked List)** 是更优选择。