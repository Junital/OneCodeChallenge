/**********************************************************
 * 题目：人口增长问题
 * 描述：计算基数在增长率下会提升到多少。
 * 思路：幂指数。
 * 对象：Increase模拟增长。
 * 注意：注意精度。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Increase
{
private:
    double Rate; // 增长率

public:
    /* 初始化，输入增长率 */
    Increase(double rate) : Rate(rate)
    {
        assert(rate < 1);
    }

    /* 输入基数、步长进行模拟。 */
    double simulate(int base, int step)
    {
        double total_rate = pow(Rate + 1, step);

        return base * total_rate;
    }
};

int main()
{
    double rate = 0.001;
    Increase inc(rate);

    int base, step;
    cin >> base >> step;

    cout << fixed << setprecision(4) << inc.simulate(base, step) << endl;
    return 0;
}
