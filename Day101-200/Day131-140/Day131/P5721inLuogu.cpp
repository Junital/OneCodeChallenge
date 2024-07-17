/***************************************************************
 * 题目：【深基4.例6】数字直角三角形
 * 描述：给定一个边长，打印一个数字三角形。
 * 思路：无。
 * 对象：NumRightTri模拟数字直角三角形。
 * 注意：注意上界。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class NumRightTri
{
private:
    void printNum(int Num)
    {
        if (Num < 10)
        {
            cout << "0" << Num;
        }
        else
        {
            cout << Num;
        }
    }

public:
    void print(int Num)
    {
        int currentNum = 1;

        rep(i, 1, Num)
        {
            rep(j, 1, Num - i + 1)
            {
                printNum(currentNum);
                currentNum++;
            }
            cout << endl;
        }
    }
};

int main()
{
    NumRightTri nrt;

    int Num;
    cin >> Num;

    nrt.print(Num);
    return 0;
}
