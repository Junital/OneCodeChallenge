/*****************************************************************
 * 题目：[COCI2011-2012#2] NAJBOLJIH 5
 * 描述：找到最大的5个元素。
 * 思路：最大堆。
 * 对象：IdxHeap模拟带索引的堆。
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

template <typename T>
class IdxHeap
{
private:
    using PairType = pair<int, T>;
    priority_queue<PairType> idx_heap;

public:
    /* 初始化。 */
    IdxHeap(int size)
    {
        rep(i, 1, size)
        {
            T element;
            cin >> element;
            idx_heap.push(make_pair(element, i));
        }
    }

    /* 获得堆顶最大N个元素。 */
    pair<vector<T>, vector<int>> topN(int num)
    {
        int size = idx_heap.size();
        assert(size >= num);

        vector<int> indices;
        vector<T> elements;
        rep(i, 1, num)
        {
            auto pit = idx_heap.top();
            idx_heap.pop();
            elements.push_back(pit.first);
            indices.push_back(pit.second);
        }

        return make_pair(elements, indices);
    }
};

int main()
{
    const int size = 8;
    IdxHeap<int> ih(size);

    const int query = 5;
    auto res = ih.topN(query);

    cout << VectorExtensions::ArrSum(res.first) << endl;
    sort(res.second.begin(), res.second.end());
    for (auto e : res.second)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}