/**********************************************************
 * 题目：字符串 p 型编码
 * 描述：统计连续出现数字的个数。
 * 思路：一次性遍历。
 * 对象：PString模型P型编码。
 * 注意：加一个解码功能，保证拓展性。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class PString
{
private:
public:
    /* 编码 */
    string encode(string Str)
    {
        int Len = Str.length();
        int i = 1;           // 迭代器
        char digit = Str[0]; // 目前的重复字符
        int Count = 1;       // 计数器

        string pcode; // p型编码

        while (i < Len)
        {
            assert(Str[i] >= '0' && Str[i] <= '9');

            if (Str[i] == digit)
            {
                Count++;
            }
            else
            {
                pcode += to_string(Count);
                pcode += digit;
                pcode += " ";
                Count = 1;
                digit = Str[i];
            }
            i++;
        }

        pcode += to_string(Count);
        pcode += digit;
        return pcode;
    }

    /* 输出p型编码 */
    void print(string pcode)
    {
        for (auto ch : pcode)
        {
            if (ch != ' ')
            {
                cout << ch;
            }
        }
        cout << endl;
    }

    /* 解码 */
    string decode(string pcode)
    {
        /* 先提取空格，然后拿出每一部分，循环加入到答案中。 */
        string space = " ";
        int begin_idx = 0;                          // 头指针
        int end_idx = pcode.find(space, begin_idx); // 尾指针

        string ans;

        while (end_idx != -1)
        {
            string subcode = pcode.substr(begin_idx, end_idx - begin_idx);

            int digit = stoi(subcode) % 10;
            int count = stoi(subcode) / 10;

            rep(i, 1, count)
            {
                ans += to_string(digit);
            }

            begin_idx = end_idx + 1;
            end_idx = pcode.find(space, begin_idx);
        }

        /* 处理最后一批 */
        string subcode = pcode.substr(begin_idx);

        int digit = stoi(subcode) % 10;
        int count = stoi(subcode) / 10;

        rep(i, 1, count)
        {
            ans += to_string(digit);
        }

        return ans;
    }
};

int main()
{
    PString ps;

    string str;
    cin >> str;

    ps.print(ps.encode(str));

    // cout << ps.decode(ps.encode(str)) << endl;
    return 0;
}