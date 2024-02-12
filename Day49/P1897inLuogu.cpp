/***********************************************
 * 题目：电梯里的尴尬
 * 描述：输入人想去的楼层，统计电梯需要运行的秒数。
 * 思路：模拟。
 * 对象：Elevator模拟电梯。
 * 注意：结果小心别溢出。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class Elevator
{
private:
    int PeoNum;
    map<int, int> Floors; // 每个楼层要去的人数
    int MaxFloor;         // 想去的最高楼层

public:
    /* 初始化，输入想上电梯的人数。 */
    Elevator(int pn) : PeoNum(pn)
    {
        MaxFloor = 0;

        rep(i, 1, PeoNum)
        {
            int x;
            cin >> x;
            Floors[x]++;

            MaxFloor = max(MaxFloor, x);
        }
    }

    /* 得到电梯运行的秒数。 */
    ll getRunTime()
    {
        int CurrentFloor = 0; // 目前的楼数
        ll RunTime = 0;       // 目前电梯的运行时间

        /* 上楼过程 */
        for (auto p : Floors)
        {
            int floor = p.first;   // 楼层数
            int people = p.second; // 人数

            RunTime += (ll)6 * (floor - CurrentFloor);
            RunTime += ((ll)5 + people);

            CurrentFloor = floor;
        }

        /* 下楼过程 */
        RunTime += (ll)4 * MaxFloor;

        return RunTime;
    }
};

int main()
{
    int N;
    cin >> N;

    Elevator e(N);

    cout << e.getRunTime() << endl;
    return 0;
}