/**********************************************************
 * 题目：小鱼会有危险吗
 * 描述：小鱼游每次是前一秒的98%，然后有一个探测器所在位置
        以及对应的检测范围，问小鱼能否在检测器检测到时快速逃出检测范围。
 * 思路：模拟。
 * 对象：FishEscape模拟逃走的小鱼。
 * 注意：注意浮点数精度。
 *********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class FishEscape
{
private:
    double Detector;           // 检测器的位置。
    double DetectRange;        // 检测器的检测范围。
    const double InitPace = 7; // 小鱼的初始步长

public:
    /* 初始化，输入探测器位置和范围。 */
    FishEscape(double detector,
               double detectrange) : Detector(detector),
                                     DetectRange(detectrange)
    {
    }

    /* 判断小鱼是否能顺利逃脱。 */
    bool JudgeEscape()
    {
        double Pace = 7;
        double LeftThres = Detector - DetectRange;
        double RightThres = Detector + DetectRange;

        double Dis = 0;
        while (Dis < RightThres)
        {
            // cout << Dis << " ";
            Dis += Pace;
            Pace *= 0.98;

            if (Dis >= LeftThres && Dis + Pace <= RightThres)
            {
                return false;
            }
        }
        // cout << endl;

        return true;
    }
};

int main()
{
    double detector, detectrange;
    cin >> detector >> detectrange;

    FishEscape fe(detector, detectrange);

    if (fe.JudgeEscape())
    {
        cout << "n" << endl;
    }
    else
    {
        cout << "y" << endl;
    }

    return 0;
}
