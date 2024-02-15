/***********************************************
 * 题目：画矩形
 * 描述：指定矩形的长宽、填充字符、内部样式，画一个矩阵。
 * 思路：模拟。
 * 对象：Rectangle模拟矩形。
 * 注意：空心实心需要额外注意。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速定义循环

/* 一个可以定义样式，输出在终端上的矩形。 */
class Rectangle
{
private:
    int Height;  // 矩形的高
    int Weight;  // 矩形的宽
    char Pad;    // 填充字符
    bool isFull; // 是否实心

public:
    /* 初始化，定义高、宽、填充字符和是否实心。 */
    Rectangle(int height, int weight, char pad, bool isfull)
        : Height(height), Weight(weight), Pad(pad), isFull(isfull)
    {
    }

    /* 输出这个矩阵。 */
    void print()
    {
        /* 思路：循环，判断，再输出。 */
        rep(i, 1, Height)
        {
            rep(j, 1, Weight)
            {
                bool allowPrint = false;   // 是否运行输出，默认为否定
                if (j == 1 || j == Weight) // 在第一列或者最后一列
                {
                    allowPrint = true;
                }
                else if (i == 1 || i == Height) // 在第一排或者最后一排
                {
                    allowPrint = true;
                }
                else if (isFull == true) // 实心
                {
                    allowPrint = true;
                }

                if (allowPrint)
                {
                    cout << Pad;
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl; // 换行
        }
    }
};

int main()
{
    int height, weight;
    char pad;
    bool isfull;

    cin >> height >> weight >> pad >> isfull;

    Rectangle r(height, weight, pad, isfull);
    r.print();
}