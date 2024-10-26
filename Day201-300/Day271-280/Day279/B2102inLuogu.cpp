/***********************************************
 * 题目：计算鞍点
 * 描述：找到一个矩阵的鞍点（所在行最大值、所在列最小值）。
 * 思路：先找最大，再判断是否是最小。
 * 对象：MyMatrix模拟矩阵。
 * 注意：为对象添加接口。
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

    /* 求解鞍点。 */
    pair<int, int> find_saddlepoint()
    {
        int rowans = -1;
        int colans = -1;

        rep(i, 0, RowNum - 1)
        {
            auto rowmax = max_element(Elements[i].begin(),
                                      Elements[i].end());
            int j = rowmax - Elements[i].begin();
            // cout << j << endl;

            bool noless = true;
            rep(k, 0, RowNum - 1)
            {
                if (Elements[k][j] <= *rowmax && k != i)
                {
                    noless = false;
                    break;
                }
            }
            if (noless)
            {
                rowans = i;
                colans = j;
                break;
            }
        }

        return make_pair(rowans, colans);
    }

    /* 定位矩阵元素。 */
    const vector<ll> &
    operator[](int index) const
    {
        return Elements[index];
    }
};

int main()
{
    const int size = 5;
    MyMatrix mm(size, size);

    auto res = mm.find_saddlepoint();
    if (res.first == -1)
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << res.first + 1 << " " << res.second + 1
             << " " << mm[res.first][res.second] << endl;
    }
    return 0;
}