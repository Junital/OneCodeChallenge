/*****************************************************************
 * 题目：[NWRRC2014] Grave
 * 描述：一个回字形的面积，问一个矩形是否有面积。
 * 思路：比较四次。
 * 对象：HollowSquare模拟回字形面积。
 * 注意：注意数据别溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

template <typename T>
class Coordinate
{
private:
    T X, Y;

public:
    Coordinate(T x, T y) : X(x), Y(y)
    {
    }

    Coordinate(Coordinate<T> &other)
    {
        X = other.X;
        Y = other.Y;
    }

    /* 获得距离 */
    T getDis(Coordinate &other)
    {
        T xdiff = abs(X - other.X);
        T ydiff = abs(Y - other.Y);

        return sqrt(xdiff * xdiff + ydiff * ydiff);
    }

    /* 获得x距离。 */
    T getXDis(Coordinate &other)
    {
        return X - other.X;
    }

    /* 获得y距离。 */
    T getYDis(Coordinate &other)
    {
        return Y - other.Y;
    }
};

class HollowSquare
{
private:
    Coordinate<int> OutLeftDown, OutRightTop,
        InLeftDown, InRightTop;

public:
    /* 初始化，输入外矩形和内矩形的左上右下坐标。 */
    HollowSquare(Coordinate<int> OutLD, Coordinate<int> OutRT,
                 Coordinate<int> InLD, Coordinate<int> InRT)
        : OutLeftDown(OutLD), OutRightTop(OutRT),
          InLeftDown(InLD), InRightTop(InRT) {}

    /* 判断能否放下某个矩形。 */
    bool judge(int Height, int Width)
    {
        /* 左侧 */
        if (InLeftDown.getXDis(OutLeftDown) >= Width &&
            OutRightTop.getYDis(OutLeftDown) >= Height)
        {
            return true;
        }

        /* 右侧 */
        if (OutRightTop.getXDis(InRightTop) >= Width &&
            OutRightTop.getYDis(OutLeftDown) >= Height)
        {
            return true;
        }

        /* 上面 */
        if (OutRightTop.getXDis(OutLeftDown) >= Width &&
            OutRightTop.getYDis(InRightTop) >= Height)
        {
            return true;
        }

        /* 下面 */
        if (OutRightTop.getXDis(OutLeftDown) >= Width &&
            InLeftDown.getYDis(OutLeftDown) >= Height)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int out_ld_x, out_ld_y, out_rt_x, out_rt_y;
    cin >> out_ld_x >> out_ld_y >> out_rt_x >> out_rt_y;

    int in_ld_x, in_ld_y, in_rt_x, in_rt_y;
    cin >> in_ld_x >> in_ld_y >> in_rt_x >> in_rt_y;

    Coordinate<int> outld(out_ld_x, out_ld_y),
        outrt(out_rt_x, out_rt_y),
        inld(in_ld_x, in_ld_y),
        inrt(in_rt_x, in_rt_y);

    HollowSquare hs(outld, outrt, inld, inrt);

    int w, h;
    cin >> w >> h;

    if (hs.judge(h, w))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
