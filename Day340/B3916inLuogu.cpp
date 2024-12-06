/*****************************************************************
 * 题目：[语言月赛 202401] 区间函数最大值
 * 描述：变量x，y为整数，求在一个函数中能取得的最大值。
 * 思路：遍历取最大。
 * 空间：FunctionMaximizer模拟函数最大器。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long // 定义长整型

class FunctionMaximizer
{
private:
    int A, B, C, D, E, F, G, P;

    int calculate(int x, int y)
    {
        ll xx = (x * x) % P;
        ll xxx = (xx * x) % P;
        ll yy = (y * y) % P;
        ll yyy = (yy * y) % P;
        ll xxy = (xx * y) % P;
        ll xyy = (x * yy) % P;
        ll xy = (x * y) % P;

        return ((A * xxx) % P + (B * yyy) % P + (C * xxy) % P +
                (D * xyy) % P + (E * xy) % P + (F * (ll)x) % P +
                (G * (ll)y) % P) %
               P;
    }

public:
    FunctionMaximizer(int a, int b, int c, int d, int e, int f, int g, int p)
        : A(a), B(b), C(c), D(d), E(e), F(f), G(g), P(p) {}

    int find_max(int X1, int X2, int Y1, int Y2)
    {
        int max_value = INT_MIN;
        for (int x = X1; x <= X2; ++x)
        {
            for (int y = Y1; y <= Y2; ++y)
            {
                max_value = max(max_value, calculate(x, y));
            }
        }
        return max_value;
    }
};

int main()
{
    int A, B, C, D, E, F, G, P;
    cin >> A >> B >> C >> D >> E >> F >> G >> P;

    int X1, X2, Y1, Y2;
    cin >> X1 >> X2 >> Y1 >> Y2;

    FunctionMaximizer fm(A, B, C, D, E, F, G, P);
    cout << fm.find_max(X1, X2, Y1, Y2) << endl;
    return 0;
}
