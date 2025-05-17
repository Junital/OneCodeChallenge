/*****************************************************************
 * 题目：矩阵转置
 * 描述：计算矩阵的转置。
 * 思路：构建一个自我转置和返回新矩阵转置。
 * 对象：MyMatrix模拟矩阵。
 * 注意：
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
    size_t RowNum; // 行数目
    size_t ColNum; // 列数目

public:
    /* 初始化输入列数目和行数目 */
    MyMatrix<T>(size_t r, size_t c) : RowNum(r), ColNum(c)
    {
        /* 初始化矩阵的大小 */
        Elements.resize(RowNum);
        for (size_t i = 0; i < RowNum; i++)
        {
            Elements[i].resize(ColNum);
        }

        /* 对每一行，每一列进行输入 */
        for (size_t i = 0; i < RowNum; i++)
        {
            assert(Elements[i].size() > 0);
            for (size_t j = 0; j < ColNum; j++)
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

        for (size_t i = 1; i < RowNum; i++)
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
        for (size_t j = 0; j < ColNum; j++)
        {
            Sum += Elements[0][j];
        }

        /* 中间的第一列和最后一列 */
        for (size_t i = 1; i < RowNum - 1; i++)
        {
            Sum += Elements[i][0];
            Sum += Elements[i][ColNum - 1];
        }

        /* 最后一行 */
        if (RowNum - 1 != 0)
        {
            for (size_t j = 0; j < ColNum; j++)
            {
                Sum += Elements[RowNum - 1][j];
            }
        }

        return Sum;
    }

    /* 求解鞍点。 */
    pair<size_t, size_t> find_saddlepoint()
    {
        size_t rowans = -1;
        size_t colans = -1;

        rep(i, 0, RowNum - 1)
        {
            auto rowmax = max_element(Elements[i].begin(),
                                      Elements[i].end());
            size_t j = rowmax - Elements[i].begin();
            // cout << j << endl;

            bool noless = true;
            for (size_t k = 0; k < RowNum; k++)
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
    operator[](size_t index) const
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

        for (size_t i = 0; i < RowNum; i++)
        {
            for (size_t j = 0; j < ColNum; j++)
            {
                ans[i][j] = this->operator[](i)[j] + other[i][j];
            }
        }

        return MyMatrix<T>(ans);
    }

    /* 打印矩阵。 */
    void print()
    {
        for (size_t i = 0; i < RowNum; i++)
        {
            for (size_t j = 0; j < ColNum; j++)
            {
                cout << this->operator[](i)[j] << " ";
            }
            cout << endl;
        }
    }

    /* 转置。 */
    MyMatrix<T> transpose() const
    {
        vector<vector<T>> result(ColNum, vector<T>(RowNum));

        for (size_t i = 0; i < RowNum; ++i)
            for (size_t j = 0; j < ColNum; ++j)
                result[j][i] = Elements[i][j];

        return MyMatrix<T>(result);
    }

    /* 自我转置。 */
    void transposeInPlace()
    {
        vector<vector<T>> result(ColNum, vector<T>(RowNum));

        for (size_t i = 0; i < RowNum; ++i)
            for (size_t j = 0; j < ColNum; ++j)
                result[j][i] = Elements[i][j];

        Elements = result;
        swap(RowNum, ColNum);
    }
};

int main()
{
    int r, c;
    cin >> r >> c;

    MyMatrix<int> M(r, c);
    M.transposeInPlace();
    M.print();
    return 0;
}