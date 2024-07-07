/*********************************************************
 * 题目：[NICA #2] 降雨量
 * 描述：通过数据范围判断雨的等级。
 * 思路：简单数学判断。
 * 函数：Rainfall模拟降雨量。
 * 注意：注意封装完善。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Rainfall
{
private:
public:
    /* 判断降雨量的等级。 */
    void JudgeLevel(int rainfall)
    {
        assert(rainfall >= 0);
        if (rainfall < 10)
        {
            cout << "Drizzle" << endl;
        }
        else if (rainfall < 25)
        {
            cout << "Moderate Rain" << endl;
        }
        else if (rainfall < 50)
        {
            cout << "Heavy Rain" << endl;
        }
        else
        {
            cout << "Torrential Rain" << endl;
        }
    }

    /* 判断短时强降雨 */
    bool isFlashHeavyRain(int rainfall)
    {
        return rainfall >= 20;
    }
};

int main()
{
    Rainfall r;

    int rainfall, hour;
    cin >> rainfall >> hour;

    r.JudgeLevel(rainfall);
    if (hour == 1)
    {
        if (r.isFlashHeavyRain(rainfall))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
