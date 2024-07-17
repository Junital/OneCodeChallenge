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
#define ld long double                            // 定义长浮点

class FishEscape
{
private:
    ld Detector;                  // 检测器的位置。
    ld DetectRange;               // 检测器的检测范围。
    const ld InitPace = 7;        // 小鱼的初始步长
    const ld DecreaseRate = 0.98; // 每次减小的比例

public:
    /* 初始化，输入探测器位置和范围。 */
    FishEscape(ld detector,
               ld detectrange) : Detector(detector),
                                 DetectRange(detectrange)
    {
    }

    /* 判断小鱼是否能顺利逃脱。 */
    bool JudgeEscape()
    {
        ld Pace = InitPace;
        ld LeftThres = Detector - DetectRange;
        ld RightThres = Detector + DetectRange;

        ld Dis = 0;
        while (Dis <= RightThres)
        {
            // cout << Dis << " ";
            if (Dis >= LeftThres && Dis + Pace <= RightThres) // 可能是这里，应该先判断
            {
                return false;
            }

            Dis += Pace;
            Pace *= DecreaseRate;
        }
        // cout << endl;

        return true;
    }
};

int main()
{
    ld detector, detectrange;
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
