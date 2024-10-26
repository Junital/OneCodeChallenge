/*****************************************************************
 * 题目：[信息与未来 2022] 幸运数字
 * 描述：判断一个数字的每一位是否是从小到大递增的。
 * 思路：逐位判断。
 * 对象：LuckyNumber模拟幸运数字。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class LuckyNumber
{
private:
public:
    /* 单一判断。 */
    bool single_judge(int Num)
    {
        int last_digit = Num % 10;
        Num /= 10;

        while (Num != 0)
        {
            int current_digit = Num % 10;
            if (current_digit >= last_digit)
            {
                return false;
            }
            last_digit = current_digit;
            Num /= 10;
        }

        return true;
    }

    /* 区间统计。 */
    int interval_count(int Begin, int Last)
    {
        int count = 0;
        rep(i, Begin, Last)
        {
            if (single_judge(i))
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    LuckyNumber ln;

    int begin, end;
    cin >> begin >> end;

    cout << ln.interval_count(begin, end) << endl;
    return 0;
}
