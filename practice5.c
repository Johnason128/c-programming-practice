#include <stdio.h>

void sort(int *p, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            if(*(p+j) < *(p+j+1))
            {
                int temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;
            }
        }
    }
}

int main()
{
    int a[] = {34, 12, 56, 78, 9, 23};
    int n = sizeof(a) / sizeof(a[0]);
    
    sort(a, n);
    
    printf("从大到小排序结果: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
