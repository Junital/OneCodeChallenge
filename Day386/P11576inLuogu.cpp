/***********************************************
 * 题目：[CCC2020] Dog Treats
 * 描述：输入各种零食数量，根据综合得分判断开心还是伤心。
 * 思路：数学计算。
 * 空间：VectorExtentions模拟数组拓展。
 * 注意：注意提高可拓展性。
 ***********************************************/

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
};

int main()
{
    const vector<int> weight = {1, 2, 3};
    const int size = weight.size();
    const int threshold = 10;

    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    if (VectorExtensions::arr_sum(
            VectorExtensions::arr_multiply(arr, weight)) >= threshold)
    {
        cout << "happy" << endl;
    }
    else
    {
        cout << "sad" << endl;
    }
    return 0;
}