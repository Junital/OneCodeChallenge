/*********************************************************
 * 题目：[GESP样题 二级] 勾股数
 * 描述：输出斜边小于某个数的勾股数数量。
 * 思路：用之前的直角三角形对象。
 * 对象：PerfRiTriangle模拟完美直角三角形。
 * 注意：注意时间复杂度，一条斜边可能有多组。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class PerfRiTriangle
{
private:
    map<int, int> Square2Num;   // 某个数平方和对应的开方
    vector<int> PossibleTri;    // 可行的完美三角形
    const int MAXNUM = 2000000; // 最大的数

    /* 求最大公因数 */
    inline int gcd(int x, int y)
    {
        if (y == 0)
        {
            return x;
        }
        return gcd(y, x % y);
    }

    /* 判断某条斜边能否构成完美三角形。 */
    int judge(int Longest)
    {
        int count = 0;
        int long_square = Longest * Longest;

        for (auto it : Square2Num)
        {
            int square = it.first;

            /* 终止条件 */
            if (square > long_square / 2)
            {
                break;
            }

            if (Square2Num.find(long_square - square) != Square2Num.end())
            {
                count++;
            }
        }

        return count;
    }

    /* 初始化，将平方和处理好，将可能的斜边放在数组中。 */
    void init()
    {
        int i = 1;
        while (i * i <= MAXNUM)
        {
            Square2Num[i * i] = i;
            i++;
        }

        // cout << Square2Num.size() << endl;

        rep(j, 1, sqrt(MAXNUM))
        {
            int tri_count = judge(j);
            rep(k, 1, tri_count)
            {
                PossibleTri.push_back(j);
            }
        }
        // cout << endl;
    }

public:
    PerfRiTriangle()
    {
        init();
    }

    /* 输入一个斜边，通过遍历求得m,n，从而算出其他两条边。 */
    pair<int, int> get_other_sides(int Longest)
    {
        int middle_ans = -1;
        int short_ans = MAXNUM;
        for (auto sn_pair : Square2Num)
        {
            int square = sn_pair.first;
            int n = sn_pair.second;

            /* 终止条件 */
            if (square > Longest / 2)
            {
                break;
            }

            if (Square2Num.find(Longest - square) != Square2Num.end())
            {
                int m = Square2Num[Longest - square];

                /* 互质，并且奇偶相异。 */
                // if (gcd(m, n) == 1 && m % 2 != n % 2)
                // {
                int middle_side = m * m - n * n;
                int short_side = 2 * m * n;

                /* 交换 */
                if (middle_side < short_side)
                {
                    swap(middle_side, short_side);
                }

                /* 选择最后的答案 */
                if (short_side < short_ans)
                {
                    short_ans = short_side;
                    middle_ans = middle_side;
                }
                // }
            }
        }

        assert(middle_ans != -1);

        return make_pair(short_ans, middle_ans);
    }

    /* 输入范围，求出范围内可能的完美三角形。 */
    int count(int Limit)
    {
        // cout << PossibleTri.size() << endl;
        return upper_bound(PossibleTri.begin(), PossibleTri.end(), Limit) -
               PossibleTri.begin();
    }
};

int main()
{
    PerfRiTriangle prt;
    int limit;

    cin >> limit;
    cout << prt.count(limit) << endl;

    return 0;
}