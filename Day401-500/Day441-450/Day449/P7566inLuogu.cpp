/*****************************************************************
 * 题目：饱食
 * 描述：每只兔子的组别号不一样，问拿到三只组别号不同的兔子有多少种方案。
 * 思路：组合数学+动态规划，dp[i]其中i代表组合数，具体思路见P7566 Solve。
 * 对象：GroupCombinations模拟组合方案。
 * 注意：注意时间复杂度，最后结果别溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

class GroupCombinations
{
private:
public:
    int64_t calculate(vector<int64_t> &groups, int64_t n)
    {
        int m = groups.size();
        // cout << m << endl;
        if (n < 0 || n > m)
        {
            return 0;
        }

        vector<int64_t> dp(n + 1, 0);
        dp[0] = 1;
        for (int64_t i = 0; i < m; i++)
        {
            int64_t group = groups[i];
            for (int64_t j = n; j >= 1; j--)
            {
                if (j > i + 1)
                {
                    dp[j] = 0;
                }
                else
                {
                    dp[j] += dp[j - 1] * group;
                }
            }
        }

        return dp[n];
    }
};
int main()
{
    i64 n;
    cin >> n;

    const vector<char> chvec = {
        'M', 'C', 'O', 'I'}; // 兔子支持的四种组别
    const i64 combine_num = 3;
    GroupCombinations gc;

    vector<int64_t> groups(chvec.size(), 0);
    rep(i, 1, n)
    {
        string str;
        cin >> str;

        auto it = find(chvec.begin(), chvec.end(), str[0]);
        if (it != chvec.end())
        {
            groups[it - chvec.begin()]++;
        }
    }

    cout << gc.calculate(groups, combine_num) << endl;
    return 0;
}