/**********************************************************
 * 题目：素数回文数的个数
 * 描述：给出范围内所有即是素数又是回文数的个数。
 * 思路：初始化，然后搜索即可。
 * 对象：PrimePalin模拟素数回文数。
 * 注意：提高拓展性。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define Prime 1                                   // 素数
#define NotPrime 0                                // 非素数

class PrimePalin
{
private:
    const int MaxNum = 10001; // 最大接受的素数范围
    vector<bitset<1>> Primes; // 收集所有素数
    vector<int> PrimePalins;  // 素数回文数

    string getReverse(string str)
    {
        string rev;       // 逆转后的字符串
        stack<char> chst; // 存储char的栈

        for (auto ch : str)
        {
            chst.push(ch);
        }

        while (!chst.empty())
        {
            rev.push_back(chst.top());
            chst.pop();
        }

        return rev;
    }

    /* 判断是否是回文数 */
    bool JudgePalin(int Num)
    {
        // 思路：将字符串倒转，如果倒转之后一模一样，那就是回文数
        string NumStr = to_string(Num);
        string RevStr = getReverse(NumStr);

        if (NumStr.length() < 2)
        {
            return false;
        }

        return NumStr == RevStr;
    }

    /* 初始化素数回文数 */
    void InitPrime()
    {
        /* 思路：线性筛素数 */
        Primes[0] = Primes[1] = NotPrime;
        rep(i, 2, MaxNum - 1)
        {
            Primes[i] = Prime;
        }
        rep(i, 2, MaxNum - 1)
        {
            if (Primes[i] == Prime)
            {
                if (JudgePalin(i))
                {
                    PrimePalins.push_back(i);
                }
                if ((long long)i * i > MaxNum)
                {
                    continue;
                }
                for (int j = i * i; j <= MaxNum - 1; j += i)
                {
                    Primes[j] = NotPrime;
                }
            }
        }

        // for (auto num : PrimePalins)
        // {
        //     cout << num << " ";
        // }
        // cout << endl;
    }

public:
    /* 初始化 */
    PrimePalin()
    {
        Primes.resize(MaxNum);

        InitPrime();
    }

    /* 输入一个范围，输出这个范围内的素数回文数个数。 */
    int find(int Limit)
    {
        auto it = upper_bound(PrimePalins.begin(), PrimePalins.end(),
                              Limit);

        return distance(PrimePalins.begin(), it);
    }
};

int main()
{
    PrimePalin pp;

    int limit;
    cin >> limit;

    cout << pp.find(limit) << endl;
    return 0;
}