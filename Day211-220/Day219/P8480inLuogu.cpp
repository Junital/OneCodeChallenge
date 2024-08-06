/*****************************************************************
 * 题目：「HGOI-1」PMTD
 * 描述：有m次操作将数组中一个元素进行加减乘除四种操作，问如何使数组的极差最大。
 * 思路：最大最小各操作一次，进行比较。
 * 对象：PMTD模拟加减乘除。
 * 注意：注意数据的范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                             // 定义长整型
#define rep(i, s, k) for (ll i = s; i <= k; i++) // 定义快速循环

class PMTD
{
private:
    const int base = 2;

    /* 最大化某个数。 */
    ll maximize(ll Number, ll OpNum)
    {
        rep(i, 1, OpNum)
        {
            if (Number < base)
            {
                Number += base;
            }
            else
            {
                Number *= base;
            }
        }

        return Number;
    }

    /* 最小化某个数。 */
    ll minimize(ll Number, ll OpNum)
    {
        rep(i, 1, OpNum)
        {
            Number /= base;
        }

        return Number;
    }

public:
    /* 输入数组和操作数，求最大极差。 */
    ll optimum(vector<ll> Arr, ll OpNum)
    {
        ll arr_max = *(max_element(Arr.begin(), Arr.end()));
        ll arr_min = *(min_element(Arr.begin(), Arr.end()));

        return max(maximize(arr_max, OpNum) - arr_min,
                   arr_max - minimize(arr_min, OpNum));
    }
};

int main()
{
    PMTD pmtd;
    ll ArrSize, OpNum;
    cin >> ArrSize >> OpNum;

    vector<ll> Arr(ArrSize);
    rep(i, 0, ArrSize - 1)
    {
        cin >> Arr[i];
    }

    cout << pmtd.optimum(Arr, OpNum) << endl;
    return 0;
}
