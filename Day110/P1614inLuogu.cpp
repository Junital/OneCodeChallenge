/***********************************************
 * 题目：爱与愁的心痛
 * 描述：求连续m个数字最小和。
 * 思路：或许直接遍历一遍即可。
 * 对象：MinSum模拟最小和。
 * 注意：逻辑问题，注意多写注释。
        溢出问题，求和可能ll。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

/* 可以求出一个数组中m个连续数的最小值。 */
class MinSum
{
public:
    /* 直接计算吧, 输入数组和连续数。 */
    ll getMinSum(vector<int> Seq, int Contin)
    {
        int SeqSize = Seq.size(); // 数组长度

        ll Sum = 0; // 求和，模拟每m个数的和。
        rep(i, 0, Contin - 1)
        {
            Sum += Seq[i];
        }
        ll MinSum = Sum; // 最小和，初始化为第一次求和

        /* 开始遍历迭代最小和 */
        rep(ce, Contin, SeqSize - 1) // ce表示连续数最后一个数的位置
        {
            Sum -= Seq[ce - Contin]; // 减去之前最前面的数
            Sum += Seq[ce];          // 加上现在最后面的数

            MinSum = min(MinSum, Sum);
        }

        return MinSum;
    }
};

int main()
{
    MinSum ms;
    int seqsize, contin;

    cin >> seqsize >> contin;

    vector<int> seq(seqsize);

    rep(i, 0, seqsize - 1)
    {
        cin >> seq[i];
    }

    cout << ms.getMinSum(seq, contin);
    return 0;
}