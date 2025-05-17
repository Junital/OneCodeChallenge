/*****************************************************************
 * 题目：[语言月赛202212] 计算
 * 描述：给一个三位数，输出三位数之和、和的平方、和的立方。
 * 思路：如果要可拓展，应该先拆开，再求和。
 * 对象：DigitSum模拟位数求和。
 * 注意：最后结果别溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

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
    DigitSum<i64> digit_sum;

    i64 num;
    cin >> num;                     // 输入一个三位数
    i64 sum = digit_sum.query(num); // 求和

    cout << sum << endl;             // 输出和
    cout << sum * sum << endl;       // 输出和的平方
    cout << sum * sum * sum << endl; // 输出和的立方
    return 0;
}