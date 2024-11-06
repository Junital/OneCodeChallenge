/*****************************************************************
 * 题目：[语言月赛 202307] 数字判断
 * 描述：判断三个数字是否满足4个条件。
 * 思路：简单判断
 * 函数：number_judge模拟数字判断。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

bool number_judge(ll A, ll B, ll C)
{
    bool condition_1 = A + B + C <= 100;
    bool condition_2 = B % 5 == 0;
    bool condition_3 = C % 7 == 0;
    bool condition_4 = A - B > B - C;

    return condition_1 && condition_2 && condition_3 && condition_4;
}

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if (number_judge(a, b, c))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
