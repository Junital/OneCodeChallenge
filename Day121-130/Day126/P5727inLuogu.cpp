/***************************************************************
 * 题目：【深基5.例3】冰雹猜想
 * 描述：冰雹猜想[可以谷歌一下]，输入一个数变化到1的过程。
 * 思路：模拟。
 * 对象：HailGuess模拟冰雹猜想。
 * 注意：数字可能会很大，注意溢出。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class HailGuess
{
private:
    ll transform(ll Num)
    {
        if (Num & (ll)1)
        {
            return (Num << 1) + Num + 1; // 乘三加1
        }
        else
        {
            return Num >> 1; // 除二
        }
    }

public:
    /* 模拟过程，输入一个数字，求出其变为1的过程。 */
    stack<ll> stimulate(ll Num)
    {
        stack<ll> Process; // 记录过程
        Process.push(Num);
        while (Num != 1)
        {
            // cout << Num << endl;
            Num = transform(Num);
            Process.push(Num);
        }

        return Process;
    }
};

int main()
{
    HailGuess hg;
    ll Num;

    cin >> Num;
    // for (Num = 1; Num <= 100; Num++)
    // {
    stack<ll> p = hg.stimulate(Num);

    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;
    // }
    return 0;
}
