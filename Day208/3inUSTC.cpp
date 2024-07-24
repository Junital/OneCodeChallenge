/***************************************************************
 * 题目：旋转图像
 * 描述：将一个二维数组顺时针旋转90°
 * 思路：遍历顺序不一样而已。
 * 对象：MatrixRotation模拟矩阵旋转。
 * 注意事项：注意计算复杂度。
 *************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义倒循环

class MatrixRotation
{
public:
    /* 旋转 */
    vector<vector<int>> Rotate(vector<vector<int>> Matrix)
    {
        /* 获得矩阵的大小 */
        int Height = Matrix.size();
        int Length = Matrix[0].size();

        vector<vector<int>> Res(Length);

        rep(i, 0, Length - 1)
        {
            Res[i].resize(Height);
            rep(j, 0, Height - 1)
            {
                // cout << Height - 1 - i << endl;
                Res[i][j] = Matrix[Height - 1 - j][i]; // 核心思想
                // cout << Res[i][j] << " ";
            }
            // cout << endl;
        }

        return Res;
    }
};

int main()
{
    int size;
    cin >> size;

    vector<vector<int>> matrix(size);
    MatrixRotation mr;

    rep(i, 0, size - 1)
    {
        matrix[i].resize(size);
        rep(j, 0, size - 1)
        {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> res = mr.Rotate(matrix);

    cout << "Output:" << endl;
    for (auto arr : res)
    {
        for (auto element : arr)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}
