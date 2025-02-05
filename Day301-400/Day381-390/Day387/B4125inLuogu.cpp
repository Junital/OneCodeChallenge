/***********************************************
 * 题目：[语言月赛 202501] 知识竞赛
 * 描述：选出最高的一列，然后选出这列中最好的同学。
 * 思路：数组操作。
 * 空间：VectorExtentions模拟数组拓展。
 * 注意：注意提高可拓展性。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

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

class KnowledgeCompetition
{
private:
public:
    /* 请求，输入班级同学的知识水平，输出比赛后的结果。 */
    pair<int, int> query(vector<vector<int>> Class)
    {
        int row_num = Class.size();
        // int col_num = Class[0].size();

        vector<int> colsum = VectorExtensions::column_sum(Class);
        auto it = max_element(colsum.rbegin(), colsum.rend());

        int max_idx = colsum.size() - 1 -
                      distance(colsum.rbegin(), it);

        int count = 0;
        int max_num = 0;
        rep(i, 0, row_num - 1)
        {
            if (Class[i][max_idx] > max_num)
            {
                max_num = Class[i][max_idx];
                count = 1;
            }
            else if (Class[i][max_idx] == max_num)
            {
                count++;
            }
        }

        return make_pair(max_num, count);
    }
};

int main()
{
    KnowledgeCompetition kc;
    int rownum, colnum;
    cin >> rownum >> colnum;

    vector<vector<int>> Class(rownum);
    rep(i, 0, rownum - 1)
    {
        Class[i].resize(colnum);
        rep(j, 0, colnum - 1)
        {
            cin >> Class[i][j];
        }
    }

    auto res = kc.query(Class);
    cout << res.first << " " << res.second << endl;
    return 0;
}