/*****************************************************************
 * 题目：[GESP样题 二级] 画正方形
 * 描述：画循环字母正方形。
 * 思路：内部模拟循环。
 * 对象：AlphabetSquare模拟字母表正方形。
 * 注意：特殊情况和要求输出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class AlphabetSquare
{
private:
    /* 获得下一个字母 */
    char get_next(char ch)
    {
        if (ch < 'A' || ch > 'Z')
        {
            throw invalid_argument("Charactor must be letter with uppercase.");
        }

        if (ch == 'Z')
        {
            return 'A';
        }
        else
        {
            return ch + 1;
        }
    }

public:
    /* 请求，输入大小，打印字母表正方形。 */
    void query(int size)
    {
        char start = 'A';

        for (int i = 1; i <= size; i++)
        {
            char col = start;
            for (int j = 1; j <= size; j++)
            {
                cout << col;
                col = get_next(col);
            }

            start = get_next(start);
            cout << endl;
        }
    }
};

int main()
{
    AlphabetSquare as;

    int size;
    cin >> size;
    as.query(size);
    return 0;
}