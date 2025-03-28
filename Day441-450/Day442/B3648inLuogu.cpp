/*****************************************************************
 * 题目：[语言月赛202208] 你几岁了
 * 描述：组合字符串。
 * 思路：简单输入输出。
 * 空间：Tools模拟工具包。
 * 注意：注意输出格式。
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
    int x;
    cin >> x;
    cout << "I am " << x << " years old." << endl;
    return 0;
}