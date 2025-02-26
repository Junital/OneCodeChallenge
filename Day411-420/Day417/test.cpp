#include <bits/stdc++.h>

using namespace std;

/* 存储数组、整数变量。 */
struct Variable
{
    vector<int> Dimensions; // 数组维度
    vector<int> Values;     // 数组值
    int DimenSize;          // 维度数量

    /* 初始化，输入维度，获取内存。 */
    Variable(vector<int> dimens)
        : Dimensions(dimens), DimenSize(dimens.size())
    {
        int size = 1;
        for (auto d : Dimensions)
        {
            size *= d;
        }

        Values.resize(size, 0);
    }

    /* 获得索引。 */
    int get_idx(vector<int> Idx)
    {
        int idx_size = Idx.size();
        // cout << idx_size << " ";
        assert(idx_size == DimenSize);
        int idx = 0;
        int base = 1;
        for (int i = 0; i < DimenSize; i++)
        {
            // cout << Idx[i] << " " << Dimensions[i] << " ";
            assert(Idx[i] < Dimensions[i]);
            idx += Idx[i] * base;
            base *= Dimensions[i];
        }

        return idx;
    }

    /* 输入维度，输出对应的值。 */
    int *at(vector<int> Idx)
    {
        int idx = get_idx(Idx);

        return &Values[idx];
    }

    /* 设置对应的值。 */
    void assgin(vector<int> Idx, int value)
    {
        *at(Idx) = value;
    }

    /* 大小。 */
    size_t size()
    {
        return Values.size();
    }
};

int main()
{
    vector<int> dimensions = {1500, 2};

    Variable var(dimensions);
    set<int> idxs;

    for (int i = 0; i < dimensions[0]; i++)
    {
        for (int j = 0; j < dimensions[1]; j++)
        {
            int idx = var.get_idx({i, j});
            if (idxs.count(idx) > 0)
            {
                cout << idx << endl;
            }
            else
            {
                idxs.insert(idx);
            }
        }
    }
    return 0;
}