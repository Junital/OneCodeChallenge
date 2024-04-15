/***********************************************
 * 题目：计算线段长度
 * 描述：给定两个坐标，输出之间的距离。
 * 思路：sqrt。
 * 对象：Coordinate模拟坐标。
 * 注意：注意精度，保留小数点三位。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

class Coordinate
{
private:
    double X, Y;

public:
    Coordinate(double x, double y) : X(x), Y(y)
    {
    }

    double getDis(Coordinate &other)
    {
        double xdiff = abs(X - other.X);
        double ydiff = abs(Y - other.Y);

        return sqrt(xdiff * xdiff + ydiff * ydiff);
    }
};

int main()
{
    double xa, ya;
    cin >> xa >> ya;
    Coordinate A(xa, ya);

    double xb, yb;
    cin >> xb >> yb;
    Coordinate B(xb, yb);

    cout << fixed << setprecision(3) << A.getDis(B) << endl;
    return 0;
}