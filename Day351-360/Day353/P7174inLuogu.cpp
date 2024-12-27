/*****************************************************************
 * 题目：[COCI2014-2015#4] CESTA
 * 描述：问一些数字所能组成的最大整除30的数。
 * 思路：数字字典，同时计算所有数字之和判断。
 * 对象：DigitMap模拟数字字典。
 * 注意：注意提升可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class DigitMap
{
private:
    const int MAX_DIGIT = 9;
    int DigitSum = 0;
    map<int, int> digit_map;

    void to_map(string num)
    {
        DigitSum = 0;
        for (auto ch : num)
        {
            if (ch >= '0' && ch <= '9')
            {
                int Digit = ch - '0';
                digit_map[Digit] += 1;
                DigitSum += Digit;
            }
        }
    }

public:
    /* 初始化，输入一个数字。 */
    DigitMap(string Num)
    {
        to_map(Num);
    }

    /* 最大30倍数的数，没有输出-1。 */
    string max_30_base()
    {
        if (digit_map[0] > 0 && DigitSum % 3 == 0)
        {
            string res;
            for (auto it = digit_map.rbegin();
                 it != digit_map.rend(); ++it)
            {
                for (int cnt = 1; cnt <= it->second; cnt++)
                {
                    res += (it->first + '0');
                }
            }
            return res;
        }
        return "-1";
    }
};

int main()
{
    string num;
    cin >> num;

    DigitMap dm(num);
    cout << dm.max_30_base() << endl;
    return 0;
}