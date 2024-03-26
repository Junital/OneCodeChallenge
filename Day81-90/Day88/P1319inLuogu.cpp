/***********************************************
 * 题目：压缩技术
 * 描述：根据0、1的个数，输出一个01矩阵。
 * 思路：先形成一个数组，再整合成一个矩阵。
 * 对象：ZeroOneMatrix模拟01矩阵。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ZeroOneMatrix
{
private:
    vector<int> ZerosOnes;    // 01个数
    vector<bitset<1>> Matrix; // 最后的矩阵
    int MatrixSize;           // 矩阵大小

    void toMatrix()
    {
        int zosize = ZerosOnes.size();

        rep(i, 0, zosize - 1)
        {
            if (i % 2 == 0)
            {
                rep(j, 1, ZerosOnes[i])
                {
                    Matrix.push_back(0);
                }
            }
            else
            {
                rep(j, 1, ZerosOnes[i])
                {
                    Matrix.push_back(1);
                }
            }
        }
    }

public:
    /* 初始化，输入矩阵大小 */
    ZeroOneMatrix(int size) : MatrixSize(size)
    {
        int Total = MatrixSize * MatrixSize;
        int Current = 0; // 目前数

        while (Current < Total)
        {
            int num;
            cin >> num;

            Current += num;
            ZerosOnes.push_back(num);
        }

        toMatrix();
    }

    /* 打印 */
    void print()
    {
        rep(i, 0, MatrixSize - 1)
        {
            rep(j, 0, MatrixSize - 1)
            {
                cout << Matrix[i * MatrixSize + j];
            }
            cout << endl;
        }
    }
};

int main()
{
    int size;

    cin >> size;

    ZeroOneMatrix zom(size);
    zom.print();

    return 0;
}