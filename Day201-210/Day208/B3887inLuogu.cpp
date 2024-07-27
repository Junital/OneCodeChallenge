/***********************************************
 * 题目：[语言月赛 202311] 风球
 * 描述：根据每个气象站计算得到的风力判断飓风等级。
 * 思路：分级判断，很难拓展。
 * 对象：Hurricane模拟飓风。
 * 注意：用排序+查找优化。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

struct WindLevel
{
    int idx;        // 风力等级
    int wind_thres; // 风力阈值
    int num_thres;  // 数量阈值
};

class Hurricane
{
private:
    const int StationNum = 8;
    const vector<WindLevel> Levels = {{3, 41, 4}, {8, 63, 4}, {10, 118, 1}};

public:
    int judge(vector<int> Stations)
    {
        int arrsize = Stations.size();
        assert(arrsize == StationNum);

        int res = 1;
        sort(Stations.begin(), Stations.end());

        for (auto l : Levels)
        {
            if (lower_bound(Stations.begin(), Stations.end(), l.wind_thres) -
                    Stations.begin() <=
                StationNum - l.num_thres)
            {
                res = l.idx;
            }
        }

        return res;
    }
};

int main()
{
    const int station_num = 8;
    vector<int> stations(station_num);
    Hurricane h;

    rep(i, 0, station_num - 1)
    {
        cin >> stations[i];
    }

    cout << h.judge(stations) << endl;
    return 0;
}
