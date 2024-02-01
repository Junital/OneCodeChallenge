/***********************************************
 * 题目：【深基3.例3】闰年判断
 * 描述：输入年份，判断是否是闰年。
 * 思路：用已经写好的函数。
 * 函数：IsLeap判断年份是否是闰年。
 * 注意：覆盖所有条件。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    int Year;
    cin >> Year;

    cout << IsLeap(Year) << endl;

    return 0;
}
