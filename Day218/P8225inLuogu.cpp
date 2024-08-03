/**********************************************************
 * 题目：「Wdoi-5」天才⑨与天才拆分
 * 描述：判断一个数是否可以被k个9组成的数整除。
 * 思路：先构造再判断。
 * 对象：LeopardNumber模拟豹子号。
 * 注意：注意数据的范围。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class LeopardNumber
{
private:
    int Digit;
    ll getNum(int Num)
    {
        ll ans = 0;
        rep(i, 1, Num)
        {
            ans = ans * 10 + Digit;
        }
        return ans;
    }

public:
    LeopardNumber(int digit) : Digit(digit)
    {
    }

    /* 输入连续数量和数字，判断是否能整除。 */
    bool judge(ll k, ll Num)
    {
        ll mod = getNum(k);
        return !(Num % mod);
    }
};

int main()
{
    const int digit = 9;
    LeopardNumber ln(digit);
    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        ll k, num;
        cin >> k >> num;
        if (ln.judge(k, num))
        {
            cout << "aya" << endl;
        }
        else
        {
            cout << "baka" << endl;
        }
    }
    return 0;
}
