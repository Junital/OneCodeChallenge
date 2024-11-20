/*****************************************************************
 * 题目：[NICA #3] 放生鱼豆腐
 * 描述：多个阶段罚款。
 * 思路：初始化构造新的罚款。
 * 对象：Finer模拟罚款者。
 * 注意：注意可拓展性，小心数据溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class Finer
{
private:
    vector<int> Limit;
    vector<int> Money;

    bool judge_asc()
    {
        int size = Limit.size();

        rep(i, 1, size - 1)
        {
            if (Limit[i] <= Limit[i - 1])
            {
                return false;
            }
        }

        return true;
    }

public:
    /* 初始化，输入限制和钱。 */
    Finer(vector<int> limit, vector<int> money)
        : Limit(limit), Money(money)
    {
        assert(Limit.size() == Money.size());
        assert(judge_asc());
    }

    /* 请求，输入数量，输出罚款金额。 */
    int query(int Num)
    {
        int fine = 0;
        int size = Limit.size();
        rep(i, 0, size - 1)
        {
            if (Num >= Limit[i])
            {
                if (i != size - 1)
                {
                    int quota = min(Num, Limit[i + 1]) - Limit[i];
                    fine += quota * Money[i];
                }
                else
                {
                    fine += (Num - Limit[i]) * Money[i];
                }
            }
        }

        return fine;
    }
};

int main()
{
    const vector<int> limit = {0, 10, 100};
    vector<int> money(limit.size());

    int query_num;
    cin >> query_num;

    int size = money.size();
    rep(i, 0, size - 1)
    {
        cin >> money[i];
    }

    Finer f(limit, money);

    ll sum = 0;
    rep(i, 1, query_num)
    {
        int num;
        cin >> num;
        sum += f.query(num);
    }

    cout << sum << endl;
    return 0;
}