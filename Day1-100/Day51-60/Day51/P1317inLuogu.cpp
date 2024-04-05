/***********************************************
 * 题目：低洼地
 * 描述：给出海拔高度，找出低洼地的个数。
 * 思路：简单统计。
 * 对象：Hollow模拟低洼地。
 * 注意：把所有情况的低洼地考虑清楚。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 用于模拟低洼地 */
class Hollow
{
private:
    vector<int> TopoChain;

public:
    /* 初始化，输入一串地形序列。 */
    Hollow(vector<int> TopoChain) : TopoChain(TopoChain)
    {
    }

    /* 计算低洼地的个数。 */
    int getHollowNum()
    {
        int N = TopoChain.size(); // 获得地形长度
        bool isDOWN = false;      // 是否已经下降
        int HollowNum = 0;        // 低洼地的个数

        rep(i, 1, N - 1)
        {
            /* 考虑下坡 */
            if (TopoChain[i] < TopoChain[i - 1])
            {
                if (!isDOWN)
                {
                    isDOWN = true;
                }
            }
            /* 考虑上坡 */
            else if (TopoChain[i] > TopoChain[i - 1])
            {
                if (isDOWN)
                {
                    HollowNum++;
                }
                isDOWN = false;
            }
        }

        return HollowNum;
    }
};

int main()
{
    int N;                 // 地形长度
    vector<int> TopoChain; // 地形序列

    cin >> N;
    rep(i, 1, N)
    {
        int x;
        cin >> x;
        TopoChain.push_back(x);
    }

    Hollow h(TopoChain);

    cout << h.getHollowNum() << endl;
}