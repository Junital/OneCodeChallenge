/***************************************************
 * 题目：[GESP202309 三级] 小杨的储蓄
 * 描述：有N个储蓄罐，存款多次后，问每个储蓄罐的钱。
 * 思路：数组相加。
 * 对象：无。
 * 注意：注意提高可拓展性。
 ***************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

int main()
{
    int num, day;
    cin >> num >> day;

    vector<int> jars(num);

    rep(i, 1, day)
    {
        int idx;
        cin >> idx;
        assert(idx >= 0 && idx < num);
        jars[idx] += i;
    }

    rep(i, 0, num - 1)
    {
        cout << jars[i] << " ";
    }
    cout << endl;
    return 0;
}