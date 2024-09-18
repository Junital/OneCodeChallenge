/*****************************************************************
 * 题目：[语言月赛 202409] 重聚
 * 描述：判断需要多久就能找数值大于等于该数。
 * 思路：二分搜索。
 * 对象：WaitforValue模拟等待数值。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class WaitforValue
{
private:
    vector<pair<int, int>> value_time;

public:
    /* 初始化，输入一个<值,时间>数组。 */
    WaitforValue(vector<pair<int, int>> arr) : value_time(arr)
    {
        sort(value_time.begin(), value_time.end());
    }

    /* 根据一个键值和时间判断需要等多久。 */
    int solve(pair<int, int> query)
    {
        auto res = lower_bound(value_time.begin(), value_time.end(),
                               query.first,
                               [](const std::pair<int, int> &a, int value)
                               {
                                   return a.first < value; // 按照 first 值进行比较
                               });
        if (res == value_time.end())
        {
            return -1;
        }
        // cout << (*res).first << endl;
        return max(0, (*res).second - query.second);
    }
};

int main()
{
    pair<int, int> query;
    cin >> query.second >> query.first;

    const int num = 2;
    vector<pair<int, int>> arr(num);

    rep(i, 0, num - 1)
    {
        cin >> arr[i].second >> arr[i].first;
    }

    WaitforValue wv(arr);
    cout << wv.solve(query) << endl;
    return 0;
}
