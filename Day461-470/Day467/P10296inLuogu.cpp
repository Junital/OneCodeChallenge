/*****************************************************************
 * 题目：[CCC 2024 S2] Heavy-Light Composition
 * 描述：出现多次的字母和出现一次的字母需要交替出现。
 * 思路：能否一次遍历就判断？
 * 函数：judge_heavy_light_str模拟判断轻重字符串。
 * 注意：可以提高可拓展性，不一定要小写字母。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
    /* 四舍五入 */
    int Approximate(double Num)
    {
        double Ceil = ceil(Num);
        double Floor = floor(Num);

        if (Ceil - Num <= Num - Floor)
        {
            return (int)Ceil;
        }
        else
        {
            return (int)Floor;
        }
    }
};

using namespace Tools;

bool judge_heavy_light_str(string &str)
{
    int len = str.length();
    map<char, int> chcnt;

    for (auto ch : str)
    {
        chcnt[ch]++;
    }

    if (chcnt[str[0]] > 1)
    {
        for (int i = 1; i < len; i++)
        {
            // i % 2 == 0 --> > 1
            // i % 2 == 1 --> == 1

            if (i % 2 && chcnt[str[i]] > 1)
            {
                return false;
            }
            else if (!(i % 2) && chcnt[str[i]] <= 1)
            {
                return false;
            }
        }
    }
    else
    {
        for (int i = 1; i < len; i++)
        {
            // i % 2 == 0 --> == 1
            // i % 2 == 1 --> > 1

            if (i % 2 && chcnt[str[i]] <= 1)
            {
                return false;
            }
            else if (!(i % 2) && chcnt[str[i]] > 1)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int query_num, len;
    cin >> query_num >> len;

    rep(i, 1, query_num)
    {
        string str;
        cin >> str;

        if (judge_heavy_light_str(str))
        {
            cout << "T" << endl;
        }
        else
        {
            cout << "F" << endl;
        }
    }
    return 0;
}