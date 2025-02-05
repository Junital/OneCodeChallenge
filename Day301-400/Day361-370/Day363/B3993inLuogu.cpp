/*****************************************************************
 * 题目：[洛谷 202406GESP 模拟 一级] 明日复明日
 * 描述：输入前一天，输出后一天。
 * 思路：月份天数判断。
 * 对象：Calendar模拟日历。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Calendar
{
private:
    /***
     * 判断是否为闰年
     * 普通闰年：公历年份是4的倍数，且不是100的倍数的，为闰年（如2004年、2020年等就是闰年）。
     * 世纪闰年：公历年份是整百数的，必须是400的倍数才是闰年（如1900年不是闰年，2000年是闰年）。
     ***/
    bool IsLeap(int year)
    {
        if (year % 400 == 0)
        {
            return true;
        }
        if (year % 100 == 0)
        {
            return false;
        }
        if (year % 4 == 0)
        {
            return true;
        }
        return false;
    }

    const int MaxMonth = 12;
    map<int, string> Num2Month; // 索引转为月份。
    map<string, int> MonthDay;  // 记录每一个月的天数。

    void init()
    {
        Num2Month[1] = "Jan";
        Num2Month[2] = "Feb";
        Num2Month[3] = "Mar";
        Num2Month[4] = "Apr";
        Num2Month[5] = "May";
        Num2Month[6] = "Jun";
        Num2Month[7] = "Jul";
        Num2Month[8] = "Aug";
        Num2Month[9] = "Sep";
        Num2Month[10] = "Oct";
        Num2Month[11] = "Nov";
        Num2Month[12] = "Dec";

        MonthDay["Jan"] = 31;
        MonthDay["Feb"] = 28;
        MonthDay["Mar"] = 31;
        MonthDay["Apr"] = 30;
        MonthDay["May"] = 31;
        MonthDay["Jun"] = 30;
        MonthDay["Jul"] = 31;
        MonthDay["Aug"] = 31;
        MonthDay["Sep"] = 30;
        MonthDay["Oct"] = 31;
        MonthDay["Nov"] = 30;
        MonthDay["Dec"] = 31;
    }

public:
    Calendar()
    {
        init();
    }

    struct monthday
    {
        int month;
        int day;
    };

    /* 获取某年某月的天数。 */
    int getDaysNum(int Year, int Month)
    {
        string M = Num2Month[Month];

        if (M == "Feb" && IsLeap(Year))
        {
            return MonthDay[M] + 1;
        }

        return MonthDay[M];
    }

    /* 找出区间内的闰年（开区间）。 */
    vector<int> find_leap(int BeginYear, int EndYear)
    {
        vector<int> leap;

        rep(i, BeginYear + 1, EndYear - 1)
        {
            if (IsLeap(i))
            {
                leap.push_back(i);
            }
        }

        return leap;
    }

    /* 输入前一天，输出后一天。 */
    monthday next_day(monthday date)
    {
        if (date.day == MonthDay[Num2Month[date.month]])
        {
            int next_month = date.month + 1;
            if (next_month > MaxMonth)
            {
                next_month = 1;
            }
            return {next_month, 1};
        }
        else
        {
            return {date.month, date.day + 1};
        }
    }
};

int main()
{
    Calendar c;
    int month, day;
    cin >> month >> day;
    Calendar::monthday md = {month, day};

    Calendar::monthday nextdate = c.next_day(md);
    cout << nextdate.month << " " << nextdate.day << endl;
    return 0;
}