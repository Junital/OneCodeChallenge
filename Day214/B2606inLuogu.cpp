/**********************************************************
 * 题目：【深基1.例9】圆的计算
 * 描述：计算圆的面积。
 * 思路：公式计算。
 * 对象：Circle模拟圆。
 * 注意：注意输出格式。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

class Graphics
{
public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};

class Circle : public Graphics
{
private:
    double Radius;
    double Area;
    double Perimeter;
    const double pi = 3.141593;

public:
    /* 初始化，输入半径。 */
    Circle(double r) : Radius(r)
    {
        Area = pi * Radius * Radius;
        Perimeter = 2 * pi * Radius;
    }

    /* 实现面积。 */
    double getArea() override
    {
        return Area;
    }

    /* 输出周长。 */
    double getPerimeter() override
    {
        return Perimeter;
    }
};

class Sphere
{
private:
    const double pi = 3.141593; // 定义圆周率
    int Radius;                 // 半径

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
    Circle c(5);
    cout << c.getPerimeter() << endl;
    cout << c.getArea() << endl;
    Sphere s(5);
    cout << s.get_vol() << endl;
    return 0;
}
