/***********************************************
 * 题目：小果的键盘
 * 描述：最多改变一个字符，使得某个字符串中VK数量最多。
 * 思路：一次遍历不合理，尝试使用切割法。
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

    bool check(string str)
    {
        int StrLen = str.size();
        int Num = 0;
        bool canChange = false; // 可以将某个字符进行替换

        rep(i, 0, StrLen - 1)
        {
            if (Str[i] == 'V' && Str[i + 1] == 'K')
            {
                Num++;
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

        return canChange;
    }

    void init()
    {
        int pos = 0;
        bool canChange = false;
        VKNum = 0;
        int StrLen = Str.size();

        while (pos < StrLen)
        {
            int idx = Str.find("VK", pos);

            if (idx == -1)
            {
                canChange = canChange | check(Str.substr(pos));

                return;
            }

            VKNum++;
            if (idx > pos)
            {
                canChange = canChange | check(Str.substr(pos, idx - pos));
            }

            pos = idx + 2;
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
        init();
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