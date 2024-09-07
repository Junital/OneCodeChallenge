/*****************************************************************
 * 题目：[Cnoi2020] 子弦
 * 描述：输出一个字符串非空子串出现最多的次数。
 * 思路：统计26个字母。
 * 对象：CharMap模拟字符统计。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class CharMap
{
private:
    map<char, int> Chars;

public:
    /* 初始化，输入字符串。 */
    CharMap(string str)
    {
        for (auto ch : str)
        {
            Chars[ch]++;
        }
    }

    /* 输出最多出现次数 */
    int max_showup()
    {
        int ans = 0;
        for (auto chpair : Chars)
        {
            ans = max(chpair.second, ans);
        }

        return ans;
    }
};

int main()
{
    string str;
    cin >> str;

    CharMap cm(str);
    cout << cm.max_showup() << endl;
    return 0;
}