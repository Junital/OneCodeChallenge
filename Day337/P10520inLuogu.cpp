/*****************************************************************
 * 题目：[XJTUPC2024] 榕树之心
 * 描述：将纵向坐标转化为平面直角坐标。
 * 思路：公式计算。
 * 空间：Coordinate模拟坐标。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Coordinate
{
private:
    T X, Y;

public:
    Coordinate(T x, T y) : X(x), Y(y)
    {
    }

    Coordinate(const Coordinate<T> &other)
    {
        X = other.X;
        Y = other.Y;
    }

    /* 获得距离 */
    T getDis(const Coordinate<T> &other) const
    {
        T xdiff = abs(X - other.X);
        T ydiff = abs(Y - other.Y);

        return sqrt(xdiff * xdiff + ydiff * ydiff);
    }

    /* 获得x距离。 */
    T getXDis(const Coordinate &other) const
    {
        return X - other.X;
    }

    /* 获得y距离。 */
    T getYDis(const Coordinate &other) const
    {
        return Y - other.Y;
    }

    /* 纵向转平面 */
    Coordinate<T> vertical2plane() const
    {
        T new_X = (X + Y) / 2;
        T new_Y = (X - Y) * (sqrt(3.0) / 2);

        return Coordinate<T>(new_X, new_Y);
    }

    /* 平面转纵向。 */
    Coordinate<T> plane2vertical() const
    {
        T new_X = (X + Y * (1.0 / sqrt(3.0)));
        T new_Y = (X - Y * (1.0 / sqrt(3.0)));

        return Coordinate(new_X, new_Y);
    }

    /* 打印。 */
    void print() const
    {
        cout << fixed << setprecision(7) << X << " " << Y << endl;
    }
};

int main()
{
    double x, y;
    cin >> x >> y;

    Coordinate<double> origin(x, y);

    Coordinate<double> fresh = origin.vertical2plane();
    fresh.print();
    return 0;
}