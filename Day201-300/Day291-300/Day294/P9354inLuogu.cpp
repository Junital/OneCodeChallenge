/*****************************************************************
 * 题目：「SiR-1」Popsicle
 * 描述：将一排冰棍逐一拿走，老鼠会进行捣乱，问最少的操作次数。
 * 思路：求和问题。
 * 对象：DigitSum模拟数位求和。
 * 注意：注意数据的范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

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
};

int main()
{
    int query_num;
    DigitSum<ll> ds;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        ll Num;
        cin >> Num;
        cout << ds.game_query(Num) << endl;
    }
    return 0;
}