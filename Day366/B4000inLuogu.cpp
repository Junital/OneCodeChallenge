/*****************************************************************
 * 题目：[GESP202406 一级] 休息时间
 * 描述：休息了一段时间，问现在的时间。
 * 思路：重构加法操作符。
 * 对象：Time模拟时间。
 * 注意：注意通用性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Time
{
private:
    int Hour;   // 小时
    int Minute; // 分钟
    int Second; // 秒

    /* 获取绝对时间 */
    int getAbsTime()
    {
        int AbsTime = Second + ((Hour * MPH) + Second) * SPM;
        return AbsTime;
    }

public:
    const int MPH = 60; // 每小时60分钟
    const int SPM = 60; // 每分钟60秒
    const int HPD = 24; // 每天24小时

    /* 初始化。 */
    Time(int h, int m) : Hour(h), Minute(m), Second(0) {}
    Time(int h, int m, int s) : Hour(h), Minute(m), Second(s) {}

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
        int new_hour = Hour - (Interval / SPM) / MPH;
        int new_min = Minute - (Interval / SPM) % MPH;
        int new_second = Second - Interval % SPM;

        if (new_second < 0)
        {
            new_min--;
            new_second += SPM;
        }

        if (new_min < 0)
        {
            new_hour--;
            new_min += MPH;
        }

        if (new_hour < 0)
        {
            new_hour += HPD;
        }

        return Time(new_hour, new_min, new_second);
    }

    /* 重构加法。 */
    Time operator+(int Interval)
    {
        int new_hour = Hour + (Interval / SPM) / MPH;
        int new_min = Minute + (Interval / SPM) % MPH;
        int new_second = Second + Interval % SPM;

        if (new_second >= SPM)
        {
            new_min++;
            new_second -= SPM;
        }

        if (new_min >= MPH)
        {
            new_hour++;
            new_min -= MPH;
        }

        if (new_hour >= HPD)
        {
            new_hour -= HPD;
        }

        return Time(new_hour, new_min, new_second);
    }

    /* 输出时分秒。 */
    void print_HMS()
    {
        cout << Hour << " " << Minute
             << " " << Second << endl;
    }

    /* 输出时分。 */
    void print_HM()
    {
        cout << Hour << " " << Minute << endl;
    }
};

int main()
{
    int h, m, s;
    cin >> h >> m >> s;
    Time t1(h, m, s);

    int interval;
    cin >> interval;
    Time t2 = t1 + interval;

    t2.print_HMS();
    return 0;
}