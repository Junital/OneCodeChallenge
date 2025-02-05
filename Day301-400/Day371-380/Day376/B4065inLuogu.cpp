/*****************************************************************
 * 题目：[GESP202412 二级] 数位和
 * 描述：数位求和。
 * 思路：调用已构建对象。
 * 对象：DigitSum模拟数位求和。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

template <typename T>
class DigitSum
{
private:
    const int Base = 10;
    const int MaxDigit = 9;

public:
    /* 输入一个整数，输出数位求和。 */
    T query(T Num)
    {
        T Sum = 0;
        while (Num != 0)
        {
            Sum += (Num % Base);
            Num /= Base;
        }
        return Sum;
    }

    /* 特殊判断，针对对弈的请求。 */
    T game_query(T Num)
    {
        T Sum = 0;
        bool max = false;
        if (Num == 0 && !max)
        {
            Sum += MaxDigit;
            max = true;
        }
        while (Num != 0)
        {
            T digit = Num % Base;
            if (digit == 0 && !max)
            {
                Sum += MaxDigit;
                max = true;
            }
            Sum += digit;
            Num /= Base;
        }

        if (!max)
        {
            Sum += MaxDigit - 1;
        }
        return Sum;
    }

    /* 输入开始和结束，问数位求和等于指定数的所有情况。
       输出的数组按照从小到大排序。 */
    vector<T> interval_query(T Begin, T End, T Sum)
    {
        vector<T> res;
        for (T i = Begin; i <= End; i++)
        {
            if (Sum == query(i))
            {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main()
{
    DigitSum<ll> ds;

    int query_num;
    cin >> query_num;

    ll max_sum = 0;
    rep(i, 1, query_num)
    {
        ll num;
        cin >> num;
        max_sum = max(max_sum, ds.query(num));
    }

    cout << max_sum << endl;
    return 0;
}