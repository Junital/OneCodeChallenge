/*****************************************************************
 * 题目：[语言月赛202209] 公园门票
 * 描述：套票90元，成人60元，儿童40元。问最少需要多少钱。
 * 思路：动态规划的思路。
 * 对象：Ticket模拟门票。
 * 注意：最好提升可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Ticket
{
private:
    const int MaxQueryNum = 100; // DP数组，行为成人、列为小孩
    const int MAXN = 1e6;
    vector<vector<int>> QueryMap;
    struct SetPrice
    {
        int adult_num;
        int child_num;
        int price;
    };
    const vector<SetPrice> Sets = {{1, 0, 60}, {0, 1, 40}, {1, 1, 90}};

    void init()
    {
        QueryMap.resize(MaxQueryNum + 1);
        rep(i, 0, MaxQueryNum)
        {
            QueryMap[i].resize(MaxQueryNum + 1, MAXN);
            rep(j, 0, MaxQueryNum)
            {
                if (i == 0 && j == 0)
                {
                    QueryMap[i][j] = 0;
                }
                for (auto s : Sets)
                {
                    if (i - s.adult_num >= 0 && j - s.child_num >= 0)
                    {
                        QueryMap[i][j] = min(QueryMap[i][j], QueryMap[i - s.adult_num][j - s.child_num] + s.price);
                    }
                }
            }
        }
    }

public:
    Ticket()
    {
        init();
    }

    /* 输入成人人数和小孩人数，输出最少价格。 */
    int query(int AdultNum, int ChildNum)
    {
        assert(AdultNum <= MaxQueryNum && ChildNum <= MaxQueryNum);
        return QueryMap[AdultNum][ChildNum];
    }
};

int main()
{
    Ticket t;
    int adultnum, childnum;
    cin >> adultnum >> childnum;
    cout << t.query(adultnum, childnum) << endl;
    return 0;
}