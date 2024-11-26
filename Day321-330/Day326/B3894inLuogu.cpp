/*****************************************************************
 * 题目：[NICA #3] 开车旅行
 * 描述：多个路段开车，求出路程和平均时速。
 * 思路：初始化构造新旅途。
 * 对象：RoadsDrive模拟公路开车。
 * 注意：注意可拓展性，小心数据溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class RoadsDrive
{
private:
    vector<double> Speeds;
    vector<double> Times;

    double TotDis;
    double AvgSpeed;
    double TotTime;

public:
    /* 初始化输入速度和时间。 */
    RoadsDrive(vector<double> speeds, vector<double> times)
        : Speeds(speeds), Times(times)
    {
        assert(Speeds.size() == Times.size());
        TotDis = 0;
        TotTime = 0;
        int size = Speeds.size();

        rep(i, 0, size - 1)
        {
            TotTime += Times[i];
            TotDis += Times[i] * Speeds[i];
        }

        AvgSpeed = TotDis / TotTime;
    }

    /* 获取总路程。 */
    double get_total_distance()
    {
        return TotDis;
    }

    /* 获取平均速度。 */
    double get_average_speed()
    {
        return AvgSpeed;
    }
};

int main()
{
    const int size = 2;
    vector<double> speeds(size);
    vector<double> times(size);

    rep(i, 0, size - 1)
    {
        cin >> speeds[i];
        cin >> times[i];
    }

    RoadsDrive rd(speeds, times);
    cout << fixed << setprecision(1) << rd.get_total_distance() << endl;
    cout << fixed << setprecision(1) << rd.get_average_speed() << endl;
    return 0;
}
