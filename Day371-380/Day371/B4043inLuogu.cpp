/*****************************************************************
 * 题目：[语言月赛 202410] 刻度尺
 * 描述：问到某个位置距离为x的刻度是否存在。
 * 思路：询问是否在范围中。
 * 对象：Ruler模拟刻度尺。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Ruler
{
private:
    int MaxLen;

    bool inRuler(int x)
    {
        return x >= 0 && x <= MaxLen;
    }

public:
    Ruler(int maxlen) : MaxLen(maxlen) {}

    set<int> find_by_dir(int x, int dir)
    {
        set<int> res;

        if (inRuler(x + dir))
        {
            res.insert(x + dir);
        }

        if (inRuler(x - dir))
        {
            res.insert(x - dir);
        }

        return res;
    }
};

int main()
{
    int maxlen;
    cin >> maxlen;

    Ruler r(maxlen);

    int x, dir;
    cin >> x >> dir;
    auto res = r.find_by_dir(x, dir);

    if (res.empty())
    {
        cout << "No solution" << endl;
    }
    else
    {
        for (auto e : res)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}