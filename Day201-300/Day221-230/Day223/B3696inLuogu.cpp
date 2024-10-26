/*****************************************************************
 * 题目：[语言月赛202301] Hello, 2023
 * 描述：将一个数对2023进行取模。
 * 思路：封装一下即可。
 * 对象：Mod模拟模数。
 * 注意：注意数据的范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Mod
{
private:
    ll mod;

public:
    /* 初始化，输入模数。 */
    Mod(int m) : mod(m)
    {
    }

    /* 判断是否能被整除。 */
    bool judge(ll Number)
    {
        return !(Number % mod);
    }

    /* 计算取模的结果。 */
    ll calculate(ll Number)
    {
        return ((Number % mod) + mod) % mod;
    }
};

int main()
{
    const ll mod = 2023;
    Mod m(mod);

    ll Num;
    cin >> Num;
    cout << m.calculate(Num) << endl;
    return 0;
}
