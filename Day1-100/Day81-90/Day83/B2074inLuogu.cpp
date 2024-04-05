/***********************************************
 * 题目：计算星期几
 * 描述：今天是星期日，请问过了a^b天后是星期几。
 * 思路：快速幂。
 * 对象：Weekday模拟星期。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class WeekDay
{
private:
    const int DayNum = 7; // 一周只有七天

    /* 快速幂 */
    int binpow(int a, int b)
    {
        long long res = 1;
        while (b > 0)
        {
            if (b & 1)
                res = res * a % DayNum;
            a = a * a % DayNum;
            b >>= 1;
        }
        return res;
    }

    /* 根据余数选择星期几。 */
    string choose_weekday(int idx)
    {
        if (idx == 0)
        {
            return "Sunday";
        }
        else if (idx == 1)
        {
            return "Monday";
        }
        else if (idx == 2)
        {
            return "Tuesday";
        }
        else if (idx == 3)
        {
            return "Wednesday";
        }
        else if (idx == 4)
        {
            return "Thursday";
        }
        else if (idx == 5)
        {
            return "Friday";
        }
        else if (idx == 6)
        {
            return "Saturday";
        }

        return "Wrong Answer!!";
    }

public:
    WeekDay(int a, int b)
    {
        cout << this->choose_weekday(this->binpow(a, b)) << endl;
    }
};

int main()
{
    int a, b;
    cin >> a >> b;

    WeekDay wd(a, b);

    return 0;
}