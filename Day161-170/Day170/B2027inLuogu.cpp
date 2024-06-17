/**********************************************************
 * 题目：计算球的体积
 * 描述：给定球的半径，计算其体积。
 * 思路：公式。
 * 对象：Sphere模拟球体。
 * 注意：封装好，增加拓展性。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Sphere
{
private:
    const double pi = 3.14; // 定义圆周率
    int Radius;             // 半径

public:
    /* 初始化，输入半径。 */
    Sphere(int r) : Radius(r) {}

    /* 计算体积。 */
    double get_vol()
    {
        return 4.0 / 3 * pi * Radius * Radius * Radius;
    }
};

int main()
{
    int radius;
    cin >> radius;

    Sphere s(radius);
    cout << fixed << setprecision(5) << s.get_vol() << endl;
}
