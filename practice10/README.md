# 练习 10：动态顺序表交互式菜单系统 | Practice 10: Interactive Menu System for Dynamic Sequence List

## 功能 | Function
- 实现双层交互式控制台菜单，整合顺序表的所有基础与进阶操作。 | Implement a two-level interactive console menu, integrating all basic and advanced operations of the sequence list.
- 支持批量数据输入（以 `-1` 为结束标志），提升用户操作效率。 | Support batch data input (with `-1` as the termination flag) to improve user operation efficiency.
- 确保程序在退出时正确释放动态分配的内存，防止内存泄漏。 | Ensure dynamically allocated memory is correctly freed when the program exits, preventing memory leaks.

## 代码结构 | Code Structure
- `SeqList.h`：头文件，包含顺序表结构体定义及函数接口声明。 | Header file, contains sequence list struct definition and function interface declarations.
- `SeqList.c`：源文件，包含各个功能函数的具体实现。 | Source file, contains specific implementations of each function.
- `test.c`：测试文件，包含 `menu1`, `menu2`, `MenuTest` 及 `main` 函数。 | Test file, contains `menu1`, `menu2`, `MenuTest`, and `main` functions.

## 核心逻辑说明 | Core Logic Description

### 1. 双层菜单架构 (Two-level Menu Architecture)
- **主菜单 (`menu1`)**：提供高频的基础操作（尾插、尾删、头插、头删、打印）以及进入二级菜单的入口（选项 6）。
- **二级菜单 (`menu2`)**：提供进阶操作（查询数据位置、指定位置插入、指定位置删除）。
- **导航逻辑**：通过 `while(1)` 循环保持程序运行，输入 `-1` 可平滑退出当前菜单层级或整个程序。

### 2. 批量输入机制 (Batch Input Mechanism)
- **应用场景**：在“尾插”（选项 1）和“头插”（选项 3）中。
- **实现方式**：使用 `while(x != -1)` 循环，允许用户连续输入多个数据。
- **优势**：用户无需每次插入一个数据就返回主菜单，大幅提升了测试和使用的效率。

### 3. 完整的生命周期管理 (Complete Lifecycle Management)
- **初始化**：在进入主循环前，调用 `SeqListInit(&s4)` 初始化顺序表。
- **销毁**：当用户选择退出（`input1 == -1`）跳出主循环后，立即调用 `SeqListDestroy(&s4)` 释放堆内存。
- **意义**：确保无论用户进行多少次操作，程序结束时都能干净地回收资源。

## 注意事项 | Notes
- **输入合法性**：当前代码假设用户输入的是有效整数。在实际工程中，应增加对 `scanf` 返回值的检查，防止用户输入字母导致死循环。
- **边界条件提示**：在执行“删除”或“查询”时，若位置无效或数据不存在，底层函数应返回明确的错误码或提示（如返回 `-1`），主菜单需对此进行友好提示。
- **内存安全**：`SeqListDestroy` 必须且只能在程序彻底结束前调用一次，重复释放（Double Free）会导致程序崩溃。
- **用户体验**：清晰的 `printf` 提示语（如“请输入需插入数据的位置”）是良好交互式程序的关键。

## 运行效果示例 | Example Output
```text
*************************************
请选择你的操作：>
1.尾插   2.尾删
3.头插   4.头删
5.打印   -1.退出
6.进入操作数据的界面
*************************************
> 1
请输入你要插入的数据，以-1结束
10 20 30 -1
> 5
10 20 30 
> 6
*************************************
请选择你的操作：>
7.查询数据位置
8.插入     9.删除
-1.退回上一个菜单
*************************************
> 7
请输入需查询的数据
20
pos = 1
> -1
退回主菜单
> -1
退出程序