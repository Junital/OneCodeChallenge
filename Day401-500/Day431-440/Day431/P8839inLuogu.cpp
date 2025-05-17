/*****************************************************************
 * 题目：[传智杯 #4 初赛] 组原成绩
 * 描述：计算综合分数。
 * 思路：数组操作。
 * 空间：VectorExtensions模拟数组拓展。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

namespace VectorExtensions
{
    /* 定义数组求和 */
    template <typename Type>
    Type arr_sum(vector<Type> Arr)
    {
        Type Sum = 0;
        for (auto element : Arr)
        {
            Sum += element;
        }
        return Sum;
    }

    /* 某个索引后的最小值。 */
    template <typename Type>
    Type SubArrMin(vector<Type> &Arr, int Index)
    {
        int Size = Arr.size();
        assert(Index < Size);

        auto start = Arr.begin() + Index;
        return *(min_element(start, Arr.end()));
    }

    // 交换数组中两个元素
    template <typename Type>
    void swapElements(std::vector<Type> &arr, int index1, int index2)
    {
        if (index1 < 0 || index1 >= arr.size() || index2 < 0 || index2 >= arr.size())
        {
            std::cerr << "Error: Indices out of bounds." << std::endl;
            return;
        }

        // Swapping the elements
        Type temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    // 将数组视为最大堆，将最大元素退出。
    template <typename Type>
    Type pop_max(vector<Type> &arr)
    {
        pop_heap(arr.begin(), arr.end());
        Type res = arr.back();
        arr.pop_back();

        return res;
    }

    // 将两个数组进行相加。
    template <typename Type>
    vector<Type> arr_add(vector<Type> A, vector<Type> B)
    {
        if (A.size() != B.size())
        {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        vector<Type> result(A.size());
        for (size_t i = 0; i < A.size(); ++i)
        {
            result[i] = A[i] + B[i];
        }
        return result;
    }

    // 将两个数组进行相减。
    template <typename Type>
    vector<Type> arr_subtract(vector<Type> A, vector<Type> B)
    {
        if (A.size() != B.size())
        {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        vector<Type> result(A.size());
        for (size_t i = 0; i < A.size(); ++i)
        {
            result[i] = A[i] - B[i];
        }
        return result;
    }

    // 两个数组相乘
    template <typename Type>
    vector<Type> arr_multiply(vector<Type> A, vector<Type> B)
    {
        if (A.size() != B.size())
        {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        vector<Type> result(A.size());
        for (size_t i = 0; i < A.size(); ++i)
        {
            result[i] = A[i] * B[i];
        }
        return result;
    }

    // 输入数组和权重，输出加权后的结果。
    template <typename Type>
    vector<Type> arr_multiply(vector<Type> Arr, Type Weight)
    {
        vector<Type> result(Arr.size());
        for (size_t i = 0; i < Arr.size(); ++i)
        {
            result[i] = Arr[i] * Weight;
        }
        return result;
    }

    // 输入二维数组，输出列向总和。
    template <typename Type>
    vector<Type> column_sum(vector<vector<Type>> Matrix)
    {
        int row_num = Matrix.size();
        int col_num = Matrix[0].size();

        vector<Type> res(col_num);
        for (int i = 0; i < row_num; i++)
        {
            assert((int)Matrix[i].size() == col_num);
            for (int j = 0; j < col_num; j++)
            {
                res[j] += Matrix[i][j];
            }
        }

        return res;
    }
};

using namespace VectorExtensions;

int main()
{
    const vector<double> weights = {0.2, 0.3, 0.5};
    vector<double> scores(weights.size());

    rep(i, 0, weights.size() - 1)
    {
        cin >> scores[i];
    }

    cout << (int)arr_sum(arr_multiply(weights, scores)) << endl;
    return 0;
}