/*****************************************************************
 * 题目：[蓝桥杯 2022 省 B] 刷题统计
 * 描述：工作日刷x道题，周末刷y道题，问何时能刷到n题。
 * 思路：先算总和，再具体精确到天数。
 * 对象：WeekSchedule模拟一周计划。
 * 注意：类型必须是int_64。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

class WeekSchedule
{
private:
    const int week_days = 7;
    const int work_days = 5;
    const int weekend_days = week_days - work_days;
    vector<int64_t> schedule;
    int64_t week_total = 0;

public:
    /* 目前支持工作日、周末两种模式，之后也可以每天都不一样。 */
    WeekSchedule(int64_t work, int64_t weekend)
    {
        schedule.resize(week_days);
        for (int i = 0; i < work_days; i++)
        {
            schedule[i] = work;
        }

        for (int i = work_days; i < week_days; i++)
        {
            schedule[i] = weekend;
        }
    }

    int64_t query(int64_t goal)
    {
        week_total = accumulate(schedule.begin(), schedule.end(), int64_t(0));
        int64_t weeks = goal / week_total;
        int64_t remain = goal % week_total;

        int day = 0;
        while (remain > 0)
        {
            remain -= schedule[day];
            day++;
        }

        return weeks * week_days + day;
    }
};

int main()
{
    i64 work, weekend, goal;
    cin >> work >> weekend >> goal;
    WeekSchedule schedule(work, weekend);
    cout << schedule.query(goal) << endl;
    return 0;
}