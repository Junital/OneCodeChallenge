/***************************************************************
 * 题目：小玉家的电费
 * 描述：计算电费。
 * 思路：分段计算。
 * 对象：ElecFee模拟电费。
 * 注意：保证精度。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ElecFee
{
private:
    const int Level1Limit = 150;
    const double Level1Fee = 0.4463;
    const int Level2Limit = 400;
    const double Level2Fee = 0.4663;
    const double Level3Fee = 0.5663;

public:
    /* 输入电力，输出电费。 */
    double charge(int Elec)
    {
        double fee = 0;
        fee += (min(Elec, Level1Limit) * Level1Fee);

        if (Elec > Level1Limit)
        {
            fee += ((min(Elec, Level2Limit) - Level1Limit) * Level2Fee);
        }

        if (Elec > Level2Limit)
        {
            fee += ((Elec - Level2Limit) * Level3Fee);
        }

        return fee;
    }
};

int main()
{
    ElecFee ef;

    int elec;
    cin >> elec;

    cout << fixed << setprecision(1) << ef.charge(elec) << endl;
    return 0;
}