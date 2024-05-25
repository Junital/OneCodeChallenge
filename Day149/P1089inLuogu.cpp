/**********************************************************
 * 题目：[NOIP2004 提高组] 津津的储蓄计划
 * 描述：根据预算留下自己的零花钱，将整百交给妈妈保管，年末获得20%的钱。
 * 思路：由于存在依赖，需要逐月模拟。
 * 对象：StoreMoney模拟存钱。
 * 注意：留好接口，提供拓展性。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class StoreMoney
{
private:
    int MoneyBatch; // 存钱的单位（比如100为一个单位）。

public:
    /* 初始化，输入存钱的单位。 */
    StoreMoney(int batch) : MoneyBatch(batch)
    {
    }

    /* 初始化，输入下发金额数组和预计消费数组。
    如果某一编号X无法消费，返回-1,X。
    否则返回一共存下的金额,手上还有的钱。 */
    pair<int, int> store(vector<int> Salary, vector<int> Demand)
    {
        assert(Salary.size() == Demand.size());
        int MoneyInHand = 0;         // 目前的钱
        int Stored = 0;              // 存下的钱
        int Periods = Salary.size(); // 周期数量

        rep(i, 0, Periods - 1)
        {
            if (MoneyInHand + Salary[i] < Demand[i])
            {
                return make_pair(-1, i);
            }

            int Balance = MoneyInHand + Salary[i] - Demand[i];
            Stored += (Balance / MoneyBatch) * MoneyBatch;
            MoneyInHand = Balance % MoneyBatch;
        }

        return make_pair(Stored, MoneyInHand);
    }
};

int main()
{
    const int batch = 100;
    const int salary = 300;
    const int periods = 12;
    const double rate = 0.2; // 回报率
    vector<int> Salary;
    vector<int> Demand;
    StoreMoney sm(batch);

    rep(i, 1, periods)
    {
        int d;
        cin >> d;
        Demand.push_back(d);
        Salary.push_back(salary);
    }

    pair<int, int> ans = sm.store(Salary, Demand);
    if (ans.first < 0)
    {
        cout << ans.first * (ans.second + 1) << endl; // +1来满足输出要求
    }
    else
    {
        int Bonus = ans.first * (1 + rate);
        cout << Bonus + ans.second << endl;
    }
    return 0;
}