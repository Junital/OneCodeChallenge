/*****************************************************************
 * 题目：[信息与未来 2017] 龟兔赛跑
 * 描述：兔子睡一会，把比赛距离设定为多少能保证乌龟能先到达终点？
 * 思路：数学计算。
 * 对象：TortoiseHare模拟龟兔赛跑。
 * 注意：提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class TortoiseHare
{
private:
public:
    /* 计算距离。 */
    int get_dis(int Tortoise, int Hare, int SleepTime)
    {
        assert(Hare > Tortoise);
        return Hare * SleepTime * Tortoise / (Hare - Tortoise);
    }
};

int main()
{
    TortoiseHare th;
    int tor, hare, st;
    cin >> tor >> hare >> st;

    cout << th.get_dis(tor, hare, st) << endl;
    return 0;
}
