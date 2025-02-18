/*****************************************************************
 * 题目：[JOI2025 预选赛 R1H3] 现金
 * 描述：金钱计算。
 * 思路：数组相乘、再相加。
 * 空间：VectorExtensions模拟数组拓展。
 * 注意：最后的结果别溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

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
    const vector<int> money = {1000,
                               10000};

    const int size = money.size();
    vector<int> quantity(size);

    for (int i = 0; i < size; i++)
    {
        cin >> quantity[i];
    }

    cout << arr_sum(arr_multiply(quantity, money)) << endl;
    return 0;
}