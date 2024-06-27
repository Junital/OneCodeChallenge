/***********************************************
 * 题目：矩阵交换行
 * 描述：对一个矩阵中两行进行交换。
 * 思路：看看能不能swap一下。
 * 对象：MyMatrix模拟矩阵。
 * 注意：注意下标转换。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class MyMatrix
{
private:
    vector<vector<ll>> Elements;
    int RowNum; // 行数目
    int ColNum; // 列数目

public:
    /* 初始化输入列数目和行数目 */
    MyMatrix(int r, int c) : RowNum(r), ColNum(c)
    {
        /* 初始化矩阵的大小 */
        Elements.resize(RowNum);
        rep(i, 0, RowNum - 1)
        {
            Elements[i].resize(ColNum);
        }

        /* 对每一行，每一列进行输入 */
        rep(i, 0, RowNum - 1)
        {
            assert(Elements[i].size() > 0);
            rep(j, 0, ColNum - 1)
            {
                ll x;
                cin >> x;
                Elements[i][j] = x;
            }
        }
    }

    /* 求边缘元素和。 */
    ll VergeSum()
    {
        ll Sum = 0;

        /* 要注意到只有1行1列的情况。 */

        /* 第一行 */
        rep(j, 0, ColNum - 1)
        {
            Sum += Elements[0][j];
        }

        /* 中间的第一列和最后一列 */
        rep(i, 1, RowNum - 2)
        {
            Sum += Elements[i][0];
            Sum += Elements[i][ColNum - 1];
        }

        /* 最后一行 */
        if (RowNum - 1 != 0)
        {
            rep(j, 0, ColNum - 1)
            {
                Sum += Elements[RowNum - 1][j];
            }
        }

        return Sum;
    }

    /* 打印矩阵 */
    void print()
    {
        rep(i, 0, RowNum - 1)
        {
            rep(j, 0, ColNum - 1)
            {
                cout << Elements[i][j] << " ";
            }
            cout << endl;
        }
    }

    /* 换行 */
    void swap_row(int RowA, int RowB)
    {
        swap(Elements[RowA - 1], Elements[RowB - 1]);
    }
};

int main()
{
    const int rownum = 5;
    const int colnum = 5;

    MyMatrix mm(rownum, colnum);

    int rowa, rowb;
    cin >> rowa >> rowb;

    mm.swap_row(rowa, rowb);
    mm.print();
    return 0;
}