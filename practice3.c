#include <stdio.h>

void f(char a[], char b[])
{
    int i = 0;
    int j = 0;
    while(*(a+i) != '\0')
    {
        i++;
    }
    while(*(b+j) != '\0')
    {
        a[i] = b[j];
        i++;
        j++;
    }
    a[i] = '\0';
}

int main()
{
    char a[100] = "Hello"; 
    char b[] = "World";

    printf("连接前: %s\n", a);
    
    f(a, b); 
    
    printf("连接后: %s\n", a);

    return 0;
}

// 纯指针版
// void f(char a[], char b[]) {
//     char *p = a;
//     char *q = b;

//     // 1. 把指针 p 移动到 a 的末尾（'\0'的位置）
//     while(*p != '\0') {
//         p++; 
//     }

//     // 2. 把 q 指向的内容逐个赋值给 p，同时 p 和 q 都向后移
//     while(*q != '\0') {
//         *p = *q;
//         p++;
//         q++;
//     }

//     // 3. 在 p 当前的位置打上结束符
//     *p = '\0';
// }
