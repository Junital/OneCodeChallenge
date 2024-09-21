/*****************************************************************
 * 题目：求一元二次方程
 * 描述：求解一元二次方程。
 * 思路：公式求解。
 * 对象：UnaryQuadraticEquation模拟一元二次方程。
 * 注意：注意输出样式。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class UnaryQuadraticEquation
{
private:
    double A, B, C; // 二次项、一次项和常数项。

public:
    /* 初始化，输入三个系数。 */
    UnaryQuadraticEquation(double a, double b, double c)
        : A(a), B(b), C(c) {}

    /* 求解。 */
    void solve()
    {
        double fake_real = B * B - 4 * A * C;

        if (fake_real < 0)
        {
            cout << "No answer!" << endl;
            return;
        }

        double separate = sqrt(fake_real);

        if (separate == 0.0)
        {
            double ans = (-B) / (2 * A);
            cout << "x1=x2=" << fixed
                 << setprecision(5) << ans << endl;
        }
        else
        {
            double x1 = (-B + separate) / (2 * A);
            double x2 = (-B - separate) / (2 * A);
            cout << fixed << setprecision(5)
                 << "x1=" << min(x1, x2) << ";" << "x2=" << max(x1, x2)
                 << endl;
        }
    }
};

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    UnaryQuadraticEquation uqe(a, b, c);

    uqe.solve();
    return 0;
}
