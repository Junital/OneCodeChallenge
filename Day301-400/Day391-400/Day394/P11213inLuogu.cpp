/*****************************************************************
 * 题目：【MX-J8-T1】竹竿
 * 描述：每个竹竿有一处标记，在标记重叠的基础上，求最大能覆盖的长度。
 * 思路：排序，以两者的最大值作为排序依据。
 * 对象：MaxPair模拟配对，按照最大元素进行排列。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class MaxPair
{
private:
    int A, B;

public:
    MaxPair(int a, int b) : A(a), B(b) {}

    int get_greater() { return max(A, B); }

    int get_less() { return min(A, B); }

    bool operator<(const MaxPair &other) const
    {
        return max(A, B) < max(other.A, other.B);
    }

    bool operator>(const MaxPair &other) const
    {
        return max(A, B) > max(other.A, other.B);
    }
};

int main()
{
    int size;
    cin >> size;
    vector<MaxPair> Sticks;

    rep(i, 0, size - 1)
    {
        int len, mark;
        cin >> len >> mark;
        Sticks.push_back(MaxPair(len - mark, mark));
    }

    sort(Sticks.begin(), Sticks.end(), greater<MaxPair>());

    cout << Sticks[0].get_greater() + max(Sticks[0].get_less(),
                                          Sticks[1].get_greater())
         << endl;
    return 0;
}