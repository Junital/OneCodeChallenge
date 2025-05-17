/*****************************************************************
 * 题目：String Minimization
 * 描述：交换两个字符串的元素，会连带着交换另外两个。
 *      问在第一组出现最小字典序的情况下，第二组最小字典序字符串是什么？
 * 思路：一样可换可不换、小于必须换、大于绝对不能换。
 * 对象：DualStringPair模拟双字符串对。
 * 注意：提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
    /* 四舍五入 */
    int Approximate(double Num)
    {
        double Ceil = ceil(Num);
        double Floor = floor(Num);

        if (Ceil - Num <= Num - Floor)
        {
            return (int)Ceil;
        }
        else
        {
            return (int)Floor;
        }
    }
};

using namespace Tools;

/* 双字符串对。 */
class DualStringPair
{
private:
    pair<string, string> Pair1;
    pair<string, string> Pair2;

public:
    DualStringPair(pair<string, string> pair1,
                   pair<string, string> pair2)
        : Pair1(pair1), Pair2(pair2)
    {
        int len1 = Pair1.first.size();
        int len2 = Pair1.second.size();
        int len3 = Pair2.first.size();
        int len4 = Pair2.second.size();

        if (!(len1 == len2 && len2 == len3 && len3 == len4))
        {
            throw invalid_argument("The lengths of strings in two string pairs must be the same.");
        }
    }

    /* 获得字符对。 */
    pair<pair<char, char>, pair<char, char>> get_dual_char_pair(int idx)
    {
        int Len = Pair1.first.size();

        if (idx >= Len || idx < 0)
        {
            throw invalid_argument("Index is out of string length.");
        }
        return make_pair(make_pair(Pair1.first[idx],
                                   Pair1.second[idx]),
                         make_pair(Pair2.first[idx],
                                   Pair2.second[idx]));
    }

    /* 两个字符串对同时交换某个索引上的字符。 */
    void both_swap(int idx)
    {
        int Len = Pair1.first.size();

        if (idx >= Len || idx < 0)
        {
            throw invalid_argument("Index is out of string length.");
        }

        swap(Pair1.first[idx], Pair1.second[idx]);
        swap(Pair2.first[idx], Pair2.second[idx]);
    }

    /* 获取配对1。 */
    pair<string, string> get_pair_1()
    {
        return Pair1;
    }

    /* 获取配对2。 */
    pair<string, string> get_pair_2()
    {
        return Pair2;
    }
};

int main()
{
    int len;
    cin >> len;

    pair<string, string> p1, p2;

    cin >> p1.first >> p2.first;
    cin >> p1.second >> p2.second;

    DualStringPair dsp(p1, p2);
    rep(i, 0, len - 1)
    {
        auto chpp = dsp.get_dual_char_pair(i);
        if (chpp.first.first == chpp.first.second)
        {
            if (chpp.second.first > chpp.second.second)
            {
                dsp.both_swap(i);
            }
        }
        else if (chpp.first.first > chpp.first.second)
        {
            dsp.both_swap(i);
        }
    }

    cout << dsp.get_pair_2().first << endl;
    return 0;
}