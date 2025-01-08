/*****************************************************************
 * 题目：[ROIR 2018 Day1] 提高成绩
 * 描述：问需要多少5分才能拉高平均分。
 * 思路：代入公式。
 * 对象：无
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long // 定义快速循环

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

/* 四舍五入（变式） */
template <typename T>
T Approximate(T Numer, T Deno)
{
    T Floor = Numer / Deno;

    if ((Numer - Floor * Deno) * 2 < Deno)
    {
        return Floor;
    }
    else
    {
        return Floor + 1;
    }
}

/* 取上（变式） */
template <typename T>
T Ceil(T Numer, T Deno)
{
    T Floor = Numer / Deno;

    if ((Numer - Floor * Deno) == 0)
    {
        return Floor;
    }
    else
    {
        return Floor + 1;
    }
}

int main()
{
    map<int, ll> NumMap;
    cin >> NumMap[2] >> NumMap[3] >> NumMap[4];

    ll sum = 0;
    ll num = 0;
    for (auto pil : NumMap)
    {
        sum += pil.first * pil.second;
        num += pil.second;
    }

    if (Approximate(sum, num) == 4)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << Ceil(7 * num - 2 * sum, (ll)3) << endl;
    }
    return 0;
}