/**********************************************************
 * 题目：输出绝对值
 * 描述：对一个浮点数输出绝对值，保留两位小数。
 * 思路：调用函数。
 * 函数：printAbs输出绝对值。
 * 注意：注意精度。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

void printAbs(double Num)
{
    cout << fixed << setprecision(2) << abs(Num) << endl;
}

int main()
{
    double Num;

    scanf("%8lf", &Num);

    printAbs(Num);
    return 0;
}