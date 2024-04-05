/***********************************************
 * 题目：[USACO19DEC] Where Am I? B
 * 描述：寻找到一个字符串最短的子长度，使得子串没有重复。
 * 思路：字符串哈希好像没有提高时间效率，还是轻松一点模拟吧。
 * 对象：UniqueSubString模拟唯一字符串。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class UniqueSubString
{
private:
public:
    /* 输入一个字符串，输出最短的字串长度。 */
    int getShortLen(string Str)
    {
        int StrLen = Str.size();
        set<string> SubStr; // 哈希集合，用于查询与存储

        rep(len, 1, StrLen)
        {
            bool Unique = true;
            SubStr.clear();
            rep(i, 0, StrLen - len) // i表示字符串的头
            {
                string substr = Str.substr(i, len);
                if (SubStr.count(substr) > 0)
                {
                    Unique = false;
                    break;
                }
                else
                {
                    SubStr.insert(substr);
                }
            }

            if (Unique)
            {
                return len;
            }
        }

        return -1;
    }
};

int main()
{
    ll strlen;
    cin >> strlen;
    UniqueSubString uss;

    string str;
    cin >> str;

    assert(str.size() == strlen);

    cout << uss.getShortLen(str) << endl;
}
