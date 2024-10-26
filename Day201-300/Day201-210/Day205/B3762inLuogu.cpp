/***********************************************
 * 题目：[语言月赛202305] 线性代数初步
 * 描述：计算2*2矩阵行列式。
 * 思路：对角线计算。
 * 函数：det模拟行列式。
 * 注意：注意数据范围。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

ll det(vector<vector<int>> Matrix)
{
    return (ll)Matrix[0][0] * Matrix[1][1] - (ll)Matrix[0][1] * Matrix[1][0];
}

int main()
{
    const int size = 2;
    vector<vector<int>> matrix(size);
    rep(i, 0, size - 1)
    {
        matrix[i].resize(size);
        rep(j, 0, size - 1)
        {
            cin >> matrix[i][j];
        }
    }

    cout << det(matrix) << endl;
    return 0;
}
