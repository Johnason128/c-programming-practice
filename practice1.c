#include <stdio.h>
int main()
{
    int sum = 0;
    for(int i = 1;i < 21 ; i++)
    {
        for(int j = 1;j < i+1;  j++)
        {
            sum += j;
        }
    }
    printf("sum = %d\n",sum);
    
    return 0;
}
