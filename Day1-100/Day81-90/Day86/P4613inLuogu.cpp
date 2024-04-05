/***********************************************
 * 题目：[COCI2017-2018#5] Olivander
 * 描述：输入盒子的高度和木棍的长度，求是否能将所有木棍逐一放进盒子里。
 * 思路：排序，逐一对应。
 * 对象：Olivander模拟木棍商。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Olivander
{
private:
    int Size;         // 木棍和盒子的个数。
    vector<int> Wand; // 木棍
    vector<int> Box;  // 盒子

    string JudgeString(bool isYes)
    {
        if (isYes)
        {
            return "DA";
        }
        return "NE";
    }

public:
    /* 判断是否木棍和盒子能逐一匹配。 */
    string judge()
    {
        sort(Wand.begin(), Wand.end());
        sort(Box.begin(), Box.end());

        rep(i, 0, Size - 1)
        {
            if (Wand[i] > Box[i])
            {
                return JudgeString(false);
            }
        }

        return JudgeString(true);
    }

    /* 初始化，输入木棍与盒子的个数。 */
    Olivander(int size) : Size(size)
    {
        Wand.resize(Size);
        Box.resize(Size);

        rep(i, 0, Size - 1)
        {
            cin >> Wand[i];
        }

        rep(i, 0, Size - 1)
        {
            cin >> Box[i];
        }
    }
};

int main()
{
    int size;

    cin >> size;

    Olivander o(size);
    cout << o.judge() << endl;

    return 0;
}