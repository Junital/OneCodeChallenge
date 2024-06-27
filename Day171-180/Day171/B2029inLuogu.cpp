/**********************************************************
 * 题目：大象喝水
 * 描述：计算圆柱体的体积，求出20升水需要几个圆柱体。
 * 思路：换算，计算体积，整除取上。
 * 对象：Cylinder模拟圆柱体。
 * 注意：封装好，增加拓展性；换算单位。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Cylinder
{
private:
    int Radius;             // 半径
    int Height;             // 高
    const double pi = 3.14; // 圆周率

public:
    /* 输入半径，高 */
    Cylinder(int r, int h) : Radius(r), Height(h) {}

    /* 计算体积 */
    double get_vol()
    {
        return Radius * Radius * pi * Height;
    }
};

int main()
{
    const double Elephant = 2e4;

    int radius, height;
    cin >> height >> radius;

    Cylinder c(radius, height);
    cout << ceil(Elephant / c.get_vol()) << endl;
}
