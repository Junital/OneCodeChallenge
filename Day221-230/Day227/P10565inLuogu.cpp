/*****************************************************************
 * 题目：[ICPC2024 Xi'an I] Chained Lights
 * 描述：每次会关一定倍数的灯，问最后某个灯是否是亮的。
 * 思路：通过测试找结论。只要非1即为NO。
 * 对象：ChainedLights模拟链式灯。
 * 注意：注意符合给定测试代码。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ChainedLights
{
private:
    vector<bitset<1>> Lights;

    /* 按灯。 */
    void press(int Idx)
    {
        Lights[Idx - 1] ^= 1;
        int len = Lights.size();
        for (int y = 2 * Idx; y <= len; y += Idx)
        {
            press(y);
        }
    }

public:
    /* 初始化，输入灯的长度。 */
    ChainedLights(int Len)
    {
        Lights.resize(Len, 0);
        rep(i, 1, Len)
        {
            press(i);
        }
    }

    /* 输出。 */
    void print()
    {
        for (auto x : Lights)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main()
{
    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        int len, query;
        cin >> len >> query;

        if (query == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
