/******************************************************
 * 题目：[NOIP2013 普及组] 计数问题
 * 描述：对数字出现的字数进行统计。
 * 思路：从个位、十位、百位依次统计。
 * 见P1980 Solve。
 * 对象：NumberStatistic进行数字统计。
 * 注意：逻辑完备性。
 ******************************************************/

#include <bits/stdc++.h>

using namespace std;

class DigitStatistic
{
private:
public:
    /* 输入数字个数和需要统计的数字。 */
    int statistics(int Num, int Digit)
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
};

int main()
{
    DigitStatistic ds;
    int Num, Digit;

    cin >> Num >> Digit;

    cout << ds.statistics(Num, Digit) << endl;
    return 0;
}