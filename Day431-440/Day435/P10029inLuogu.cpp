/*****************************************************************
 * 题目：「Cfz Round 3」Battle
 * 描述：模拟一场游戏，存在平局情况。
 * 思路：直接比较大小，
 * 空间：Tools模拟工具包。
 * 注意：注意数据范围，覆盖所有情况。
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
    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        int alice, bob;
        int mod;

        cin >> alice >> bob >> mod;

        if (bob >= mod && alice >= mod)
        {
            cout << "Lasting Battle" << endl;
        }
        else if (bob < mod)
        {
            cout << "Alice" << endl;
        }
        else
        {
            cout << "Bob" << endl;
        }
    }
    return 0;
}