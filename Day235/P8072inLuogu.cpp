/*****************************************************************
 * 题目：[COCI2009-2010#7] COKOLADA
 * 描述：求出刚好大于等于某个数的2次幂，以及需要如何切几刀才能拿到指定单位。
 * 思路：位数计算 + 数学计算法。
 * 对象：Chocolate模拟巧克力。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class Chocolate
{
private:
    /* 得到大于等于某个数的二次幂。 */
    int large2pow(int Size)
    {
        double x = log2(Size);
        return 1 << (int)ceil(x);
    }

    /* 得到最少切割次数。 */
    int cut(int LargeSize, int Size)
    {
        int offset = Size & (-Size);
        return log2(LargeSize) - log2(offset);
    }

public:
    /* 输入所需大小，返回大巧克力的大小和切割次数。 */
    pair<int, int> buy(int Size)
    {
        int large_size = large2pow(Size);
        int cut_time = cut(large_size, Size);
        return make_pair(large_size, cut_time);
    }
};

int main()
{
    Chocolate c;
    int size;
    cin >> size;

    pair<int, int> ans = c.buy(size);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}
