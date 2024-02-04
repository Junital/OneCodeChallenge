/***********************************************
 * 题目：[USACO19DEC] Cow Gymnastics B
 * 描述：在众多排列中，找到相对位置一直保持不变的对数。
 * 思路：暴力搜索。
 * 对象：ConsistentPair来寻找序列中相对位置不变的对子。
 * 注意：要搜索完全。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义循环

class ConsistentPair
{
private:
    vector<vector<int>> Seqs;
    int SeqNum;
    int SeqLen;

    /* 通过序列ID和元素来寻找对应的位置。 */
    int findIdx(int SeqID, int Element)
    {
        vector<int> seq = Seqs[SeqID];

        rep(i, 0, SeqLen - 1)
        {
            if (Element == seq[i])
            {
                return i;
            }
        }

        return -1;
    }

public:
    /* 获取相对位置没变的对数。*/
    int getConsistentPair()
    {
        vector<int> initialSeq = Seqs[0]; // 初始序列
        int CPNum = 0;                    // 恒定对的个数

        rep(i, 0, SeqLen - 1)
        {
            rep(j, i + 1, SeqLen - 1)
            {
                int isCP = true;                  // 用于判断是否是恒定对
                int leftElement = initialSeq[i];  // 左侧元素
                int rightElement = initialSeq[j]; // 右侧元素

                rep(k, 1, SeqNum - 1)
                {
                    int i_idx = findIdx(k, leftElement);
                    int j_idx = findIdx(k, rightElement);
                    assert(i_idx != -1 || j_idx != -1);

                    if (i_idx > j_idx)
                    {
                        isCP = false; // 标为不是恒定对
                        break;
                    }
                }

                if (isCP)
                {
                    CPNum++; // 如果是恒定对，就数量+1
                }
            }
        }

        return CPNum;
    }

    /* 初始化时，输入多少个序列和序列的长度。 */
    ConsistentPair(int sn, int sl) : SeqNum(sn), SeqLen(sl)
    {
        Seqs.resize(SeqNum);

        rep(i, 0, SeqNum - 1)
        {
            rep(j, 1, SeqLen)
            {
                int x;
                cin >> x;
                Seqs[i].push_back(x);
            }
        }
    }
};

int main()
{
    int SeqNum, SeqLen;
    cin >> SeqNum >> SeqLen;

    ConsistentPair cp(SeqNum, SeqLen);

    cout << cp.getConsistentPair() << endl;
}