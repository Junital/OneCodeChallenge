/*****************************************************************
 * 题目：【深基3.例1】数字比较
 * 描述：比较数字。
 * 思路：直接当做整型处理。
 * 空间：Tools模拟工具包。
 * 注意：类型转换和不同编译器的适配。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

int main()
{
    int a, b;
    cin >> a >> b;

    cout << (a > b) << " " << (a <= b) << " " << (a != b) << endl;
    return 0;
}