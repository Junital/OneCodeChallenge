/**********************************************************
 * 题目：质数的和与积
 * 描述：给定两个质数的和，求最大乘积。
 * 思路：单纯遍历，贪心，两个数越接近越好。
 * 对象：PrimeSum模拟质数和。
 * 注意：提高拓展性。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i++) // 定义逆循环
#define Prime 1                                   // 素数
#define NotPrime 0                                // 非素数

class PrimeSum
{
private:
    const int MaxNum = 10001; // 最大接受的素数范围
    vector<bitset<1>> Primes; // 收集所有素数

    /* 初始化素数 */
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
    }

public:
    /* 初始化 */
    PrimeSum()
    {
        Primes.resize(MaxNum);
        InitPrime();
    }

    /* 测试函数 */
    void test()
    {
        rep(i, 1, MaxNum - 1)
        {
            if (Primes[i] == Prime)
            {
                rep(j, 1, i)
                {
                    if (Primes[j] == Prime)
                    {
                        cout << i + j << endl;
                    }
                }
            }
        }
    }

    /* 给定两个素数的和，求最大素数乘积。 */
    int max_multi(int Sum)
    {
        per(small, Sum / 2, 1)
        {
            int large = Sum - small;
            if (Primes[small] == Prime && Primes[large] == Prime)
            {
                return small * large;
            }
        }

        return -1;
    }
};

int main()
{
    PrimeSum ps;

    int sum;
    cin >> sum;
    cout << ps.max_multi(sum) << endl;
    return 0;
}
