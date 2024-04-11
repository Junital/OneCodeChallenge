/***********************************************
 * 题目：小果的键盘
 * 描述：最多改变一个字符，使得某个字符串中VK数量最多。
 * 思路：一次遍历。
 * 对象：VKString模拟含VK的字符串。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class VKString
{
private:
    string Str;
    int VKNum;

    void check()
    {
        int StrLen = Str.size();
        VKNum = 0;
        bool canChange = false; // 可以将某个字符进行替换

        rep(i, 0, StrLen - 1)
        {
            if (Str[i] == 'V' && Str[i + 1] == 'K')
            {
                VKNum++;
            }
            else if (Str[i] == 'V' && i + 1 <= StrLen - 1 && Str[i + 1] != 'K')
            {
                canChange = true;
            }
            else if (Str[i] == 'K' && i - 1 >= 0 && Str[i - 1] != 'V')
            {
                canChange = true;
            }
        }

        if (canChange)
        {
            VKNum++;
        }
    }

public:
    /* 初始化输入一个字符串。 */
    VKString(string str) : Str(str)
    {
        check();
    }

    /* 获得VK的数量。 */
    int getVKNum()
    {
        return VKNum;
    }
};

int main()
{
    string strlen;
    string str;

    getline(cin, strlen);
    getline(cin, str);

    VKString vks(str);

    cout << vks.getVKNum() << endl;
    return 0;
}