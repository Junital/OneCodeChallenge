/***********************************************
 * 题目：哥德巴赫猜想
 * 描述：找到偶数为两个质数之和，质数小优先。
 * 思路：初始化，然后再输出。
 * 对象：Goldbach模拟哥德巴赫猜想。
 * 注意：时间限制。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define Prime 1                                   // 素数
#define NotPrime 0                                // 非素数

class GoldBach
{
private:
    const int MaxNum = 10005; // 最大接受的素数范围
    vector<bitset<1>> Primes; // 收集所有素数
    int Top;                  // 迭代输出结束的偶数

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
    /* 初始化，输入结束的偶数 */
    GoldBach(int top) : Top(top)
    {
        Primes.resize(MaxNum);

        InitPrime();
    }

    /* 输出猜想结果，将偶数进行拆解。 */
    void Print()
    {
        for (int i = 4; i <= Top; i += 2)
        {
            rep(j, 2, i - 1)
            {
                if (Primes[j] == Prime && Primes[i - j] == Prime)
                {
                    cout << i << "=" << j << "+" << i - j << endl; // 输出结果
                    break;
                }
            }
        }
    }
};

int main()
{
    int top;
    cin >> top;

    GoldBach gb(top);
    gb.Print();
}