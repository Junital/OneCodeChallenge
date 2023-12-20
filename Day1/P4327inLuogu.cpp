/*********************
 * 题目：[COCI2006-2007#1] Okviri
 * 要求：输入一个字符串，遇到第三个字母，就用*包装，其余就用#包装。
 * 作者：Junital
 * 函数：SpecialPrint用于输出包装
 *********************/

#include <bits/stdc++.h>

using namespace std;

void PrintFirstLayer(int len)
{
    // 第一行和第五行由..#..构成，如果有多个字母每个#或者*后面要加...
    cout << ".."; // 首部
    for (int i = 1; i <= len; i++)
    {
        if (i % 3 == 0)
        {
            cout << "*";
        }
        else
        {
            cout << "#";
        }
        if (i != len)
        {
            cout << "...";
        }
    }
    cout << ".." << endl; // 尾部
}

void PrintSceondLayer(int len)
{
    // 第二部分和第四部分.#.#.，一个字母有两个#或者*。
    cout << "."; // 首部
    for (int i = 1; i <= len; i++)
    {
        if (i % 3 != 0)
        {
            cout << "#.#.";
        }
        else
        {
            cout << "*.*.";
        }
    }
    cout << endl; // 尾部
}

void SpecialPrint(string str)
{
    int len = str.length();

    PrintFirstLayer(len);

    PrintSceondLayer(len);

    // 第三部分有点复杂，可以先看成#.A这种格式，不过第四个和尾部需要判断一下。
    for (int i = 1; i <= len; i++)
    {
        if (i % 3 == 0 || (i % 3 == 1 && i != 1)) // 特殊判断，因为第三个会覆盖
        {
            cout << "*." << str[i - 1] << ".";
        }
        else
        {
            cout << "#." << str[i - 1] << ".";
        }
    }
    if (len % 3 == 0)
    {
        cout << "*" << endl;
    }
    else
    {
        cout << "#" << endl;
    }

    PrintSceondLayer(len); // 第四层和第二层一样

    PrintFirstLayer(len); // 第五层和第一层一样
}

int main()
{
    string str; // 输入用的字符串
    cin >> str;
    SpecialPrint(str);
}