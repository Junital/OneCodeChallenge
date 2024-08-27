/*****************************************************************
 * 题目：[GESP202312 三级] 小猫分鱼
 * 描述：每次将乘上权重并加上系数。
 * 思路：迭代+选择最优参数。
 * 函数：LinearTransform模拟线性变换。
 * 注意：数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

int LinearTransform(int Number, int Weight, int Bias)
{
    return Number * Weight + Bias;
}

int main()
{
    int People, Left;
    cin >> People >> Left;

    int Partion = 1;
    int ans;
    bool flag = false;
    while (true)
    {
        if (!flag)
        {
            flag = true;
        }
        else
        {
            break;
        }
        ans = LinearTransform(Partion, People, Left);
        // cout << ans << endl;

        rep(i, 1, People - 1)
        {
            if (ans % (People - 1) != 0)
            {
                Partion++;
                flag = false;
                break;
            }
            ans = LinearTransform(ans / (People - 1), People, Left);
        }
    }
    cout << ans << endl;
    return 0;
}