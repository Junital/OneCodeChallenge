/*****************************************************************
 * 题目：[语言月赛 202408] 相识于 2016
 * 描述：计算两个时间点差了几个月。
 * 思路：构造，转化。
 * 对象：YearMonth模拟年月。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class YearMonth
{
private:
    int Year;                    // 年份
    int Month;                   // 月份
    const int MonthPerYear = 12; // 一年十二个月

public:
    /* 初始化，输入年份与月份。 */
    YearMonth(int Y, int M) : Year(Y), Month(M) {}

    /* 构造，计算两个时间段的差。 */
    int operator-(const YearMonth &other) const
    {
        return (Year - other.Year) * MonthPerYear + (Month - other.Month);
    }
};

int main()
{
    const YearMonth start(2016, 8);
    int year, month;

    cin >> year >> month;

    YearMonth current(year, month);
    cout << (current - start) + 1 << endl;

    return 0;
}
