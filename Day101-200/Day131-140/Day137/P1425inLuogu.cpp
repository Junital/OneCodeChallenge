/***************************************************************
 * 题目：小鱼的游泳时间
 * 描述：两个时间相减。
 * 思路：模拟时间。
 * 对象：Money模拟钱。
 * 注意：无。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Time
{
private:
    int Hour, Minute;       // 小时、分钟
    const int MINPERH = 60; // 每小时60分钟
    const int HPERDAY = 24; // 每天24小时

public:
    /* 输入小时和分钟。 */
    Time(int hour, int minute = 0)
        : Hour(hour), Minute(minute)
    {
        Hour %= HPERDAY;
        Minute %= MINPERH;
    }

    /* 减法。 */
    Time operator-(Time &other)
    {
        int resHour = Hour - other.Hour;
        int resMinute = Minute - other.Minute;

        if (resMinute < 0)
        {
            resMinute += MINPERH;
            resHour -= 1;
        }

        return Time(resHour, resMinute);
    }

    /* 加法。 */
    Time operator+(Time &other)
    {
        int resHour = Hour + other.Hour;
        int resMinute = Minute + other.Minute;

        if (resMinute >= 60)
        {
            resHour += 1;
            resMinute %= MINPERH;
        }

        return Time(resHour, resMinute);
    }

    void print()
    {
        cout << Hour << " " << Minute;
    }
};

int main()
{
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    Time start(h1, m1);
    Time ending(h2, m2);

    Time interval = ending - start;
    interval.print();
    return 0;
}