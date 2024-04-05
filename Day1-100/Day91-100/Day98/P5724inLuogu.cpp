/***********************************************
 * 题目：【深基4.习5】求极差 / 最大跨度值
 * 描述：输入一系列整数，输出最大值和最小值的差距。
 * 思路：模拟。
 * 对象：MaxVariance模拟极差。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class MaxVariance
{
private:
    int Num;              // 整数个数
    int MaxInt = 1 << 30; // 最大的整型
    int Variance;

public:
    /* 初始化，输入整数个数。 */
    MaxVariance(int num) : Num(num)
    {
        int MinNum = MaxInt;
        int MaxNum = 0;

        rep(i, 1, num)
        {
            int x;
            cin >> x;

            MaxNum = max(MaxNum, x);
            MinNum = min(MinNum, x);
        }

        Variance = MaxNum - MinNum;
    }

    /* 获得极差。 */
    int getVar()
    {
        return Variance;
    }
};

int main()
{
    int num;
    cin >> num;

    MaxVariance mv(num);
    cout << mv.getVar() << endl;
    return 0;
}
