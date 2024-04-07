/***********************************************
 * 题目：[CSP-J2019 江西] 面积
 * 描述：比较一个正方形的面积和一个长方形面积的大小。
 * 思路：简单计算。
 * 对象：Square、Rectangle模拟正方形和长方形。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

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
    int squlen, rectlen, rectwid;
    cin >> squlen >> rectlen >> rectwid;

    Square Alice(squlen);
    Rectangle Bob(rectlen, rectwid);

    if (Alice.getArea() > Bob.getArea())
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }

    return 0;
}
