/*****************************************************************
 * 题目：【深基2.例2】英文字母
 * 描述：对英文字母进行询问。
 * 思路：简单计算。
 * 空间：Tools模拟工具包。
 * 注意：输出格式。
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
    cout << 'M' - 'A' + 1 << endl;
    cout << (char)('A' + 18 - 1) << endl;
    return 0;
}