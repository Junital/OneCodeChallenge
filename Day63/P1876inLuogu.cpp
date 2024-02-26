/***********************************************
 * 题目：开灯
 * 描述：每次开关i的倍数的灯，问最后亮的灯。
 * 思路：素数一定会被关，必须是某个数的倍数a^2 = b，b才不会被关。
 * 函数：OddFactor来获得某个范围内的所有奇因子数。
 * 注意：注意范围限制，要用长整型。
 ***********************************************/

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