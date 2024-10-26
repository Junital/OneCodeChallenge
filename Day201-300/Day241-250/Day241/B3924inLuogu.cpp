/*****************************************************************
 * 题目：[GESP202312 二级] 小杨的H字矩阵
 * 描述：打印H字。
 * 思路：分段输出。
 * 对象：PrintH模拟打印H矩阵。
 * 注意：注意条件判断。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class PrintH
{
private:
    const char FILL = 'a';

public:
    /* 输入矩阵大小，进行输出。 */
    void print(int Size)
    {
        rep(i, 1, Size)
        {
            cout << "|";
            if (i == (Size + 1) >> 1)
            {
                rep(i, 1, Size - 2)
                {
                    cout << "-";
                }
            }
            else
            {
                rep(i, 1, Size - 2)
                {
                    cout << FILL;
                }
            }
            cout << "|" << endl;
        }
    }
};

int main()
{
    PrintH ph;

    int size;
    cin >> size;
    ph.print(size);
    return 0;
}