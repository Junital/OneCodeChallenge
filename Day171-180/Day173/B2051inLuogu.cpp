/**********************************************************
 * 题目：点和正方形的关系
 * 描述：判断一个点是否在正方形内。
 * 思路：范围确定
 * 函数：printAbs输出绝对值。
 * 注意：注意精度。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

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

    /* 比较x轴坐标，如果小输出<0，如果一样输出=0，如果大输出>0 */
    double JudgeX(Coordinate &other)
    {
        return X - other.X;
    }

    /* 比较y轴坐标，如果小输出<0，如果一样输出=0，如果大输出>0 */
    double JudgeY(Coordinate &other)
    {
        return Y - other.Y;
    }
};

class Graphics
{
private:
    Coordinate Center;

public:
    virtual ll getArea() = 0;
    virtual bool inShape(Coordinate) = 0;

    Graphics(double center_x, double center_y)
        : Center(center_x, center_y) {}
};

class Square : public Graphics
{
private:
    int Len;
    Coordinate lefttop;
    Coordinate righttop;
    Coordinate leftbottom;
    Coordinate rightbottom;
    ll Area;

public:
    /* 初始化，输入边长。 */
    Square(int len, double center_x, double center_y)
        : Graphics(center_x, center_y), Len(len),
          lefttop(center_x - len / 2.0, center_y + len / 2.0),
          righttop(center_x + len / 2.0, center_y + len / 2.0),
          leftbottom(center_x - len / 2.0, center_y - len / 2.0),
          rightbottom(center_x + len / 2.0, center_y - len / 2.0)
    {
        Area = (ll)Len * Len;
    }

    /* 实现面积。 */
    ll getArea() override
    {
        return Area;
    }

    /* 判断坐标是否在图形内。 */
    bool inShape(Coordinate Point)
    {
        return lefttop.JudgeX(Point) <= 0 &&
               righttop.JudgeX(Point) >= 0 &&
               lefttop.JudgeY(Point) >= 0 &&
               leftbottom.JudgeY(Point) <= 0;
    }
};

class Rectangle : public Graphics
{
private:
    int Len;
    int Width;
    Coordinate lefttop;
    Coordinate righttop;
    Coordinate leftbottom;
    Coordinate rightbottom;
    ll Area;

public:
    /* 初始化，输入边长。 */
    Rectangle(int len, int wid, double center_x, double center_y)
        : Graphics(center_x, center_y), Len(len), Width(wid),
          lefttop(center_x - len / 2.0, center_y + wid / 2.0),
          righttop(center_x + len / 2.0, center_y + wid / 2.0),
          leftbottom(center_x - len / 2.0, center_y - wid / 2.0),
          rightbottom(center_x + len / 2.0, center_y - wid / 2.0)
    {
        Area = (ll)Len * Width;
    }

    /* 实现面积。 */
    ll getArea() override
    {
        return Area;
    }

    /* 判断坐标是否在图形内。 */
    bool inShape(Coordinate Point)
    {
        return lefttop.JudgeX(Point) <= 0 &&
               righttop.JudgeX(Point) >= 0 &&
               lefttop.JudgeY(Point) >= 0 &&
               leftbottom.JudgeY(Point) <= 0;
    }
};

int main()
{
    Square s(2, 0, 0);

    double x, y;
    cin >> x >> y;

    Coordinate point(x, y);

    if (s.inShape(point))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}