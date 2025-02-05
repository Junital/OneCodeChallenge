/*****************************************************************
 * 题目：[PA2021] Oranżada
 * 描述：置换相邻的橙汁，使其两两各不一样。
 * 思路：数字有重复肯定得移动，标记最右边的重复以及最左边不曾出现的即可。
 * 对象：MinSwap模拟最小置换。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义快速循环

class MinSwap
{
private:
    vector<int> Elements;

public:
    /* 初始化，输入数组。 */
    MinSwap(vector<int> elements) : Elements(elements) {}

    /* 输入想维持不一样的个数，输出最小步数。 */
    ll query(int k)
    {
        int size = Elements.size();

        set<int> counts;

        ll res = 0;
        int demand = 0;
        rep(i, 0, k - 1)
        {
            // cout << i << " " << counts.count(Elements[i]) << endl;
            if (counts.count(Elements[i]) > 0)
            {
                res += k - i;
                demand++;
            }

            counts.insert(Elements[i]);
        }

        // cout << res << endl;

        rep(i, k, size - 1)
        {
            if (demand == 0)
            {
                break;
            }

            if (counts.count(Elements[i]) == 0)
            {
                demand--;
                res += i - k;
                counts.insert(Elements[i]);
            }
        }

        if (!demand)
        {
            return res;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    int size, k;
    cin >> size >> k;

    vector<int> elements(size);
    rep(i, 0, size - 1)
    {
        cin >> elements[i];
    }

    MinSwap ms(elements);

    cout << ms.query(k) << endl;
    return 0;
}
