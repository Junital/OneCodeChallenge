/***********************************************
 * 题目：Coprime
 * 描述：输入的数字最大公约数必须是1，然后找到每个数组值最大的一对。
 * 思路：数论，可以用数字<=1000的限制来完成。
 * 对象：Coprime用于模拟并计算。
 * 注意：事件上的限制。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义快速倒序循环

class Coprime
{
private:
    int T;
    const int MaxNum = 1000;

    inline int gcd(int x, int y)
    {
        if (y == 0)
        {
            return x;
        }
        return gcd(y, x % y);
    }

    /* 先输入一个map，然后通过遍历找到值最大的组合。 */
    int search_cal(map<int, int> NumIdx)
    {
        int MaxValue = -1; // 答案

        for (auto ni : NumIdx)
        {
            for (auto nj : NumIdx)
            {
                if (gcd(ni.first, nj.first) == 1)
                {
                    MaxValue = max(MaxValue, ni.second + nj.second);
                }
            }
        }

        return MaxValue;
    }

public:
    /* 初始化，输入需要计算的次数。 */
    Coprime(int t) : T(t)
    {
        rep(i, 1, T)
        {
            int size;
            map<int, int> numidx;
            cin >> size;

            rep(j, 1, size)
            {
                int num;

                cin >> num;

                numidx[num] = max(numidx[num], j);
            }

            cout << search_cal(numidx) << endl; // 搜索并计算最大的值。
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    Coprime c(t);
}