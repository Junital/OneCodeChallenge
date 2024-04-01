/***********************************************
 * 题目：[MtOI2019] 黑蚊子多
 * 描述：每次向上跳指定台阶，在某些特殊台阶会提升跳跃能力，问最后什么时候到达顶部。
 * 思路：模拟。
 * 对象：MagicSteps模拟台阶。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class MagicSteps
{
private:
    set<int> MagicStepSet; // 提升弹跳力的台阶
    int AllStepNum;        // 所有台阶数量
    int Stride;            // 一次跨越的台阶数量
    int MagicStepNum;      // 魔法台阶的数量

    int CostTime;

    /* 模拟。 */
    void Simulate()
    {
        CostTime = 0;
        int CurrentStep = 0;

        while (CurrentStep < AllStepNum)
        {
            if (MagicStepSet.count(CurrentStep) > 0)
            {
                Stride++;
            }

            CurrentStep += Stride;
            CostTime++;
        }
    }

public:
    /* 初始化，输入所有台阶数量、一次跨越的台阶数量、魔法台阶数量。 */
    MagicSteps(int allstepnum, int stride, int magicstepnum)
        : AllStepNum(allstepnum), Stride(stride), MagicStepNum(magicstepnum)
    {
        rep(i, 1, MagicStepNum)
        {
            int stepIdx;
            cin >> stepIdx;

            MagicStepSet.insert(stepIdx);
        }

        Simulate();
    }

    /* 获得耗费时间。 */
    int getCostTime()
    {
        return CostTime;
    }
};

int main()
{
    int allstepnum, stride, magicstepnum;

    cin >> allstepnum >> stride >> magicstepnum;

    MagicSteps ms(allstepnum, stride, magicstepnum);

    cout << ms.getCostTime() << endl;

    return 0;
}