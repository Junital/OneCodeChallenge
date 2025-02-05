/*****************************************************************
 * 题目：[语言月赛202304] 扶苏与 0
 * 描述：数字映射求和。
 * 思路：获得每一个数字，映射后再求和。
 * 对象：DigitMapSum模拟数字映射求和。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class DigitMapSum
{
private:
    map<int, int> DigitMap;

    bool all_digit_judge()
    {
        rep(i, 0, MAX_DIGIT)
        {
            auto it = DigitMap.find(i);
            if (it == DigitMap.end())
            {
                return false;
            }
        }

        return true;
    }

    const int MAX_DIGIT = 9;

public:
    /* 初始化，输入映射。 */
    DigitMapSum(map<int, int> Map) : DigitMap(Map)
    {
        assert(all_digit_judge());
    }

    /* 请求，输入数字，输出求和。 */
    int query(ll Num)
    {
        int Sum = 0;
        while (Num > 0)
        {
            int Digit = Num % (MAX_DIGIT + 1);
            Sum += DigitMap[Digit];

            Num /= (MAX_DIGIT + 1);
        }

        return Sum;
    }
};

int main()
{
    const map<int, int> dm = {{1, 0},
                              {2, 1},
                              {3, 0},
                              {4, 0},
                              {5, 0},
                              {6, 1},
                              {7, 0},
                              {8, 2},
                              {9, 1},
                              {0, 1}};
    DigitMapSum dms(dm);
    ll num;
    cin >> num;
    cout << dms.query(num) << endl;
    return 0;
}
