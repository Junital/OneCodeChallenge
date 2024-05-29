/**********************************************************
 * 题目：[COCI2007-2008#2] CRNE
 * 描述：一个矩形，沿着边平行切n刀，最多能切成几块。
 * 思路：横竖交叉切。P6337Solve
 * 对象：CutRectangle模拟切矩形。
 * 注意：注意多种情况。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class CutRectangle
{
private:
    /* 获得一个维度的块数。 */
    int getdim(int cut)
    {
        return cut + 1;
    }

public:
    /* 输入切的次数，输出最多的块数。 */
    int cut(int CutNum)
    {
        int RowCut = CutNum / 2;
        int ColCut = RowCut + CutNum % 2;

        return getdim(RowCut) * getdim(ColCut);
    }
};

int main()
{
    CutRectangle cr;

    int cutnum;
    cin >> cutnum;

    cout << cr.cut(cutnum) << endl;
    return 0;
}
