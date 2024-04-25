/**********************************************************
 * 题目：Uim的情人节礼物·其之壱
 * 描述：求出一个序列的前一个字典序。
 * 思路：STL。
 * 函数：PreviousPermutation返回前一个字典序。
 * 注意：无。
 *********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 用prev_permutation函数来获得上一个字典序，如果没有应该会返回false */
pair<bool, vector<int>> PreviousPermutation(vector<int> seq)
{
    vector<int> Seq = seq;

    if (prev_permutation(Seq.begin(), Seq.end()))
    {
        return make_pair(true, Seq);
    }
    else
    {
        return make_pair(false, Seq);
    }
}

int main()
{
    int Num;
    vector<int> Seq;
    cin >> Num;

    Seq.resize(Num);

    rep(i, 0, Num - 1)
    {
        cin >> Seq[i];
    }

    pair<bool, vector<int>> Ans = PreviousPermutation(Seq);

    if (Ans.first)
    {
        for (auto element : Ans.second)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "ERROR" << endl;
    }
    return 0;
}