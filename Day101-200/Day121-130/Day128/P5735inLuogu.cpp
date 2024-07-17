/***************************************************************
 * 题目：【深基7.例1】距离函数
 * 描述：输入三个点，求出三角形的周长。
 * 思路：使用之前封装好的坐标再进一步使用。
 * 对象：Triangle用来模拟三角形。
 * 注意：注意精度。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

/* 之前封装好的坐标对象 */
class Coordinate
{
private:
    double X, Y;

public:
    Coordinate(double x, double y) : X(x), Y(y) {}

    Coordinate(pair<double, double> cor) : X(cor.first), Y(cor.second) {}

    double getDis(Coordinate &other)
    {
        double xdiff = abs(X - other.X);
        double ydiff = abs(Y - other.Y);

        return sqrt(xdiff * xdiff + ydiff * ydiff);
    }
};

/* 三角形 */
class Triangle
{
private:
    Coordinate pointA, pointB, pointC;

public:
    Triangle(Coordinate A, Coordinate B, Coordinate C)
        : pointA(A), pointB(B), pointC(C) {}

    double getPerimeter()
    {
        return pointA.getDis(pointB) +
               pointB.getDis(pointC) + pointC.getDis(pointA);
    }
};

int main()
{
    double ax, ay;
    double bx, by;
    double cx, cy;

    cin >> ax >> ay;
    Coordinate a(ax, ay);
    cin >> bx >> by;
    Coordinate b(bx, by);
    cin >> cx >> cy;
    Coordinate c(cx, cy);

    Triangle tri(a, b, c);
    cout << fixed << setprecision(2) << tri.getPerimeter() << endl;

    return 0;
}