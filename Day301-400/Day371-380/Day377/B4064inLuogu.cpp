/*****************************************************************
 * 题目：[GESP202412 二级] 寻找数字
 * 描述：问数字能否被四次开根号。
 * 思路：指数运算。
 * 对象：无。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

int main()
{
    int query_num;
    const double exponent = 0.25;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        int Num;
        cin >> Num;

        int X = pow(Num, exponent);

        if (Num == (int)pow(X, 1 / exponent))
        {
            cout << X << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}
