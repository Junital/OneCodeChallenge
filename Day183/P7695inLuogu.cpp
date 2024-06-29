/***********************************************
 * 题目：[COCI2009-2010#4] PLANINA
 * 描述：根据迭代次数，输出有几个中点位。
 * 思路：数学阶段得出(2^i+1)^2。
 * 对象：PLANINA模拟中点数量计算。
 * 注意：注意数据范围。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class PLANINA
{
private:
    /* 快速幂 */
    int binpow(int a, int b)
    {
        long long res = 1;
        while (b > 0)
        {
            if (b & 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }

public:
    /* 输入迭代次数，计算中点数量。 */
    int cal(int ItNum)
    {
        return binpow((1 << ItNum) + 1, 2);
    }
};

int main()
{
    PLANINA planina;
    int itnum;
    cin >> itnum;

    cout << planina.cal(itnum) << endl;
    return 0;
}