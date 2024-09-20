/*****************************************************************
 * 题目：[语言月赛 202409] 始终
 * 描述：给定一个字符串，输出多少子串的首尾是相同的。
 * 思路：统计字母出现次数。
 * 对象：BeginEndSubString模拟首尾子串。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long // 定义长整型

class BeginEndSubString
{
private:
    map<char, int> Letters;

public:
    /* 初始化，输入字符串。 */
    BeginEndSubString(string str)
    {
        for (auto ch : str)
        {
            Letters[ch]++;
        }
    }

    /* 输出一共有多少子串。 */
    ll substr()
    {
        ll ans = 0;
        for (auto pci : Letters)
        {
            ans += pci.second;
            ans += (ll)pci.second * (pci.second - 1) / 2;
        }

        return ans;
    }
};

int main()
{
    string str;
    cin >> str;

    BeginEndSubString bess(str);
    cout << bess.substr() << endl;
    return 0;
}
