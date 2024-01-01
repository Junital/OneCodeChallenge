/************************************************************
 * 题目：【深基7.例3】闰年展示
 * 要求：输入一个区间，输出这个区间中的闰年数
 * 作者：Junital
 * 思路：闰年判断
 * 对象：IsLeap判断是否为闰年，ScanYears用于扫描年份区间
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++)

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

/* 输入开始年份和结束年份，打印区间内的所有闰年 */
void ScanYears(int startyear, int endyear)
{
    vector<int> leapyears; // 存储所有闰年
    rep(i, startyear, endyear)
    {
        if (IsLeap(i))
        {
            leapyears.push_back(i);
        }
    }

    int year_num = leapyears.size(); // 闰年的数量
    cout << year_num << endl;

    rep(i, 0, year_num - 1)
    {
        cout << leapyears[i] << " ";
    }
    cout << endl;
}

int main()
{
    int start_year, end_year; // 起始年份和结束年份

    cin >> start_year >> end_year;

    ScanYears(start_year, end_year);
    return 0;
}
