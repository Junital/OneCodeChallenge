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
    vector<int> Floors; // 每个人想去的楼层数
    int MaxFloor;       // 想去的最高楼层

    /* 统计到达某一楼层的个数 */
    ll at(int floor)
    {
        ll sum = 0;
    }

public:
    /* 初始化，输入想上电梯的人数。 */
    Elevator(int pn) : PeoNum(pn)
    {
        MaxFloor = 0;

        rep(i, 1, PeoNum)
        {
            int x;
            cin >> x;
            Floors.push_back(x);

            MaxFloor = max(MaxFloor, x);
        }
    }

    /* 得到电梯运行的秒数。 */
    ll getRunTime()
    {
        int CurrentFloor = 0; // 目前的楼数
        ll RunTime = 0;       // 目前电梯的运行时间

        /* 上楼过程 */
        do
        {
            RunTime += 6;

            CurrentFloor++;
            if (Floors[CurrentFloor] != 0)
            {
                RunTime += 5;
                RunTime += Floors[CurrentFloor];
            }
        } while (CurrentFloor != MaxFloor);

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