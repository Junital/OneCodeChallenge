/*****************************************************************
 * 题目：[NICA #1] 年金现值系数表
 * 描述：按照公式计算年金现值系数。
 * 思路：模拟。
 * 对象：APVCTable模拟年金现值系数表。
 * 注意：注意精度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class APVCTable
{
private:
    /* 计算APVC */
    double calAPVC(int DayNum, int Rate)
    {
        return (1 - pow(1 + Rate / 100.0, -DayNum)) / (Rate / 100.0);
    }

public:
    /* 制作表格，输入行数和列数。 */
    void make_table(int row_num, int col_num)
    {
        cout << "\t";
        rep(i, 1, col_num)
        {
            cout << i << "%";
            if (i != col_num)
            {
                cout << "\t";
            }
        }
        cout << endl;

        rep(i, 1, row_num)
        {
            cout << i << "\t";
            rep(j, 1, col_num)
            {
                cout << fixed << setprecision(4) << calAPVC(i, j);
                if (j != col_num)
                {
                    cout << "\t";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    int RowNum, ColNum;
    APVCTable apvct;

    cin >> RowNum >> ColNum;
    apvct.make_table(RowNum, ColNum);
    return 0;
}
