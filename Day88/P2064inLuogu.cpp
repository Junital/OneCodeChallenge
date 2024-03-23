/***********************************************
 * 题目：奇妙的汽车
 * 描述：每天行驶的公里数都是前一天的2~9倍，请问能否刚好行驶完某个距离。
 * 思路：打个表。
 * 对象：MagicCar模拟汽车。
 * 注意：暂时无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义倒置循环

class MagicCar
{
private:
public:
    int Drive(int Distance)
    {
        queue<int> q;
        rep(i, 1, Distance)
        {
            if (Distance % i == 0)
            {
                q.push(Distance / i);
            }
        }
        q.push(0);

        int Days = 2;
        while (!q.empty())
        {
            int element = q.front(); // 拿到队列第一个
            q.pop();
            if (element == 0)
            {
                Days++;
                if (q.empty()) // 判断目前是否还有元素可以进入下一轮
                {
                    break;
                }
                else
                {
                    q.push(0);
                }
            }
            else if (element - 1 < 2)
            {
                continue;
            }
            else if (element - 1 <= 10)
            {
                if (Days == 1)
                {
                    continue;
                }
                else
                {
                    return Days;
                }
            }
            else
            {
                element--;
                rep(i, 2, 9)
                {
                    if (element % i == 0)
                    {
                        // cout << i << endl;
                        q.push(element / i);
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    MagicCar mc;

    int Dis;
    cin >> Dis;

    cout << mc.Drive(Dis) << endl;

    return 0;
}