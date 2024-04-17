/***********************************************
 * 题目：压缩技术（续集版）
 * 描述：输入一个点阵图案，用0、1的数量来进行信息压缩。
 * 思路：简单统计。
 * 对象：CompressCode模拟压缩码。
 * 注意：注意一开始必须是0的个数。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class CompressCode
{
private:
    string Matrix;               // 点阵
    int Cnt;                     // 压缩码大小
    const bitset<1> StartCh = 0; // 开始字符为0

public:
    /* 直接开始输入。 */
    CompressCode()
    {
        Cnt = 1;
        rep(i, 1, Cnt)
        {
            string Str;
            cin >> Str;

            Cnt = Str.size();
            Matrix += Str;
        }

        // cout << Matrix.size() << endl;
    }

    /* 开始压缩。 */
    vector<int> compress()
    {
        int MatrixSize = Matrix.size();
        int i = 0;                     // 迭代器
        bitset<1> currentCh = StartCh; // 目前需要统计的字符
        vector<int> Code;              // 压缩码

        Code.push_back(Cnt);

        bitset<1> digit = Matrix[i] - '0';
        if (digit != currentCh)
        {
            Code.push_back(0);
            currentCh = ~currentCh;
        }

        while (i < MatrixSize)
        {
            int cnt = 0; // 统计连续数量
            while (digit == currentCh)
            {
                cnt++;
                i++;
                digit = Matrix[i] - '0';
            }

            currentCh = ~currentCh;
            Code.push_back(cnt);
        }

        return Code;
    }
};

int main()
{
    CompressCode cs;

    vector<int> code = cs.compress();

    for (auto c : code)
    {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
