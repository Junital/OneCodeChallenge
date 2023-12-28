/************************************************************
 * 题目：使徒袭来
 * 要求：输入一个正整数，代表三个数字的积，现在求出这三个数字所有可能中最小的和。
 * 作者：Junital
 * 思路：x * y * z = a，a为常数，求x + y + z最小为多少。(推测为3\times \sqrt[3]{a})
 * 函数：ThreeTimesSqrtThree计算最小的结果
 ***********************************************************/

#include <bits/stdc++.h>
using namespace std;

double ThreeTimesSqrtThree(double x)
{
    double sqrt3 = (double)1.0 / 3;
    double ans = 3 * pow(x, sqrt3); // 3\times \sqrt[3]{a}
    return ans;
}

int main()
{

    int x;
    scanf("%d", &x);
    printf("%.3f", ThreeTimesSqrtThree(x));
    return 0;
}
