/*****************************************************************
 * 题目：[KMOI R1] 音波武器
 * 描述：不断累乘，获得最大取模数。
 * 思路：区间遍历。
 * 对象：MaxMutipleMod模拟最大累乘取模数。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class MaxMultipleMod
{
private:
    int Mod; // 模数。

    /* 输出为一个数的阶乘，比如2!=2*1=2 */
    ll multiple(int x)
    {
        ll sum = 1;
        do
        {
            sum = (sum * x) % Mod; // 每次累乘
        } while ((--x) > 1); // 判断是否减到1了

        return sum;
    }

public:
    /* 初始化，输入一个模数。 */
    MaxMultipleMod(int mod) : Mod(mod) {}

    /* 请求，输入起点 + 终点，输出最大的取模数。 */
    ll query(int Begin, int End)
    {
        ll sum = multiple(Begin);
        ll ans = sum;

        rep(i, Begin + 1, End)
        {
            sum = (sum * i) % Mod;
            ans = max(sum, ans);
        }

        return ans;
    }
};

int main()
{
    int begin, end, mod;
    cin >> begin >> end >> mod;

    MaxMultipleMod mmm(mod);
    cout << mmm.query(begin, end) << endl;

    return 0;
}
