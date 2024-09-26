/*****************************************************************
 * 题目：求小数的某一位
 * 描述：计算某个分数小数点后的某一位。
 * 思路：循环计算。
 * 对象：Fraction模拟分数。
 * 注意：注意时间复杂度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Fraction
{
private:
    int Up = 0;   // 分子
    int Down = 0; // 分母

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

    /* 请求小数后某一位。 */
    int query_digit(int Idx)
    {
        int left = Up % Down;
        rep(i, 1, Idx - 1)
        {
            left *= 10;
            left = left % Down;
        }

        return left * 10 / Down;
    }
};

int main()
{
    int up, down;
    cin >> up >> down;
    Fraction f(up, down);

    int idx;
    cin >> idx;
    cout << f.query_digit(idx) << endl;
    return 0;
}
