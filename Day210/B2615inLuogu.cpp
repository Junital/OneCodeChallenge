/**********************************************************
 * 题目：【深基1.习7】定期存款
 * 描述：计算银行利率。
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
    int base = 10000;
    const double one_rate = 0.035;
    const double five_rate = 0.04;

    Increase One(one_rate);
    Increase Five(five_rate);

    cout << One.simulate(base, 5) << " " << base + base * five_rate * 5 << endl;
    return 0;
}
