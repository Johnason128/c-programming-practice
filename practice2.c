#include <stdio.h>
// 冒泡排序版
// void f(float score[20], float b[3])
// {
//     for(int j = 0; j < 19; j++)
//     {
//         for(int i = 0; i < (19 - j); i++)
//         {
//             if(score[i] > score[i+1])
//             {
//                 float temp = 0;
//                 temp = score[i];
//                 score[i] = score[i+1] ;
//                 score[i+1] = temp;
//             }
//         }
        
//     }
//     b[0] = score[19];
//     b[1] = score[0];

//     float sum = 0;
//     for(int m = 0; m < 20; m++)
//     {
//         sum += score[m];
//     }
//     b[2] = sum/20.0f;

//     printf("%f %f %f",b[0], b[1], b[2]);//仅用于测试，考试不写
// }

//优化版
void f(float score[20], float b[3])
{
    float sum = score[0];
    float max = score[0];
    float min = score[0];
    for(int i = 1; i < 20; i++)
    {
        sum += score[i];
        if(score[i] > max)
        {
            max = score[i];
        }
        if(score[i] < min)
        {
            min = score[i];
        }

    }
    b[0] = max;
    b[1] = min;
    b[2] = sum/20.0f;

    printf("%f %f %f",b[0], b[1], b[2]);//仅用于测试，考试不写
}

//测试
int main()
{
    float test1[20] = {2.0,4.3,5.6,9.7,1.9,3.3,15.7,34.0,25.8,11.7};//便于测试，仅给十个数据
    float test2[3] = {0.0};
    f(test1, test2);

    return 0;
}
