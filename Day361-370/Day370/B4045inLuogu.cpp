/*****************************************************************
 * 题目：[语言月赛 202410] 同桌
 * 描述：问所有人能否两两配对。
 * 思路：数组访问。
 * 对象：Matching模拟配对。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Matching
{
private:
public:
    /* 输入意愿数组，输出能否匹配。 */
    bool query(vector<int> Willing)
    {
        int size = Willing.size();
        assert(size % 2 == 0);

        rep(i, 0, size - 1)
        {
            int willing_idx = Willing[i] - 1;
            int willingwilling_idx = Willing[willing_idx] - 1;
            if (willingwilling_idx != i || willing_idx == i)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Matching m;

    int size;
    cin >> size;

    vector<int> willing(size * 2);
    rep(i, 0, size * 2 - 1)
    {
        cin >> willing[i];
    }

    if (m.query(willing))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}