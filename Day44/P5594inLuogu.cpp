/***********************************************
 * 题目：【XR-4】模拟赛
 * 描述：大家进行模拟赛，每天有不同的人想做不同的题，想问问需要开多少个教室。
 * 思路：用集合的思想。
 * 对象：ManageMatches用于管理比赛。
 * 注意：内存问题。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速定义循环

class ManageMatches
{
private:
    int DayNum;                   // 安排天数
    int StuNum;                   // 学生人数
    int MatchNum;                 // 模拟赛数量
    vector<set<int>> ManageTable; // 记录每天的模拟赛

public:
    /* 输出每天比赛清单 */
    vector<int> getMatchList()
    {
        vector<int> MatchNums;
        for (auto s : ManageTable)
        {
            MatchNums.push_back(s.size());
        }
        return MatchNums;
    }

    /* 初始化，输入学生人数、模拟赛数量和安排天数 */
    ManageMatches(int sn, int mn, int d) : StuNum(sn), MatchNum(mn), DayNum(d)
    {
        ManageTable.resize(DayNum);
        rep(i, 1, StuNum)
        {
            rep(j, 1, MatchNum)
            {
                int x;
                cin >> x;
                // printf("%d\n", x);
                ManageTable[x - 1].insert(j);
            }
        }
    }
};

int main()
{
    int Days, StuNum, MatchNum;
    cin >> StuNum >> MatchNum >> Days;
    ManageMatches mm(StuNum, MatchNum, Days);

    vector<int> matchlist = mm.getMatchList();

    for (auto match : matchlist)
    {
        cout << match << " ";
    }
    cout << endl;
    return 0;
}