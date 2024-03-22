/***********************************************
 * 题目：语句解析
 * 描述：解析PASCAL赋值语句。
 * 思路：编译器原理。
 * 对象：PASCAL模拟编译器。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class PASCAL
{
private:
    map<char, int> Variables; // 变量的值

    void init()
    {
        Variables['a'] = 0;
        Variables['b'] = 0;
        Variables['c'] = 0;
    }

public:
    /* 解析语句 */
    void Compile(string Sentence)
    {
        int len = Sentence.size();

        assert(len % 5 == 0);

        int i = 0;
        while (i < len)
        {
            // cout << Sentence[i] << " " << Sentence[i + 3] << endl;
            if (Sentence[i + 1] == ':' && Sentence[i + 2] == '=')
            {
                if (Sentence[i + 3] >= '0' && Sentence[i + 3] <= '9')
                {
                    Variables[Sentence[i]] = Sentence[i + 3] - '0';
                }
                else
                {
                    Variables[Sentence[i]] = Variables[Sentence[i + 3]];
                }
                i += 5;
            }
        }
    }

    /* 输出三个变量的值 */
    void print()
    {
        cout << Variables['a'] << " " << Variables['b']
             << " " << Variables['c'] << endl;
    }

    /* 初始化 */
    PASCAL()
    {
        init();
    }
};

int main()
{
    PASCAL pascal;

    string str;
    cin >> str;

    pascal.Compile(str);
    pascal.print();
}
