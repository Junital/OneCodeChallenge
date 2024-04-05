/*************************************
 * 题目：Cantor表（升级版）
 * 描述：计算两个分数的相乘，输出结果在Centor表上的位置。
    Centor表：
    1/1 1/2 1/3 1/4 1/5 ...
    2/1 2/2 2/3 2/4 ...
    3/1 3/2 3/3 ...
    4/1 4/2 ...
    5/1 ...
 * 思路：先算乘法，再搜索表。
 * 对象：Fraction用于抽象分数。
 *************************************/

#include <bits/stdc++.h>

using namespace std;

class Fraction
{
private:
    int Down = 0; // 分母
    int Up = 0;   // 分子

    /* 求最大公因数 */
    inline int gcd(int x, int y)
    {
        if (y == 0)
        {
            return x;
        }
        return gcd(y, x % y);
    }

    /* 化简分数 */
    void Simplify()
    {
        int both = gcd(Up, Down); // 计算最大公约数
        Up /= both;
        Down /= both;
    }

public:
    Fraction()
    {
        scanf("%d/%d", &Up, &Down);
        Simplify();
    }
    Fraction(int up, int down) : Up(up), Down(down)
    {
        Simplify();
    }

    Fraction operator*(const Fraction other)
    {
        int new_up = this->Up * other.Up;
        int new_down = this->Down * other.Down;
        Fraction res = Fraction(new_up, new_down);
        return res;
    }

    pair<int, int> getCantor()
    {
        return make_pair(Down, Up);
    }
};

int main()
{
    Fraction f1 = Fraction();
    Fraction f2 = Fraction();
    Fraction f3 = f1 * f2;
    pair<int, int> pos = f3.getCantor();
    printf("%d %d\n", pos.first, pos.second);
}