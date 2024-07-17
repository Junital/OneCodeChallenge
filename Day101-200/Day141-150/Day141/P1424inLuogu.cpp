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
        int weekdays = Period - (Period / DaysPerWeek) * RestDaysPerWeek;
        Period %= DaysPerWeek;

        int endIdx = StartIdx + Period - 1;
        set<int> Days; // 记录星期

        rep(i, StartIdx, endIdx)
        {
            Days.insert(i % DaysPerWeek);
        }

        if (Days.count(DaysPerWeek - 1) > 0) // 周六
        {
            weekdays -= 1;
        }

        if (Days.count(0) > 0) // 周日
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
