/***************************************************************
 * 题目：【深基3.例9】月份天数
 * 描述：问某一年某一月有几天。
 * 思路：常识题，用之前封装好的闰年判断函数。
 * 对象：Calendar模拟日历。
 * 注意：注意闰年。
 **************************************************************/

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
};

int main()
{
    Calendar c;
    int year, month;

    cin >> year >> month;
    cout << c.getDaysNum(year, month);

    return 0;
}