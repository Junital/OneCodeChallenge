/***********************************************
 * 题目：三角函数
 * 描述：给出直角三角形的三条边，要求输出小锐角的正弦值。
 * 思路：找到最小的、最大的，然后约分。
 * 对象：RightTriangle模拟直角三角形。
 * 注意：注意约分。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

class RightTriangle
{
private:
    int A, B, C; // 三条边

    inline int gcd(int x, int y)
    {
        if (y == 0)
        {
            return x;
        }
        return gcd(y, x % y);
    }

    /* 约分 */
    void Simplify(int &x, int &y)
    {
        int both = gcd(x, y);

        x /= both;
        y /= both;
    }

public:
    /* 初始化，输入三条边。 */
    RightTriangle(int a, int b, int c) : A(a), B(b), C(c) {}

    /* 输出最小角的余弦值。 */
    void printSmallSin()
    {
        int minAngle = min(A, min(B, C)); // 最小角
        int maxAngle = max(A, max(B, C)); // 最大角

        Simplify(minAngle, maxAngle);

        cout << minAngle << "/" << maxAngle << endl;
    }
};

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    RightTriangle rt(a, b, c);

    rt.printSmallSin();
    return 0;
}