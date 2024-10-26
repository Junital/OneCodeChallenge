/*****************************************************************
 * 题目：「SvR-1」Don't Mozheng. /oh
 * 描述：读取用户信息，如果出现指定表情，增加对应魔怔值。
 * 思路：字符串匹配问题。
 * 对象：Mozheng模拟魔怔。
 * 注意：注意数据的范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Mozheng
{
private:
    const string a_emo = "oh";
    const string b_emo = "hsh";
    const map<string, int> Emotion2Value;

public:
    /* 初始化，输入a值和b值。 */
    Mozheng(int a, int b) : Emotion2Value({{a_emo, a}, {b_emo, b}})
    {
    }

    /* 输入对话长度，输出对应的魔怔值。 */
    int query(int DialogueLen)
    {
        int res = 0;
        rep(i, 1, DialogueLen)
        {
            string name;
            string content;
            cin >> name;
            cin >> content;

            if (content[0] == '/')
            {
                string emo = content.substr(1);
                // cout << emo << endl;
                auto it = Emotion2Value.find(emo);
                if (it != Emotion2Value.end())
                {
                    res += it->second;
                }
            }
        }

        return res;
    }
};

int main()
{
    int len, a, b;
    cin >> len >> a >> b;

    Mozheng mz(a, b);
    cout << mz.query(len) << endl;
    return 0;
}