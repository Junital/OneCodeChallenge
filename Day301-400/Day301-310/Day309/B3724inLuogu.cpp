/*****************************************************************
 * 题目：[语言月赛202303] Carrot Harvest G
 * 描述：在方格中，找到最小包括了k个元素的矩形。
 * 思路：嵌套遍历。
 * 对象：MinRectinGrid模拟网格中的最小矩形。
 * 注意：注意时间复杂度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class MinRectinGrid
{
private:
    vector<vector<bitset<1>>> Grid;
    vector<vector<int>> PreSum;
    int RowNum, ColNum;

    /* 计算前缀和。 */
    void init()
    {
        PreSum.resize(RowNum);
        rep(i, 0, RowNum - 1)
        {
            PreSum[i].resize(ColNum);
            rep(j, 0, ColNum - 1)
            {
                int left, top, left_top;

                if (i == 0)
                {
                    top = 0;
                    left_top = 0;
                }
                else
                {
                    top = PreSum[i - 1][j];
                }

                if (j == 0)
                {
                    left = 0;
                    left_top = 0;
                }
                else
                {
                    left = PreSum[i][j - 1];
                }

                if (i != 0 && j != 0)
                {
                    left_top = PreSum[i - 1][j - 1];
                }

                PreSum[i][j] = Grid[i][j].to_ulong() + left + top - left_top;
                // cout << PreSum[i][j] << " ";
            }
            // cout << endl;
        }
    }

public:
    /* 初始化，输入网格。 */
    MinRectinGrid(vector<vector<bitset<1>>> grid) : Grid(grid)
    {
        RowNum = Grid.size();
        assert(RowNum > 0);
        ColNum = Grid[0].size();
        rep(i, 0, RowNum - 1)
        {
            assert((int)Grid[i].size() == ColNum);
        }

        init();
    }

    /* 请求，输入需要的元素数量，输出矩形大小。 */
    int query(int Num)
    {
        int MinSize = RowNum * ColNum;
        rep(i, 0, RowNum - 1)
        {
            rep(j, 0, ColNum - 1)
            {
                rep(m, i, RowNum - 1)
                {
                    rep(n, j, ColNum - 1)
                    {
                        int left, top, left_top;

                        if (i == 0)
                        {
                            top = 0;
                            left_top = 0;
                        }
                        else
                        {
                            top = PreSum[i - 1][n];
                        }

                        if (j == 0)
                        {
                            left = 0;
                            left_top = 0;
                        }
                        else
                        {
                            left = PreSum[m][j - 1];
                        }

                        if (i != 0 && j != 0)
                        {
                            left_top = PreSum[i - 1][j - 1];
                        }

                        if (PreSum[m][n] + left_top - left - top >=
                            Num)
                        {
                            MinSize = min(MinSize,
                                          (m - i + 1) * (n - j + 1));
                        }
                    }
                }
            }
        }
        return MinSize;
    }
};

int main()
{
    vector<vector<bitset<1>>> grid;
    int rownum, colnum, query;
    cin >> rownum >> colnum >> query;

    grid.resize(rownum);
    rep(i, 0, rownum - 1)
    {
        grid[i].resize(colnum);
        rep(j, 0, colnum - 1)
        {
            cin >> grid[i][j];
        }
    }

    MinRectinGrid mrg(grid);
    cout << mrg.query(query) << endl;
    return 0;
}