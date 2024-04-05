/***********************************************
 * 题目：弹珠游戏
 * 描述：给一张地图，在某一个空位上放上弹珠，可以获得该行、该列所有的分数。
        现在想问最佳的空位以及分数。
 * 思路：多遍历一下，保存每一行、每一列的分数之和。
 * 对象：MarblesGame模拟弹珠游戏。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class MarbelsGame
{
private:
    vector<vector<ll>> GameMap;
    int MapSize;

public:
    /* 初始化，输入地图大小。 */
    MarbelsGame(int mapsize) : MapSize(mapsize)
    {
        GameMap.resize(MapSize);

        rep(i, 0, MapSize - 1)
        {
            GameMap[i].resize(MapSize);

            rep(j, 0, MapSize - 1)
            {
                cin >> GameMap[i][j];
            }
        }
    }

    /* 输出最佳的分数。 */
    ll play()
    {
        vector<ll> Row(MapSize, 0);
        vector<ll> Col(MapSize, 0);

        rep(i, 0, MapSize - 1)
        {
            rep(j, 0, MapSize - 1)
            {
                Row[i] += GameMap[i][j];
                Col[j] += GameMap[i][j];
            }
        }

        ll BestScore = -1;
        rep(i, 0, MapSize - 1)
        {
            rep(j, 0, MapSize - 1)
            {
                if (GameMap[i][j] == 0)
                {
                    BestScore = max(BestScore, Row[i] + Col[j]);
                }
            }
        }

        return BestScore;
    }
};

int main()
{
    int mapsize;
    cin >> mapsize;

    MarbelsGame mg(mapsize);

    ll bs = mg.play();

    if (bs == -1)
    {
        cout << "Bad Game!" << endl;
    }
    else
    {
        cout << bs << endl;
    }

    return 0;
}