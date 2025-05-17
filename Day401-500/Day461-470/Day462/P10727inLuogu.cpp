/*****************************************************************
 * 题目：[NOISG 2023 Qualification] Area
 * 描述：求面积最大的一个长方形。
 * 思路：计算，取最大值。
 * 空间：Rectangle模拟长方形。
 * 注意：尽量别浪费空间。
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

using namespace Tools;

class Graphics
{
public:
    virtual int getArea() = 0;
};

class Square : public Graphics
{
private:
    int Len;
    int Area;

public:
    /* 初始化，输入边长。 */
    Square(int len) : Len(len)
    {
        Area = Len * Len;
    }

    /* 实现面积。 */
    int getArea() override
    {
        return Area;
    }
};

class Rectangle : public Graphics
{
private:
    int Len;
    int Width;
    int Area;

public:
    /* 初始化，输入边长。 */
    Rectangle(int len, int wid) : Len(len), Width(wid)
    {
        Area = Len * Width;
    }

    /* 实现面积。 */
    int getArea() override
    {
        return Area;
    }
};

int main()
{
    int rect_num;
    cin >> rect_num;

    int max_area = 0;
    rep(i, 1, rect_num)
    {
        int len, wid;
        cin >> len >> wid;
        max_area = max(max_area, Rectangle(len, wid).getArea());
    }

    cout << max_area << endl;
    return 0;
}