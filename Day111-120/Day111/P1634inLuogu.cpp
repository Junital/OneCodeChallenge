/***********************************************
 * 题目：禽兽的传染病
 * 描述：每次一只感染的禽兽会传染固定的数量禽兽，问几轮过后有多少只感染的禽兽。
 * 思路：感染一个的话就是1 2 4 8，每次×2。
 * 对象：Affect模拟传染。
 * 注意：溢出问题，求和可能ll。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                             // 定义长整型
#define rep(i, s, k) for (ll i = s; i <= k; i++) // 定义快速循环

/* 传染过程，输入传染因子和传染轮数。 */
ll Affect(ll AffectFactor, ll Turns)
{
    ll Beast = 1; // 禽兽数量

    rep(i, 1, Turns)
    {
        Beast *= (AffectFactor + 1); // 一轮感染
    }

    return Beast;
}

int main()
{
    ll affectfactor, turns;
    cin >> affectfactor >> turns;

    cout << Affect(affectfactor, turns) << endl;
    return 0;
}
