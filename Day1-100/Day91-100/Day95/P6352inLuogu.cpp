/***********************************************
 * 题目：[COCI2007-2008#3] CETIRI
 * 描述：给出等差数列中的三个数，求出第四个数。
 * 思路：求数列差。
 * 对象：IncompleteSeqNum模拟不完全的数列。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 不完整的等差数列。 */
class IncompleteSeqNum
{
private:
    vector<int> Seq;    // 目前的数列
    map<int, int> Diff; // 统计两个元素的差

    /* 计算前后两个元素的差。 */
    void getDiff()
    {
        int SeqSize = Seq.size();

        rep(i, 1, SeqSize - 1)
        {
            Diff[Seq[i] - Seq[i - 1]]++;
        }
    }

public:
    /* 初始化，输入不完整的数列。 */
    IncompleteSeqNum(vector<int> seq) : Seq(seq)
    {
        sort(Seq.begin(), Seq.end());
        getDiff();
    }

    /* 找到缺的元素 */
    int find()
    {
        int SeqSize = Seq.size();

        if (Diff.size() == 1)
        {
            return Seq[SeqSize - 1] + Diff.begin()->first; // 最后一个数 + 方差
        }
        else if (Diff.size() == 2)
        {
            map<int, int>::iterator it = Diff.begin();
            int d1 = it->first;
            it++;
            int d2 = it->first;

            // cout << d1 << " " << d2 << endl;

            if (d2 == d1 * 2)
            {
                rep(i, 1, SeqSize - 1)
                {
                    if (Seq[i] - Seq[i - 1] == d2)
                    {
                        return Seq[i - 1] + d1;
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    const int seqsize = 3;
    vector<int> seq(seqsize);

    rep(i, 0, seqsize - 1)
    {
        cin >> seq[i];
    }

    IncompleteSeqNum ism(seq);

    cout << ism.find() << endl;
    return 0;
}
