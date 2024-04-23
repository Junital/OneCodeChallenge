/**********************************************************
 * 题目：yyy loves Maths II
 * 描述：一序列数求和。
 * 思路：模拟。
 * 函数：LongDoubleSum求和。
 * 注意：注意溢出问题，注意精度问题。
 *********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ld long double // 定义长浮点数

double DoubleSum(vector<double> Seq)
{
    double Sum = 0;

    for (auto num : Seq)
    {
        Sum += num;
    }

    return Sum;
}

int main()
{
    double Num;
    vector<double> seq;

    while (scanf("%15lf", &Num))
    {
        seq.push_back(Num);
    }

    printf("%.5lf\n", DoubleSum(seq));
}