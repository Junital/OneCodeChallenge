/*****************************************************************
 * 题目：计算分数加减表达式的值
 * 描述：计算数列求和。
 * 思路：循环加入。
 * 对象：ArraySum模拟数列求和。
 * 注意：注意精度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ArraySum
{
private:
public:
    /* 输入求和数量。 */
    double sum(int index)
    {
        double ans = 1;
        rep(i, 2, index)
        {
            ans += pow(-1, i - 1) * (1.0 / i);
        }
        return ans;
    }
};

int main()
{
    int idx;
    ArraySum as;
    cin >> idx;

    cout << fixed << setprecision(4) << as.sum(idx) << endl;
    return 0;
}
