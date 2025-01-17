/*****************************************************************
 * 题目：[语言月赛 202412] 聪明猪猪大赛
 * 描述：问今年举办多少比赛。
 * 思路：简单比较。
 * 对象：无。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

struct match
{
    int start_year;
    int matches_per_year;
};

int main()
{
    match icpc, ccpc;
    cin >> icpc.start_year >> icpc.matches_per_year;
    cin >> ccpc.start_year >> ccpc.matches_per_year;

    int query_year;
    cin >> query_year;

    int count = 0;
    if (query_year >= icpc.start_year)
    {
        count += icpc.matches_per_year;
    }
    if (query_year >= ccpc.start_year)
    {
        count += ccpc.matches_per_year;
    }
    cout << count << endl;
    return 0;
}