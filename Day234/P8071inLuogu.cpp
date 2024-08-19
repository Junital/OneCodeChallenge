/*****************************************************************
 * 题目：[COCI2009-2010#7] SPAVANAC
 * 描述：输出24小时进制下早45分钟的时间。
 * 思路：重构减法操作符。
 * 对象：Time模拟时间。
 * 注意：注意通用性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Time
{
private:
    int Hour;           // 小时
    int Minute;         // 分钟
    const int MPH = 60; // 每小时60秒
    const int HPD = 24; // 每天24小时

    /* 获取绝对时间 */
    int getAbsTime()
    {
        int AbsTime = Minute + Hour * MPH;
        return AbsTime;
    }

public:
    /* 初始化，输入小时和分钟。 */
    Time(int h, int m) : Hour(h), Minute(m) {}

    /* 重构减法 */
    int operator-(Time other)
    {
        int abs1 = this->getAbsTime();
        int abs2 = other.getAbsTime();
        return abs1 - abs2;
    }

    /* 重构减法 */
    Time operator-(int Interval)
    {
        int new_hour = Hour - Interval / MPH;
        int new_min = Minute - Interval % MPH;

        if (new_min < 0)
        {
            new_hour--;
            new_min += MPH;
        }

        if (new_hour < 0)
        {
            new_hour += HPD;
        }

        return Time(new_hour, new_min);
    }

    /* 输出 */
    void print()
    {
        cout << Hour << " " << Minute << endl;
    }
};

int main()
{
    int hour, minute;
    cin >> hour >> minute;

    Time t1(hour, minute);
    Time t2 = t1 - 45;

    t2.print();
    return 0;
}