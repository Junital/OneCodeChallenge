/**********************************************************
 * 题目：远大目标
 * 描述：给出一个数，说出绝对值在这个数内的个数。
 * 思路：2*k-1
 * 对象：LessAbsolute模拟小于绝对值。
 * 注意：数据范围为2^64。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long                    // 定义无符号长整型
#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class LessAbsolute
{
private:
public:
    /* 输入绝对值，输出绝对值内数字个数。 */
    ull inAbosolute(ll Limit)
    {
        if (Limit > 0)
        {
            return ((ull)Limit << 1) - 1;
        }
        return 0;
    }
};

int main()
{
    LessAbsolute la;

    ll limit;
    cin >> limit;

    cout << la.inAbosolute(limit) << endl;
    return 0;
}
