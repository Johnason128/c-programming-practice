#include <stdio.h>

float fun(int n);

int main()
{
    int n = 0;
    float s = 0;
    scanf("%d",&n);

    s = fun(n);
    printf("%f\n",s);

    return 0;
}

float fun(int n)
{
    float sum = 1.0f;
    float temp = 1.0f;
    for(int i = 1; i < n + 1; i++)
    {
        temp *= i;
        sum += 1.0f/temp;
    }
    
    return sum;
}
