/*****************************************************************
 * 题目：[语言月赛 202502] 披萨订单
 * 描述：问怎么从区间内选效果最好的数字。
 * 思路：遍历。
 * 空间：Tools模拟便携式工具。
 * 注意：数据范围、时间复杂度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

namespace Iterations
{
    struct Interval
    {
        int begin;
        int end;
    };

    vector<vector<int>> IterationResults; // 为了提升时间复杂度，这里存储结果。

    void backtrack(
        const vector<Interval> &intervals,
        vector<int> &current,
        int depth = 0)
    {
        if (depth == intervals.size())
        {
            IterationResults.push_back(current);
            return;
        }

        for (int num = intervals[depth].begin;
             num <= intervals[depth].end; num++)
        {
            current.push_back(num);
            backtrack(intervals, current, depth + 1);
            current.pop_back();
        }
    }

    /* 获取所有排列组合。 */
    void get_all_combinations(const vector<Interval> &intervals)
    {
        IterationResults.clear();
        vector<int> current;
        backtrack(intervals, current);
    }
};

using namespace Iterations;

int main()
{
    int end1, end2, end3;

    cin >> end1 >> end2 >> end3;
    // get_all_combinations({{0, end1},
    //                       {1, end2},
    //                       {0, end3}});

    int max_delicious = -1;
    int delicious_cnt = 0;
    rep(i, 0, end1)
    {
        rep(j, 1, end2)
        {
            rep(k, 0, end3)
            {
                int delicious = (i + j) ^ k;
                if (delicious > max_delicious)
                {
                    max_delicious = delicious;
                    delicious_cnt = 1;
                }
                else if (delicious == max_delicious)
                {
                    delicious_cnt++;
                }
            }
        }
    }

    cout << max_delicious << endl;
    cout << delicious_cnt << endl;
    return 0;
}