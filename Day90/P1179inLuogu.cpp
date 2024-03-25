/***********************************************
 * 题目：[NOIP2010 普及组] 数字统计
 * 描述：统计数字2出现的个数。
 * 思路：统计。
 * 对象：NumberTwo统计数字2出现的个数。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class NumberTwo
{
private:
    const int Two = 2;
    /* 统计单个数字中2的个数 */
    int SingleNum(int Num)
    {
        int Sum = 0;
        while (Num != 0)
        {
            if (Num % 10 == Two)
            {
                Sum++;
            }
            Num /= 10;
        }

        return Sum;
    }

public:
    /* 输入最小值和最大值，输出区间内2出现的次数。 */
    int stats(int Left, int Right)
    {
        int Sum = 0;
        rep(i, Left, Right)
        {
            Sum += SingleNum(i);
        }

        return Sum;
    }
};

int main()
{
    int left, right;
    NumberTwo nt;

    cin >> left >> right;

    cout << nt.stats(left, right) << endl;

    return 0;
}