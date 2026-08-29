#include <stdio.h>

int* inverse(int *p, int n)
{
    for(int i = 0; i < n/2; i++)
    {
        int temp = *(p+i);
        *(p+i)=  *(p+n-1-i);
        *(p+n-1-i) = temp;
    }
    return p;
}

int main()
{
    // 1. 准备测试数组（我们写 6 个测试一下）
    int a[] = {10, 20, 30, 40, 50, 60};
    
    // 2. 自动计算数组的长度
    int n = sizeof(a) / sizeof(a[0]); 

    printf("翻转前: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // 3. 调用函数翻转数组
    inverse(a, n); 

    printf("翻转后: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
