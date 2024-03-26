/***********************************************
 * 题目：因子化简
 * 描述：化简素数，使其幂次方都大于某个阈值。
 * 思路：初始化，然后开始模拟。
 * 对象：SimplifyPrime模拟简化素数。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (long long i = s; i <= k; i++) // 定义快速循环

#define ll long long // 定义长整型

#define NotPrime 0 // 不是素数
#define Prime 1    // 素数

class SimplifyPrime
{
private:
    vector<bitset<1>> Primes;
    const ll MaxNum = (ll)100005;

    void Init()
    {
        Primes.resize(MaxNum + 1);
        Primes[0] = Primes[1] = NotPrime;

        rep(i, 2, MaxNum)
        {
            Primes[i] = Prime;
        }

        rep(i, 2, MaxNum)
        {
            if (Primes[i] == NotPrime)
            {
                continue;
            }

            for (ll j = i * i; j <= MaxNum; j += i)
            {
                Primes[j] = NotPrime;
            }
        }
    }

public:
    SimplifyPrime()
    {
        Init();
    }

    void Query(int Times)
    {
        rep(i, 1, Times)
        {
            ll Num;        // 数字
            int Threshold; // 阈值

            cin >> Num >> Threshold;

            ll Simplified = Num;

            rep(i, 2, MaxNum)
            {
                if (Primes[i] == Prime && Num % i == 0)
                {
                    ll Mi = 1;
                    int Ti = 0;
                    while (Num % i == 0)
                    {
                        Num /= i;
                        Mi *= i;
                        Ti++;
                        // cout << Num << " " << Ti << endl;
                    }

                    if (Ti < Threshold)
                    {
                        Simplified /= Mi;
                    }
                }
            }

            cout << Simplified / Num << endl;
        }
    }
};

int main()
{
    SimplifyPrime sp;

    int q;
    cin >> q;

    sp.Query(q);
    return 0;
}