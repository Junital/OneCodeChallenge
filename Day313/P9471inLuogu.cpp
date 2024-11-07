/*****************************************************************
 * 题目：[yLOI2022] 签到题
 * 描述：统计字符串中 大写字母 小写字母 数字 出现的次数。
 * 思路：将所有子函数集成到对象里。
 * 对象：StringStatistics模拟字符串统计。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class StringStatistics
{
private:
    string Str;

public:
    /* 初始化，输入字符串。 */
    StringStatistics(string str) : Str(str) {}

    /* 统计数字个数。 */
    int digit_count()
    {
        int count = 0;
        for (auto ch : Str)
        {
            if (ch >= '0' && ch <= '9')
            {
                count++;
            }
        }
        return count;
    }

    /* 统计大写字母个数。 */
    int upper_letter_count()
    {
        int count = 0;
        for (auto ch : Str)
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                count++;
            }
        }
        return count;
    }

    /* 统计小写字母个数。 */
    int lower_letter_count()
    {
        int count = 0;
        for (auto ch : Str)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    string str;
    cin >> str;

    StringStatistics ss(str);
    cout << ss.digit_count() << " " << ss.lower_letter_count()
         << " " << ss.upper_letter_count() << endl;
    return 0;
}