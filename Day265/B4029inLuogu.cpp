/*****************************************************************
 * 题目：[语言月赛 202409] 种子
 * 描述：种子的增长符合一定规律，问第几天能破土。
 * 思路：模拟。
 * 对象：SeedGrowth模拟种子成长。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class SeedGrowth
{
private:
    int SpeedBase; // 增长基数。
    int ExtraDay;  // 额外增长开始天数
    int Extra;     // 额外增长量
    int Threshold; // 破土阈值

    /* 模拟增长，输入天数和目前增长情况。 */
    int grow(int DayNum, int Current)
    {
        Current += DayNum / SpeedBase;

        if (DayNum >= ExtraDay)
        {
            Current += Extra;
        }

        return Current;
    }

public:
    /* 初始化，输入增长基数，额外增长开始天数，额外增长量，破土阈值。 */
    SeedGrowth(int speedbase, int extraday,
               int extra, int threshold)
        : SpeedBase(speedbase), ExtraDay(extraday),
          Extra(extra), Threshold(threshold) {}

    /* 询问什么时候能破土。 */
    int query()
    {
        int current = 0;
        int daynum = 1;
        while (true)
        {
            current = grow(daynum, current);
            if (current >= Threshold)
            {
                break;
            }
            daynum++;
        }

        return daynum;
    }
};

int main()
{
    int extraday, extra, speedbase, threshold;
    cin >> extraday >> extra >> speedbase >> threshold;

    SeedGrowth sg(speedbase, extraday, extra, threshold);
    cout << sg.query() << endl;
    return 0;
}