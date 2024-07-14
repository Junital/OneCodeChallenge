/*********************************************************
 * 题目：「MXOI Round 1」宝箱
 * 描述：一维坐标上移动，找宝箱。
 * 思路：贪心算法。
 * 对象：Planning1D模拟一维规划。
 * 注意：注意玩家坐标的变换。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Planning1D
{
private:
    int INIT = 0;
    const int MAXDIS = 1000; // 最大距离

public:
    /* 输入目标数组，输出最少移动次数。 */
    int Greedy(vector<int> Targets)
    {
        int player = INIT;
        int TargetNum = Targets.size();
        int ans = 0; // 最佳距离

        vector<bool> Visited(TargetNum, false);

        rep(i, 1, TargetNum)
        {
            int min_idx = -1;
            int min_dis = MAXDIS;

            rep(j, 0, TargetNum - 1)
            {
                if (!Visited[j] && abs(Targets[j] - player) < min_dis)
                {
                    min_dis = abs(Targets[j] - player);
                    min_idx = j;
                }
            }

            Visited[min_idx] = true;
            ans += min_dis;
            player = Targets[min_idx];
        }

        return ans;
    }
};

int main()
{
    Planning1D p1d;
    const int targetnum = 2;

    vector<int> targets(targetnum);
    rep(i, 0, targetnum - 1)
    {
        cin >> targets[i];
    }

    cout << p1d.Greedy(targets) << endl;
    return 0;
}
