/*****************************************************************
 * 题目：[语言月赛202211] Winner
 * 描述：比较某个数与2的关系，输出对应的答案。
 * 思路：简单函数实现。
 * 对象：Compare用于比较某个数和2的关系。
 * 注意：注意数据的范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Compare
{
private:
    int Base; // 基数

public:
    /* 初始化，输入一个基数。 */
    Compare(int base = 0) : Base(base)
    {
    }

    int compare(int Num)
    {
        return Num - Base;
    }
};

int main()
{
    const int base = 2;
    int num;

    Compare c(base);
    cin >> num;

    if (c.compare(num) > 0)
    {
        cout << "Survivor" << endl;
    }
    else if (c.compare(num) == 0)
    {
        cout << "Tie" << endl;
    }
    else
    {
        cout << "Hunter" << endl;
    }
    return 0;
}
