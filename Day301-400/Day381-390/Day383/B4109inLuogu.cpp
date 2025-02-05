/*****************************************************************
 * 题目：[JOI2025 预选赛 R1H1] 散步
 * 描述：向前，向后走，问最后走到哪里。
 * 思路：运用取模。
 * 对象：PeriodicChange模拟周期变化。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class PeriodicChange
{
private:
    vector<int> Period;
    int PeriodSize;
    vector<int> PrefixSum; // 前缀和。
    int TotalSum;

    void init()
    {
        PrefixSum.resize(0);

        int sum = 0;
        rep(i, 0, PeriodSize - 1)
        {
            PrefixSum.push_back(sum);
            sum += Period[i];
        }

        TotalSum = sum;
    }

public:
    PeriodicChange(vector<int> period) : Period(period)
    {
        PeriodSize = Period.size();
        init();
    }

    /* 请求，输入x，输出这时候的值。 */
    int query(int x)
    {
        return x / PeriodSize * TotalSum +
               PrefixSum[x % PeriodSize];
    }
};

int main()
{
    const vector<int> period = {3, -2};
    PeriodicChange pc(period);

    int x;
    cin >> x;
    cout << pc.query(x) << endl;
    return 0;
}