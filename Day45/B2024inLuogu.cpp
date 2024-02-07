/***********************************************
 * 题目：输出浮点数
 * 描述：输入浮点数，输出浮点数。
 * 思路：输出游戏。
 * 函数：FloatPrint进行输出浮点数。
 * 注意：要注意输出格式。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

/* 输入一个浮点数，输出各种浮点数形式。 */
void FloatPrint(double Num)
{
    printf("%f\n", Num);
    printf("%.5f\n", Num);
    printf("%e\n", Num);
    printf("%g\n", Num);
}

int main()
{
    double Num;
    cin >> Num;
    FloatPrint(Num);
    return 0;
}