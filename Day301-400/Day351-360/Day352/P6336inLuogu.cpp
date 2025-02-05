/*****************************************************************
 * 题目：[COCI2007-2008#2] BIJELE
 * 描述：问每类棋子还差多少。
 * 思路：将两个数组进行相减。
 * 空间：VectorExtensions模拟数组拓展。
 * 注意：注意提升可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

namespace VectorExtensions
{
    /* 定义数组求和 */
    template <typename Type>
    Type ArrSum(vector<Type> &Arr)
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
}

int main()
{
    const vector<int> Standard = {1, 1, 2, 2, 2, 8};
    const int size = Standard.size();

    vector<int> Current(size);
    rep(i, 0, size - 1)
    {
        cin >> Current[i];
    }

    auto res = VectorExtensions::arr_subtract(Standard, Current);
    for (auto element : res)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}