/*****************************************************************
 * 题目：[语言月赛202210] 垃圾分类
 * 描述：每个垃圾桶都有容量，如果溢出就需要按件数收费。
 * 思路：数组相减、求和。
 * 空间：VectorExtensions模拟数组拓展。
 * 注意：小心空间、int溢出。
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
    int bin_num, charge_per_item;
    cin >> bin_num >> charge_per_item;

    i64 total_charge = 0;
    vector<i64> bin_capacity(bin_num);

    rep(i, 0, bin_num - 1)
    {
        cin >> bin_capacity[i];
    }

    rep(i, 0, bin_num - 1)
    {
        i64 current_capacity;
        cin >> current_capacity;

        i64 overflow = current_capacity - bin_capacity[i];
        if (overflow > 0)
        {
            total_charge += overflow * charge_per_item;
        }
    }

    cout << total_charge << endl;

    return 0;
}