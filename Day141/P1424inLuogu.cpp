/***************************************************************
 * 题目：小鱼的航程（改进版）
 * 描述：计算工作日天数。
 * 思路：统计。
 * 对象：WeekDayCnt计算区间内的工作日。
 * 注意：优化算法。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class WeekDayCnt
{
private:
    const int DaysPerWeek = 7;     // 一周7天
    const int RestDaysPerWeek = 2; // 周末2天

public:
    /* 输入目前的天数和经过的天数，输出工作日天数。 */
    int CountWeekDay(int StartIdx, int Period)
    {
        int weekdays = Period;
        while (Period >= DaysPerWeek)
        {
            Period -= DaysPerWeek;
            weekdays -= RestDaysPerWeek;
        }

        int endIdx = StartIdx + Period - 1;
        if (endIdx >= DaysPerWeek && StartIdx <= DaysPerWeek - 1) // 扣一个周末
        {
            weekdays -= 2;
        }
        else if (endIdx >= DaysPerWeek - 1 || StartIdx <= DaysPerWeek) // 扣一天
        {
            weekdays -= 1;
        }

        return weekdays;
    }
};

int main()
{
    WeekDayCnt wdc;

    int startidx, period;
    cin >> startidx >> period;

    cout << wdc.CountWeekDay(startidx, period) * 250 << endl;
    return 0;
}
