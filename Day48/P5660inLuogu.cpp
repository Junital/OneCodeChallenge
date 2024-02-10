/***********************************************
 * 题目：[CSP-J2019] 数字游戏
 * 描述：统计01串中1的个数。
 * 思路：简单统计。
 * 对象：ZeroOneString模拟01串。
 * 注意：结果小心别溢出。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速定义循环

class ZeroOneString
{
private:
    string Str;

public:
    /* 初始化，输入一个01字符串。 */
    ZeroOneString(string Str) : Str(Str)
    {
        /* 检查是否元素都是0或1 */
        for (auto ch : this->Str)
        {
            assert(ch == '1' || ch == '0');
        }
    }

    /* 获得字符1的个数。 */
    int GetOnesNum()
    {
        int cnt = 0; // 字符1计数
        for (auto ch : this->Str)
        {
            if (ch == '1')
            {
                cnt++;
            }
        }

        return cnt;
    }
};

int main()
{
    string str;
    cin >> str;
    ZeroOneString zo(str);

    cout << zo.GetOnesNum() << endl;
}