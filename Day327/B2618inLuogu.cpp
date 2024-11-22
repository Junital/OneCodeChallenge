/*****************************************************************
 * 题目：【深基2.例3】玩橡皮泥
 * 描述：两个球形橡皮泥，塑造一个正方体。
 * 思路：构造三维立体。
 * 对象：Sphere模拟球体，Cube模拟立方体。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class ThreeDimension
{
private:
public:
    virtual double get_vol() = 0;  // 体积
    virtual double get_surf() = 0; // 表面积
};

class Sphere : public ThreeDimension
{
private:
    const double pi = 3.141593; // 定义圆周率
    double Radius;              // 半径

public:
    /* 初始化，输入半径。 */
    Sphere(double r) : Radius(r) {}

    /* 计算体积。 */
    double get_vol() override
    {
        return 4.0 / 3 * pi * Radius * Radius * Radius;
    }

    /* 计算表面积。 */
    double get_surf() override
    {
        return 4.0 * pi * Radius * Radius;
    }
};

class Cube : public ThreeDimension
{
private:
    double Edge;

public:
    /* 初始化，输入边长。 */
    Cube(double e) : Edge(e) {}

    /* 通过体积初始化 */
    Cube(double volume, bool is_volume)
    {
        if (is_volume)
        {
            Edge = cbrt(volume); // 计算边长
        }
        else
        {
            Edge = volume; // 直接当作边长
        }
    }

    /* 获取边长 */
    double getEdge() const
    {
        return Edge;
    }

    /* 计算体积。 */
    double get_vol() override
    {
        return Edge * Edge * Edge;
    }

    /* 计算表面积。 */
    double get_surf() override
    {
        return 6 * Edge * Edge;
    }
};

int main()
{
    double A = Sphere(4).get_vol();
    double B = Sphere(10).get_vol();

    double C = A + B;
    int edge = Cube(C, true).getEdge();

    cout << edge << endl;
    return 0;
}