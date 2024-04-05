/***********************************************
 * 题目：[NOIP1997 普及组] 棋盘问题
 * 描述：输入一个棋盘，输出其中包含的正方形数和长方形数。
 * 思路：先试试，找规律。
 * 对象：GridBoard模拟棋盘。
 * 注意：注意结果别溢出。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class GridBoard
{
private:
    int Row; // 行
    int Col; // 列

    /* 差为1的等差数列求和 */
    int seqSum(int Num)
    {
        return Num * (Num + 1) / 2;
    }

    /* 计算总共能组合的形状。 */
    int calTotal()
    {
        return seqSum(Col) * seqSum(Row);
    }

    /* 计算正方形的数量。 */
    int calSquare()
    {
        int Sum = 0;

        rep(i, 1, min(Row, Col))
        {
            Sum += (Row - i + 1) * (Col - i + 1);
        }

        return Sum;
    }

public:
    /* 初始化，输入行数，列数。 */
    GridBoard(int row, int col) : Row(row), Col(col)
    {
        int squareNum = calSquare();
        int rectNum = calTotal() - squareNum;

        cout << squareNum << " " << rectNum << endl;
    }
};

int main()
{
    int row, col;
    cin >> row >> col;

    GridBoard gb(row, col);
}