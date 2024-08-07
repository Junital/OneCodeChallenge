/*****************************************************************
 * 题目：[语言月赛202301] 就要 62
 * 描述：判断某个数是否能被整除或者出现了62。
 * 思路：封装一下即可。
 * 对象：Mod模拟模数，SubStr模拟子串。
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
};

class SubStr
{
private:
    string sub_string; // 子串

public:
    /* 初始化输入需要包含的子串。 */
    SubStr(string substr) : sub_string(substr) {}

    /* 判断字符串是否包含子串。 */
    bool judge(string Str)
    {
        return Str.find(sub_string) != (ll)-1;
    }
};

int main()
{
    const int mod = 62;
    Mod m(mod);
    SubStr ss(to_string(mod));

    ll Num;
    cin >> Num;
    if (m.judge(Num) || ss.judge(to_string(Num)))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
