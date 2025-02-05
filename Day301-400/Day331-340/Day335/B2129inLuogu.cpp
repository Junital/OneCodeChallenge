/*****************************************************************
 * 题目：最大数 max(x,y,z)
 * 描述：根据公式求出答案。
 * 思路：直接计算。
 * 函数：max模拟三个元素中取最大值。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    cout << fixed << setprecision(3)
         << max({a, b, c}) /
                (max({a + b, b, c}) *
                 max({a, b, b + c}))
         << endl;
    return 0;
}
