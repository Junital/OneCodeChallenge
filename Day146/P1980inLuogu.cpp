/******************************************************
 * 题目：[NOIP2013 普及组] 计数问题
 * 描述：对数字出现的字数进行统计。
 * 思路：从个位、十位、百位依次统计。
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

        int Group = 1; // 一个组的大小
        int Sum = 0;   // 统计

        /* 以数字个数为728，数字为7为例 */
        while (Group <= Num)
        {
            Sum += Num / (Group * 10) * Group; // 统计720中的7、700中的70和7000中的700

            if (Num >= Group * 10) // 统计720~728中的7、700~728中的70
            {
                int Remainder = Num % (Group * 10);
                if (Remainder >= Digit * Group && Remainder != 0)
                {
                    Sum += Group;
                }
            }
            else if (Num >= Group * Digit && Digit != 0) // 统计700~728中的700。
            {
                Sum += (Num - Group * Digit + 1);
            }
            // cout << Sum << endl;

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