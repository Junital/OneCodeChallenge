/*********************************************************
 * 题目：「MXOI Round 2」酒店
 * 描述：尽量让大家不相邻居住。
 * 思路：偶数起点为4，奇数起点为2。
 * 对象：RoundNeighbor模拟圆形邻居。
 * 注意：考虑逻辑完备性。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

class RoundNeighbor
{
private:
    const int OddBase = 1;
    const int EvenBase = 2;

public:
    /* 输入需要占用的个数和总位置数，输出最少的邻接关系个数。 */
    int CalNeighbor(int Occupy, int Total)
    {
        assert(Occupy <= Total);

        if (Occupy * 2 <= Total)
        {
            return 0;
        }

        if (Total % 2 == 0)
        {
            return EvenBase + 2 * (Occupy - Total / 2 - 1);
        }
        else
        {
            return OddBase + 2 * (Occupy - Total / 2 - 1);
        }
    }
};

int main()
{
    RoundNeighbor rn;
    int occupy, total;
    cin >> occupy >> total;

    cout << 2 * rn.CalNeighbor(occupy, total) << endl; // 怒气值为邻接数*2
    return 0;
}
