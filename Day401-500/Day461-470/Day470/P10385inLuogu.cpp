/*****************************************************************
 * 题目：[蓝桥杯 2024 省 A] 艺术与篮球
 * 描述：根据汉字的笔画确定每天做什么。
 * 思路：模拟日历。
 * 对象：Calendar模拟日历。
 * 注意：注意加入一些可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
    /* 四舍五入 */
    int Approximate(double Num)
    {
        double Ceil = ceil(Num);
        double Floor = floor(Num);

        if (Ceil - Num <= Num - Floor)
        {
            return (int)Ceil;
        }
        else
        {
            return (int)Floor;
        }
    }
};

using namespace Tools;

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
    monthday next_day(int year, monthday date)
    {
        if (date.day == getDaysNum(year, date.month))
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

    // 输出指定日期区间的 YYYYMMDD 格式字符串
    vector<string> get_dates_in_range(int startYear, monthday startDate, int endYear, monthday endDate)
    {
        vector<string> dates;

        int currentYear = startYear;
        monthday currentDate = startDate;

        while (currentYear < endYear || (currentYear == endYear && (currentDate.month < endDate.month || (currentDate.month == endDate.month && currentDate.day <= endDate.day))))
        {
            string dateStr = to_string(currentYear);
            if (currentDate.month < 10)
            {
                dateStr += "0";
            }
            dateStr += to_string(currentDate.month);
            if (currentDate.day < 10)
            {
                dateStr += "0";
            }
            dateStr += to_string(currentDate.day);

            dates.push_back(dateStr);

            currentDate = next_day(currentYear, currentDate);
            if (currentDate.month == 1 && currentDate.day == 1)
            {
                currentYear++;
            }
        }

        return dates;
    }
};

int main()
{
    const map<char, int> Digit2Stroke = {
        {'0', 13},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 5},
        {'5', 4},
        {'6', 4},
        {'7', 2},
        {'8', 2},
        {'9', 2}};
    const int threshold = 50;

    Calendar cal;
    Calendar::monthday startDate = {1, 1};
    Calendar::monthday endDate = {4, 13};
    std::vector<std::string> dates = cal.get_dates_in_range(2000, startDate, 2024, endDate);

    int basketball = 0;
    int calligraphy = 0;
    for (const auto &date : dates)
    {
        int cnt = 0;
        for (auto digit : date)
        {
            auto it = Digit2Stroke.find(digit);
            if (it != Digit2Stroke.end())
            {
                cnt += it->second;
            }
        }

        if (cnt > threshold)
        {
            basketball++;
        }
        else
        {
            calligraphy++;
        }
    }

    cout << basketball << endl;
    return 0;
}