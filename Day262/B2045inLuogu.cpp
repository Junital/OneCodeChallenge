/*****************************************************************
 * 题目：晶晶赴约会
 * 描述：晶晶每周一三五要上课，问是否能赴约某一天。
 * 思路：集合判断是否包含。
 * 函数：无。
 * 注意：判断注意取反。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    const set<int> Class = {1, 3, 5};
    int day;
    cin >> day;
    assert(day >= 1 && day <= 7);

    if (Class.count(day) > 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}
