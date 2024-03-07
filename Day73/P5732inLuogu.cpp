/***********************************************
 * 题目：【深基5.习7】杨辉三角
 * 描述：输入一个数字，输出一个杨辉三角。
 * 思路：存储三角，再输出。
 * 对象：YangHuiTri模拟杨辉三角。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class YangHuiTri
{
private:
    vector<vector<int>> Tri; // 存储杨辉三角
    int Row;                 // 行数

    void makeTri()
    {
        rep(i, 1, Row)
        {
            rep(j, 1, i)
            {
                if (j == 1 || j == i)
                {
                    Tri[i].push_back(1);
                }
                else
                {
                    Tri[i].push_back(Tri[i - 1][j - 2] + Tri[i - 1][j - 1]);
                }
            }
        }
    }

public:
    /* 初始化，输入需要的三角行数。 */
    YangHuiTri(int row) : Row(row)
    {
        Tri.resize(Row + 1);
        makeTri();
    }

    /* 输出杨辉三角。 */
    void print()
    {
        rep(i, 1, Row)
        {
            rep(j, 0, i - 1) // 数组是从0计数的。
            {
                cout << Tri[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int row;
    cin >> row;

    YangHuiTri yht(row);
    yht.print();
}
