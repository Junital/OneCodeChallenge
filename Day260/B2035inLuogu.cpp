/*****************************************************************
 * 题目：判断数正负
 * 描述：判断一个数的正负。
 * 思路：简单比较。
 * 函数：positive_negative模拟正负。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

string positive_negative(int Num)
{
    if (Num == 0)
    {
        return "zero";
    }

    if (Num > 0)
    {
        return "positive";
    }

    return "negative";
}

int main()
{
    int num;
    cin >> num;
    cout << positive_negative(num) << endl;
    return 0;
}
