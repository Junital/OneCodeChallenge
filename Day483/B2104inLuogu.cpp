/*****************************************************************
 * 题目：矩阵加法
 * 描述：将两个矩阵相加。
 * 思路：对应元素相加。
 * 对象：MyMatrix模拟矩阵。
 * 注意：提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
    /* 四舍五入 */
    int Approximate(double Num)
    {
        double Ceil = ceil(Num);
        double Floor = floor(Num);

        if (Ceil - Num <= Num - Floor)
        {
            return (int)Ceil;
        }
        else
        {
            return (int)Floor;
        }
    }
};

using namespace Tools;

template <typename T>
class MyMatrix
{
private:
    vector<vector<T>> Elements;
    int RowNum; // 行数目
    int ColNum; // 列数目

public:
    /* 初始化输入列数目和行数目 */
    MyMatrix<T>(int r, int c) : RowNum(r), ColNum(c)
    {
        /* 初始化矩阵的大小 */
        Elements.resize(RowNum);
        for (int i = 0; i < RowNum; i++)
        {
            Elements[i].resize(ColNum);
        }

        /* 对每一行，每一列进行输入 */
        for (int i = 0; i < RowNum; i++)
        {
            assert(Elements[i].size() > 0);
            rep(j, 0, ColNum - 1)
            {
                T x;
                cin >> x;
                Elements[i][j] = x;
            }
        }
    }

    MyMatrix<T>(vector<vector<T>> matrix) : Elements(matrix)
    {
        RowNum = matrix.size();
        ColNum = matrix[0].size();

        for (int i = 1; i < RowNum; i++)
        {
            if (ColNum != matrix[i].size())
            {
                throw invalid_argument("The number of elements in each row of the matrix must be the same.");
            }
        }
    }

    /* 求边缘元素和。 */
    T VergeSum()
    {
        T Sum = 0;

        /* 要注意到只有1行1列的情况。 */

        /* 第一行 */
        for (int j = 0; j < ColNum; j++)
        {
            Sum += Elements[0][j];
        }

        /* 中间的第一列和最后一列 */
        for (int i = 1; i < RowNum - 1; i++)
        {
            Sum += Elements[i][0];
            Sum += Elements[i][ColNum - 1];
        }

        /* 最后一行 */
        if (RowNum - 1 != 0)
        {
            for (int j = 0; j < ColNum; j++)
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
            for (int k = 0; k < RowNum; k++)
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
    const vector<T> &
    operator[](int index) const
    {
        return Elements[index];
    }

    /* 重构加法。 */
    MyMatrix<T> operator+(const MyMatrix<T> &other)
    {
        vector<vector<T>> ans(RowNum, vector<T>(ColNum));

        if (this->RowNum != other.RowNum ||
            this->ColNum != other.ColNum)
        {
            throw runtime_error("The sizes of the two matrices must be exactly the same.");
        }

        for (int i = 0; i < RowNum; i++)
        {
            for (int j = 0; j < ColNum; j++)
            {
                ans[i][j] = this->operator[](i)[j] + other[i][j];
            }
        }

        return MyMatrix<T>(ans);
    }

    void print()
    {
        for (int i = 0; i < RowNum; i++)
        {
            for (int j = 0; j < ColNum; j++)
            {
                cout << this->operator[](i)[j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int row, col;
    cin >> row >> col;

    MyMatrix<int> m1(row, col), m2(row, col);

    auto m3 = m1 + m2;
    m3.print();
    return 0;
}