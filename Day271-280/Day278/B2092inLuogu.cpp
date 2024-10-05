/*****************************************************************
 * 题目：开关灯
 * 描述：将某个数的倍数进行开关灯，看最后剩下几个。
 * 思路：找到能整数开方的。
 * 函数：OddFactor来获得某个范围内的所有奇因子数。
 * 注意：注意移植稳定性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速定义循环
#define ll long long                              // 定义长整型

vector<ll> OddFactor(ll Threshold)
{
    vector<ll> Answers; // 记录结果
    ll Iter = 1;        // 迭代元素

    while (true)
    {
        ll Candi = Iter * Iter; // 候选结果
        if (Candi <= Threshold)
        {
            Answers.push_back(Candi);
            Iter++;
        }
        else
        {
            break;
        }
    }

    return Answers;
}

int main()
{
    ll thres;

    cin >> thres;

    vector<ll> answers = OddFactor(thres);

    for (auto answer : answers)
    {
        cout << answer << " ";
    }

    cout << endl;
    return 0;
}
