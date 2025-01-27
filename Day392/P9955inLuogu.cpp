/*****************************************************************
 * 题目：[USACO20DEC] Do You Know Your ABCs? B
 * 描述：已知A、B、C、A+B、B+C、A+C、A+B+C，求出A、B、C。
 * 思路：根据最大值、最小值来确定。
 * 对象：SumReconstruction模拟求和还原。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class SumReconstruction
{
private:
    int Num; // 数字的数量

public:
    /* 初始化，输入需要找出的数字数量。 */
    SumReconstruction(int num) : Num(num) {}

    /* 请求，输入一系列求和，找出最后的三个数字。 */
    vector<int> query(vector<int> Sums)
    {
        int sum_size = Sums.size();
        if (sum_size != Num * Num - 2)
        {
            throw invalid_argument("The vector must contain all sums (including single numbers).");
        }

        sort(Sums.begin(), Sums.end());

        vector<int> ans(Num);
        ans[0] = Sums[0], ans[1] = Sums[1];

        int total_sum = Sums[sum_size - 1];
        auto it1 = find(Sums.begin(), Sums.end(), ans[0] + ans[1]);
        auto it2 = find(Sums.begin(), Sums.end(), total_sum - (ans[0] + ans[1]));

        if (it1 == Sums.end() || it2 == Sums.end())
        {
            throw invalid_argument("There is no solution.");
        }

        vector<int> CurrentSums;
        CurrentSums.push_back(ans[0]);
        CurrentSums.push_back(ans[1]);
        CurrentSums.push_back(*it1);

        vector<bool> is_used(sum_size, false);
        is_used[0] = true;
        is_used[1] = true;

        int idx = 2;
        rep(j, 0, sum_size - 1)
        {
            if (idx == Num)
            {
                break;
            }
            if (!is_used[j])
            {
                bool pass = true;
                for (auto cs : CurrentSums)
                {
                    auto it = find(Sums.begin(), Sums.end(),
                                   cs + Sums[j]);
                    if (it == Sums.end())
                    {
                        pass = false;
                    }

                    if (cs + Sums[j] != total_sum)
                    {
                        it = find(Sums.begin(), Sums.end(),
                                  total_sum - (cs + Sums[j]));
                        if (it == Sums.end())
                        {
                            pass = false;
                        }
                    }
                }

                if (pass)
                {
                    is_used[j] = true;
                    ans[idx] = Sums[j];

                    int current_size = CurrentSums.size();
                    rep(i, 0, current_size - 1)
                    {
                        CurrentSums.push_back(CurrentSums[i] + Sums[j]);
                    }
                    idx++;
                }
            }
        }

        if (idx != Num)
        {
            throw runtime_error("There is no solution.");
        }

        return ans;
    }
};

int main()
{
    const int num = 3;

    SumReconstruction sr(num);

    vector<int> sums(num * num - 2);
    rep(i, 0, num * num - 3)
    {
        cin >> sums[i];
    }

    auto ans = sr.query(sums);
    for (auto e : ans)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}