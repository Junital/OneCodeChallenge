/**************************************************
 * 题目：【MX-X6-T0】Arcaea Scoring System
 * 描述：给Arcaea玩家评分，根据其每个物件的判定结果给出评级。
 * 思路：分段评估。
 * 对象：Arcaea模拟该游戏评分。
 * 注意：注意附加值。
 **************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class Arcaea
{
private:
    const int C_thres = 8600000;      // C级阈值
    const int B_thres = 8900000;      // B级阈值
    const int A_thres = 9200000;      // A级阈值
    const int AA_thres = 9500000;     // AA级阈值
    const int EX_thres = 9800000;     // EX级阈值
    const int EXplus_thres = 9900000; // EX+级阈值

    const int Base = 10000000;

    string rate(int score)
    {
        if (score >= EXplus_thres)
        {
            return "EX+";
        }
        else if (score >= EX_thres)
        {
            return "EX";
        }
        else if (score >= AA_thres)
        {
            return "AA";
        }
        else if (score >= A_thres)
        {
            return "A";
        }
        else if (score >= B_thres)
        {
            return "B";
        }
        else if (score >= C_thres)
        {
            return "C";
        }
        else
        {
            return "D";
        }
    }

public:
    /* 给定大Pure、小Pure、Far、Lost四种物件判定，计算分数。 */
    string judge(int BigPure, int SmallPure, int Far, int Lost)
    {
        int Sum = BigPure + SmallPure + Far + Lost;

        int base = (ll)Base * (BigPure * 2 + SmallPure * 2 + Far) / (Sum * 2);
        int supplement = BigPure;
        return rate(base + supplement);
    }
};

int main()
{
    Arcaea arc;
    int bigpure, smallpure, far, lost;
    cin >> bigpure >> smallpure >> far >> lost;

    cout << arc.judge(bigpure, smallpure, far, lost) << endl;
    return 0;
}