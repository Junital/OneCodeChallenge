/*********************************************************
 * 题目：[NEERC2013] Fraud Busters
 * 描述：判断一个字符串是否符合掩码。
 * 思路：字符串配对。
 * 对象：MaskedString模拟掩码。
 * 注意：注意考虑拓展性。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class MaskedString
{
private:
    const char MASK = '*';
    string Str;

public:
    /* 初始化，输入字符串。 */
    MaskedString(string str) : Str(str) {}

    /* 判断字符串与掩码是否匹配。 */
    bool judge(string Code)
    {
        if (Str.size() != Code.size())
        {
            return false;
        }

        int codesize = Code.size();

        rep(i, 0, codesize - 1)
        {
            if (!(Str[i] == Code[i] || Str[i] == MASK))
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string mask;
    cin >> mask;

    MaskedString ms(mask);

    int Num;
    cin >> Num;
    vector<string> Ans;

    rep(i, 1, Num)
    {
        string code;
        cin >> code;

        if (ms.judge(code))
        {
            Ans.push_back(code);
        }
    }

    cout << Ans.size() << endl;
    for (auto ans : Ans)
    {
        cout << ans << endl;
    }
    return 0;
}
