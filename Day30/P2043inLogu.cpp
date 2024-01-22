/*************************************
 * 题目：质因子分解
 * 描述：输入一个数字，输出这个数的累乘质因数分解后的结果。
 * 思路：边累乘，边分解。
 * 函数：SplitLargeNumber用于分解。
 *************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++)

/* 输入一个数字，输出这个数字累乘，质因数分解后的结果。 */
map<int, int> SplitLargeNumber(int Num)
{
    map<int, int> Prime;

    rep(i, 1, Num)
    {
        int p = 2; // 质数，一开始为2
        int num = i;

        /* 开始对每个数进行质因数分解。 */
        while (true)
        {
            if (num == 1)
            {
                break;
            }

            while (num % p == 0)
            {
                Prime[p]++;
                num /= p;
            }
            p++; // 每次移动到下一个数，只有素数才会在循环停留。
        }
    }

    return Prime;
}

int main()
{
    int Num;

    cin >> Num;

    map<int, int> Prime = SplitLargeNumber(Num);

    for (auto prime : Prime)
    {
        cout << prime.first << " " << prime.second << endl;
    }

    return 0;
}