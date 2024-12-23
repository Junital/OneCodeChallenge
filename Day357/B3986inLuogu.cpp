/*****************************************************************
 * 题目：[语言月赛 202406] 小 Z 的 Z 矩阵
 * 描述：打印Z字型矩阵。
 * 思路：遍历一遍。
 * 对象：ZMatrix模拟Z矩阵。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ZMatrix
{
private:
public:
    void print(int size)
    {
        rep(j, 1, size)
        {
            cout << "Z";
        }
        cout << endl;

        rep(i, 2, size - 1)
        {
            rep(j, 1, size)
            {
                if (i + j == size + 1)
                {
                    cout << "Z";
                }
                else
                {
                    cout << "-";
                }
            }
            cout << endl;
        }

        rep(j, 1, size)
        {
            cout << "Z";
        }
        cout << endl;
    }
};

int main()
{
    int size;
    ZMatrix zm;

    cin >> size;
    zm.print(size);
    return 0;
}
