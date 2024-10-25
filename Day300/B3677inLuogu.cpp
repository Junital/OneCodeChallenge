/*****************************************************************
 * 题目：[语言月赛202211] Fear
 * 描述：在第五人格中，问被追逐几秒后的恐慌值。
 * 思路：判断正负性、奇偶性。
 * 对象：IdentityV模拟第五人格。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class IdentityV
{
private:
public:
    pair<bool, bool> query(ll Init, ll Chase)
    {
        if (Chase == 0)
        {
            return make_pair(false, true);
        }

        bool Neg = false;
        bool Odd = false;

        if (Init < 0 && Chase % 2)
        {
            Neg = true;
        }

        if (Init % 2)
        {
            Odd = true;
        }

        return make_pair(Neg, Odd);
    }
};

int main()
{
    ll init, chase;
    IdentityV iv;
    cin >> init >> chase;

    auto res = iv.query(init, chase);
    if (res.first)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    if (res.second)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}