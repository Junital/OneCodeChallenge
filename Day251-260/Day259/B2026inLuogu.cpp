/*****************************************************************
 * 题目：计算浮点数相除的余
 * 描述：计算两个双精度浮点数相除的余数。
 * 思路：利用floor来获得除数。
 * 函数：FloatMod模拟浮点数余数。
 * 注意：注意浮点数精度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 浮点数取模。 */
template <typename T>
pair<T, T> FloatMod(T A, T B)
{
    T Ans = floor(A / B);
    T Mod = A - Ans * B;

    return make_pair(Ans, Mod);
}

int main()
{
    double a, b;
    cin >> a >> b;

    auto ans = FloatMod(a, b);
    cout << fixed << setprecision(7) << ans.second << endl;
    return 0;
}
