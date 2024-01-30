/***********************************************
 * 题目：【深基2.习2】三角形面积
 * 描述：输入三条边，输出三角形面积。
 * 思路：S=\sqrt{p(p-a)(p-b)(p-c)}，其中p=(a+b+c)/2。
 * 函数：TriArea输出三角形面积。
 * 注意：保留一位小数。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

/* 输入三角形的三条边，输出面积。 */
double TriArea(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));

    return S;
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    cout << fixed << setprecision(1) << TriArea(a, b, c) << endl;

    return 0;
}