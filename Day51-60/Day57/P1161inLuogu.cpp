/***********************************************
 * 题目：开灯
 * 描述：一排灯，让我操作开关，找到最后亮的那盏灯。
 * 思路：模拟。
 * 对象：Lights模拟一排灯。
 * 注意：模拟要清晰，注意时空限制。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

#define OFF 0
#define ON 1

/* 一排灯，可以模拟开关灯，可以找出最后亮的灯。 */
class Lights
{
private:
    int OpTime;                    // 操作次数
    vector<bitset<1>> LightsOnOFF; // 记录灯的开关状态
    const int MaxSize = 2000005;   // 灯的最长距离

    /* 用于改变灯的状态，需要输入相对位移。 */
    void LightChange(int Offset)
    {
        LightsOnOFF[Offset] = ~LightsOnOFF[Offset];
    }

public:
    /* 初始化，输入操作次数。 */
    Lights(int optime) : OpTime(optime)
    {
        LightsOnOFF.resize(MaxSize, OFF); // 默认都是关的

        rep(i, 1, OpTime)
        {
            double Step; // 移动步长
            int Time;    // 移动次数
            cin >> Step >> Time;

            rep(j, 1, Time)
            {
                int OffSet = floor(Step * j); // 获取灯的相对位置
                LightChange(OffSet);
            }
        }
    }

    /* 获取最后亮灯的位置。 */
    int getLastLight()
    {
        rep(i, 1, MaxSize)
        {
            if (LightsOnOFF[i] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    int OpTimes;
    cin >> OpTimes;

    Lights lights(OpTimes);

    cout << lights.getLastLight() << endl;
}