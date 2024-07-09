/***********************************************
 * 题目：同行列对角线的格
 * 描述：根据格子的坐标，输出同行、同列、同对角线的格子坐标。
 * 思路：先找到首个坐标，然后依次输出。
 * 对象：Grid模拟网格。
 * 注意：不能有遗漏，注意覆盖所有情况。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Grid
{
private:
    int RowNum, ColNum; // 行数列数

    /* 输出格子坐标 */
    void print(int Row, int Col)
    {
        printf("(%d,%d)", Row, Col);
    }

    /* 输出一行的点。 */
    void RowLine(int RowIdx)
    {
        rep(i, 1, ColNum)
        {
            print(RowIdx, i);
            cout << " ";
        }
        cout << endl;
    }

    /* 输出一列的点。 */
    void ColLine(int ColIdx)
    {
        rep(i, 1, RowNum)
        {
            print(i, ColIdx);
            cout << " ";
        }
        cout << endl;
    }

    /* 输出主对角线的点。 */
    void MainDiagLine(int RowIdx, int ColIdx)
    {
        int StartRow, StartCol;
        if (RowIdx < ColIdx)
        {
            StartRow = 1;
            StartCol = ColIdx - RowIdx + 1;
        }
        else
        {
            StartRow = RowIdx - ColIdx + 1;
            StartCol = 1;
        }

        int i = StartRow, j = StartCol;
        while (i <= RowNum && j <= ColNum)
        {
            print(i, j);
            cout << " ";
            i += 1;
            j += 1;
        }
        cout << endl;
    }

    /* 输出副对角线的点。 */
    void ViceDiagLine(int RowIdx, int ColIdx)
    {
        int StartRow, StartCol;
        if (RowNum - RowIdx + 1 < ColIdx)
        {
            StartRow = RowNum;
            StartCol = ColIdx - (RowNum - RowIdx);
        }
        else
        {
            StartRow = ColIdx - 1 + RowIdx;
            StartCol = 1;
        }

        int i = StartRow, j = StartCol;
        while (i >= 1 && j <= ColNum)
        {
            print(i, j);
            cout << " ";
            j += 1;
            i -= 1;
        }
        cout << endl;
    }

public:
    /* 初始化，输入行列数。 */
    Grid(int Row, int Col) : RowNum(Row), ColNum(Col)
    {
    }

    /* 找到在所有在一条线上的格子。 */
    void find_all_in_line(int RowIdx, int ColIdx)
    {
        RowLine(RowIdx);
        ColLine(ColIdx);
        MainDiagLine(RowIdx, ColIdx);
        ViceDiagLine(RowIdx, ColIdx);
    }
};

int main()
{
    int size, rowidx, colidx;
    cin >> size >> rowidx >> colidx;

    Grid grid(size, size);
    grid.find_all_in_line(rowidx, colidx);
    return 0;
}
