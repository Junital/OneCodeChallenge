/*****************************************************************
 * 题目：[COCI2015-2016#5] ZAMKA
 * 描述：在区间中，找到各位数字之和为某个值的最大、最小整数。
 * 思路：数位求和
 * 对象：BookShop模拟书店。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

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
    int begin, end, sum;
    cin >> begin >> end >> sum;

    DigitSum<int> ds;
    auto ans = ds.interval_query(begin, end, sum);
    cout << ans[0] << endl;
    cout << ans.back() << endl;
    return 0;
}