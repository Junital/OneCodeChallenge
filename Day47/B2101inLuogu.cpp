/***********************************************
 * 题目：计算矩阵边缘元素之和
 * 描述：求矩阵第一行、最后一行、第一列、最后一列元素之和。
 * 思路：简单求和。
 * 对象：Matrix矩阵。
 * 注意：结果小心别溢出。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速定义循环
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
};

int main()
{
    int RowNum, ColNum;
    cin >> RowNum >> ColNum;

    MyMatrix m(RowNum, ColNum);

    cout << m.VergeSum() << endl;
}