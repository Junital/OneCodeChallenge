/**********************************************************
 * 题目：[传智杯 #3 练习赛] 直角三角形
 * 描述：直角三角形三条边都是整数，给出斜边，求出另外两条边。
 * 思路：x=2mn,y=m^2-n^2,z=m^2+n^2
 * 对象：PerfRiTriangle模拟完美直角三角形。
 * 注意：注意数据范围。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class PerfRiTriangle
{
private:
    map<int, int> Square2Num; // 某个数平方和对应的开方
    const int MAXNUM = 14100; // 最大的数

    /* 求最大公因数 */
    inline int gcd(int x, int y)
    {
        if (y == 0)
        {
            return x;
        }
        return gcd(y, x % y);
    }

    /* 初始化，将平方和处理好。 */
    void init()
    {
        int i = 1;
        while (i * i <= MAXNUM)
        {
            Square2Num[i * i] = i;
            i++;
        }
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

            if (Square2Num[Longest - square])
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
};

int main()
{
    PerfRiTriangle prt;

    int longest;
    cin >> longest;

    pair<int, int> sides = prt.get_other_sides(longest);
    cout << sides.first << " " << sides.second << endl;
    return 0;
}
