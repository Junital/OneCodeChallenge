/******************************************************
 * 题目：小书童——凯撒密码
 * 描述：将密码向后移动n位。
 * 思路：每个字母处理一下。
 * 对象：CaesarCipher模拟凯撒密码。
 * 注意：循环移动。
 ******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class CasearCipher
{
private:
    int Offset;               // 密码与原码的偏移
    const int LETTERNUM = 26; // 字母数量

    char move_afterward(char ch)
    {
        assert(ch >= 'a' && ch <= 'z');

        /* 索引：a为0、z为25 */
        int idx = ch - 'a';                         // 获得初始字母的索引
        int moved_idx = (idx + Offset) % LETTERNUM; // 计算得到偏移后的索引

        return 'a' + moved_idx;
    }

    char move_forward(char ch)
    {
        assert(ch >= 'a' && ch <= 'z');

        /* 索引：a为0、z为25 */
        int idx = ch - 'a';                                     // 获得初始字母的索引
        int moved_idx = (idx - Offset + LETTERNUM) % LETTERNUM; // 计算得到偏移后的索引

        return 'a' + moved_idx;
    }

public:
    /* 初始化，可以定义偏移。 */
    CasearCipher(int offset = 1) : Offset(offset) {}

    /* 编码，输入字符串，输出对应的密码。 */
    string encode(string Origin)
    {
        int StrLen = Origin.size();

        string Code;

        rep(i, 0, StrLen - 1)
        {
            Code += move_afterward(Origin[i]); // 将移动后的字符串加入
        }

        return Code;
    }

    /* 解码，输入字符串密码，输出对应的原。 */
    string decode(string Code)
    {
        int StrLen = Code.size();

        string Origin;

        rep(i, 0, StrLen - 1)
        {
            Origin += move_afterward(Code[i]); // 将移动后的字符串加入
        }

        return Origin;
    }
};

int main()
{
    int offset;
    string origin;

    cin >> offset;
    cin >> origin;

    CasearCipher cc(offset);
    cout << cc.encode(origin) << endl;
    return 0;
}