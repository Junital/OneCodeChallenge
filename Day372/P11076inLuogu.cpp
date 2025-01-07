/*****************************************************************
 * 题目：「FSLOI Round I」单挑
 * 描述：问赢下比赛的所有可能性中连胜最少数量。
 * 思路：单个插入。
 * 对象：CharMap模拟字符统计。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

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

    /* 请求，输入字符，输出次数。 */
    int query(char ch)
    {
        auto it = Chars.find(ch);

        if (it != Chars.end())
        {
            return it->second;
        }
        return 0;
    }
};

int main()
{
    int query_num;
    const char x_ch = 'F';
    const char y_ch = 'S';
    cin >> query_num;

    rep(i, 1, query_num)
    {
        int len, x_win, y_win, ans;
        cin >> len >> x_win >> y_win;
        string match;
        cin >> match;

        CharMap cm(match);

        int x_left = x_win - cm.query(x_ch);
        int y_left = y_win - cm.query(y_ch);

        assert(y_left != 0);

        if (x_left == 0)
        {
            ans = 0;
        }
        else if (y_left == 1)
        {
            ans = x_left;
        }
        else
        {
            ans = x_left / y_left + (x_left % y_left != 0);
        }
        // cout << x_left << " " << y_left << endl;
        cout << ans << endl;
    }
    return 0;
}