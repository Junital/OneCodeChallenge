/*****************************************************************
 * 题目：[信息与未来 2019] 幸运素数
 * 描述：幸运素数不仅本身是素数，且每次去除低位依旧是素数。
 * 思路：先找素数，再逐一判断。
 * 对象：LuckyPrime模拟幸运素数。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class LuckyPrime
{
private:
    const int MaxNum = 10005; // 最大接受的素数范围
    vector<bool> Primes;      // 收集所有素数

    /* 初始化素数 */
    void InitPrime()
    {
        Primes.resize(MaxNum);

        /* 思路：线性筛素数 */
        Primes[0] = Primes[1] = false;
        rep(i, 2, MaxNum - 1)
        {
            Primes[i] = true;
        }
        rep(i, 2, MaxNum - 1)
        {
            if (Primes[i] == true)
            {
                if ((long long)i * i > MaxNum)
                {
                    continue;
                }
                for (int j = i * i; j <= MaxNum - 1; j += i)
                {
                    Primes[j] = false;
                }
            }
        }
    }

public:
    LuckyPrime() { InitPrime(); }

    /* 判断单个值是否是素数。 */
    bool judge(int Num)
    {
        if (Num < 0 || Num >= MaxNum)
        {
            throw invalid_argument("The number is out of the limit.");
        }

        while (Num != 0)
        {
            if (!Primes[Num])
            {
                return false;
            }
            Num /= 10;
        }
        return true;
    }

    /* 输入区间，输出这个区间内的幸运素数。 */
    vector<int> interval_query(int Begin, int End)
    {
        vector<int> res;

        rep(i, Begin, End)
        {
            if (judge(i))
            {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main()
{
    LuckyPrime lp;

    int Begin, End;
    cin >> Begin >> End;

    auto res = lp.interval_query(Begin, End);
    for (auto e : res)
    {
        cout << e << endl;
    }
    return 0;
}