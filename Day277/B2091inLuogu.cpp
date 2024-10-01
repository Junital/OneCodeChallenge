/*****************************************************************
 * 题目：向量点积计算
 * 描述：计算两个向量的点积。
 * 思路：遍历元素并乘积。
 * 函数：vector_dotproduct模拟向量点积。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

template <typename T>
T vector_dotproduct(vector<T> A, vector<T> B)
{
    T Sum = 0;
    assert(A.size() == B.size());

    int vec_size = A.size();
    rep(i, 0, vec_size - 1)
    {
        Sum += A[i] * B[i];
    }

    return Sum;
}

int main()
{
    int size;
    cin >> size;

    vector<int> a(size), b(size);

    rep(i, 0, size - 1)
    {
        cin >> a[i];
    }
    rep(i, 0, size - 1)
    {
        cin >> b[i];
    }

    cout << vector_dotproduct(a, b) << endl;
    return 0;
}
