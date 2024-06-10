/**********************************************************
 * 题目：我家的门牌号
 * 描述：门牌号从1开始排到n，如果其他门牌号之和减去我家门牌号的两倍恰好为n。
        问我家门牌号以及一共有多少家。
 * 思路：见B2133 Solve。
 * 对象：HouseNumber模拟门牌号。
 * 注意：先检验一下阶段性结论。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class HouseNumber
{
private:
    const int threshold = 1e5 + 1e3;
    vector<int> Sums;

    void init()
    {
        int i = 1;

        /* 获取所有和，方便查询 */
        while (true)
        {
            int sum = (i) * (i + 1) / 2;
            if (sum >= threshold)
            {
                break;
            }
            Sums.push_back(sum);
            i++;
        }
    }

public:
    HouseNumber()
    {
        init();
    }

    void test()
    {
        rep(i, 1, 1000)
        {
            int sum = (i) * (i + 1) / 2;
            if (sum >= 1e5 + 1e3)
            {
                break;
            }
            cout << sum << endl;
        }
    }

    void solve(int diff)
    {
        vector<int>::iterator it = lower_bound(Sums.begin(), Sums.end(), diff);

        while (true)
        {
            int sum = *it;
            int triple = sum - diff;

            if (triple % 3 == 0 && triple != 0)
            {
                // 我家门牌号就是之差除以3、总共多少家就是求和的两倍开方
                cout << triple / 3 << " " << (int)sqrt(2 * sum) << endl;
                break;
            }

            it++;
        }
    }
};

int main()
{
    HouseNumber hn;

    int diff;
    cin >> diff;

    hn.solve(diff);
    return 0;
}
