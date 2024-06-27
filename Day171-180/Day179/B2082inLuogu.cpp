/**********************************************************
 * 题目：数学统计
 * 描述：给定区间，求出数字2出现的次数。
 * 思路：借用之前做好的函数。
 * 对象：DigitStat模拟数字统计。
 * 注意：注意数据范围。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class DigitStatistic
{
private:
public:
    /* 输入数字个数和需要统计的数字。 */
    int single_stat(int Num, int Digit)
    {
        assert(Digit >= 0 && Digit <= 9);

        /* 采用分组的思想：
        一个整组就是邻近某一位都是一个数字的数块，比如10~19就是一个整组。
        当然，也包括一些零散的组。*/

        int Group = 1; // 一个组的大小，会随着位数而改变
        int Sum = 0;   // 统计

        while (Group <= Num)
        {
            int Enough = Num / (Group * 10);   // 有多少个包含这一位的整组
            int NumDigit = (Num / Group) % 10; // 位数对应的数字。
            int Remainder = Num % Group;       // 剩余数。

            if (Digit > 0)
            {
                if (Digit == NumDigit)
                {
                    Sum += Enough * Group + Remainder + 1;
                }
                else if (NumDigit > Digit)
                {
                    Sum += (Enough + 1) * Group;
                }
                else
                {
                    Sum += Enough * Group;
                }
            }
            else
            {
                if (NumDigit == 0)
                {
                    Sum += (Enough - 1) * Group + Remainder + 1;
                }
                else
                {
                    Sum += Enough * Group;
                }
            }

            // cout << Sum << endl;s

            Group *= 10;
        }

        return Sum;
    }

    /* 区间统计 */
    int interval_stat(int Small, int Large, int Digit)
    {
        return single_stat(Large, Digit) - single_stat(Small - 1, Digit);
    }
};

int main()
{
    int small, large;
    DigitStatistic ds;

    cin >> small >> large;
    cout << ds.interval_stat(small, large, 2);
    return 0;
}