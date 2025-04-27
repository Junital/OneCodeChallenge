/*****************************************************************
 * 题目：[语言月赛 202403] Qiu
 * 描述：通过加入分母，问分数何时比阈值小。
 * 思路：封装一个分数类。
 * 空间：Fraction模拟分数。
 * 注意：
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
    /* 四舍五入 */
    int Approximate(double Num)
    {
        double Ceil = ceil(Num);
        double Floor = floor(Num);

        if (Ceil - Num <= Num - Floor)
        {
            return (int)Ceil;
        }
        else
        {
            return (int)Floor;
        }
    }
};

/* 分数。 */
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

    Fraction operator*(const Fraction &other)
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

    /* 比较大小。 */
    bool operator<=(const Fraction &other)
    {
        return this->Up * other.Down <= other.Up * this->Down;
    }
    bool operator>=(const Fraction &other)
    {
        return this->Up * other.Down >= other.Up * this->Down;
    }
    bool operator<(const Fraction &other)
    {
        return this->Up * other.Down < other.Up * this->Down;
    }
    bool operator>(const Fraction &other)
    {
        return this->Up * other.Down > other.Up * this->Down;
    }
};

using namespace Tools;

int main()
{
    int cur_down, cur_up, thres_up, thres_down;
    cin >> cur_down >> cur_up >> thres_up >> thres_down;

    Fraction threshold(thres_up, thres_down);

    int increase = 0;
    while (Fraction(cur_up, cur_down + increase) > threshold)
    {
        increase++;
    }

    cout << increase << endl;
    return 0;
}