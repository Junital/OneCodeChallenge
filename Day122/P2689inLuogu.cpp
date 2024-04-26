/***************************************************************
 * 题目：东南西北
 * 描述：一个人只能顺风而动，想问一下规定时间内能否顺着风向到达终点。
 * 思路：地图存储较好。
 * 对象：FollowWind模拟随风而动。
 * 注意：注意时间限制。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define MAXINT 1 << 30                            // 定义最大值

class FollowWind
{
private:
    map<pair<int, int>, int> WindMap; // 存储每个点最少几阵风可以吹到。
    const int MaxSize = 50;           // 最大吹的距离为50。
    pair<int, int> InitCor;           // 初始坐标。
    pair<int, int> EndCor;            // 终点坐标。
    int WindTime;                     // 风吹时刻。
    vector<char> WindQueue;           // 风向队列。
    int LeastMove;                    // 从起点到终点的最小移动距离。

    /* 初始化，主要将坐标周围的点都初始化一下。 */
    void init()
    {
        int minx = max(0, InitCor.first - MaxSize);
        int miny = max(0, InitCor.second - MaxSize);

        int maxx = InitCor.first + MaxSize;
        int maxy = InitCor.second + MaxSize;

        if (EndCor.first >= minx && EndCor.first <= maxx &&
            EndCor.second >= miny && EndCor.second <= maxy)
        {
            rep(i, minx, maxx)
            {
                rep(j, miny, maxy)
                {
                    WindMap[make_pair(i, j)] = MAXINT;
                }
            }

            WindMap[make_pair(InitCor.first, InitCor.second)] = 0;
        }
        else
        {
            LeastMove = -1;
        }
    }

    /* 吹风 */
    void blow(pair<int, int> offset)
    {
        int minx = max(0, InitCor.first - MaxSize);
        int miny = max(0, InitCor.second - MaxSize);

        int maxx = InitCor.first + MaxSize;
        int maxy = InitCor.second + MaxSize;

        rep(i, minx, maxx)
        {
            rep(j, miny, maxy)
            {
                if (WindMap[make_pair(i, j)] != MAXINT)
                {
                    WindMap[make_pair(i + offset.first, j + offset.second)] =
                        min(WindMap[make_pair(i + offset.first, j + offset.second)],
                            WindMap[make_pair(i, j)] + 1);
                }
            }
        }
    }

    /* 开始模拟。 */
    void mimic()
    {
        /* 如果为-1，直接输出。 */
        if (LeastMove == -1)
        {
            return;
        }

        for (auto c : WindQueue)
        {
            if (c == 'E')
            {
                blow(make_pair(1, 0));
            }
            else if (c == 'S')
            {
                blow(make_pair(0, -1));
            }
            else if (c == 'W')
            {
                blow(make_pair(-1, 0));
            }
            else if (c == 'N')
            {
                blow(make_pair(0, 1));
            }
        }

        LeastMove = WindMap[make_pair(EndCor.first, EndCor.second)];
        if (LeastMove == MAXINT)
        {
            LeastMove = -1;
        }
    }

public:
    /* 一开始输入起点和终点，和风吹时刻。 */
    FollowWind(pair<int, int> initcor, pair<int, int> endcor, int windtime)
        : InitCor(initcor), EndCor(endcor), WindTime(windtime)
    {
        WindQueue.resize(WindTime);

        rep(i, 0, WindTime - 1)
        {
            cin >> WindQueue[i];
        }

        LeastMove = MAXINT;
        init();

        /* 模拟 */
        mimic();
    }

    /* 输出最小移动步数，如果无法移动到那即为-1。 */
    int getLeastMove()
    {
        return LeastMove;
    }
};

int main()
{
    pair<int, int> initcor;
    pair<int, int> endcor;
    int windtime;

    cin >> initcor.first >> initcor.second;
    cin >> endcor.first >> endcor.second;
    cin >> windtime;

    FollowWind fw(initcor, endcor, windtime);
    cout << fw.getLeastMove() << endl;

    return 0;
}