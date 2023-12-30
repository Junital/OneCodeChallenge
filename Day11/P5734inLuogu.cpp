/************************************************************
 * 题目：【深基6.例6】文字处理软件
 * 要求：按照知识操作字符串：
    1为后面插入指定字符串；
    2为截取文档的某些部分；
    3为在指定位置插入新的字符串；
    4为查找对应子串
 * 作者：Junital
 * 思路：对字符串的操作要了解
 * 对象：WordProcess用于处理字符串
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

/* 用于处理字符串 */
class WordProcess
{
private:
    string Str;

    void Append()
    {
        string new_str;
        cin >> new_str;
        Str += new_str; // 用加法进行插入
        cout << Str << endl;
    }

    void Cut()
    {
        int start, len; // 输入开始的位置和长度
        cin >> start >> len;

        string cut_str = Str.substr(start, len); // 用substr来截取
        Str = cut_str;
        cout << Str << endl;
    }

    void Insert()
    {
        int start;      // 开始的位置
        string new_str; // 想插入的字符串
        cin >> start >> new_str;

        /* 读取出字符串的前段和后端，拼接到一起 */
        string front_str = Str.substr(0, start);
        string end_str = Str.substr(start);
        Str = front_str + new_str + end_str;

        cout << Str << endl;
    }

    void Find()
    {
        string substring; // 输入子串
        cin >> substring;

        int idx = Str.find(substring); // 用find查找
        cout << idx << endl;
    }

public:
    /* 初始化必须输入一个初始字符串 */
    WordProcess(string str)
    {
        Str = str;
    }

    /* 输入的数字必须在1,2,3,4中间，每次根据输入的操作符号进行对应的操作
        输入1代表向字符串末尾插入新的字符串
        输入2代表截取字符串的部分并输出
        输入3代表在某个位置插入字符串
        输入4代表查找字符串 */
    void Operation(int i)
    {
        if (i == 1)
        {
            Append();
        }
        else if (i == 2)
        {
            Cut();
        }
        else if (i == 3)
        {
            Insert();
        }
        else if (i == 4)
        {
            Find();
        }
    }
};

int main()
{
    int op_num; // 需要操作的个数
    string str; // 初始字符串

    cin >> op_num;
    cin >> str;
    WordProcess processer(str);

    for (int i = 1; i <= op_num; i++)
    {
        int op;
        cin >> op;
        processer.Operation(op);
    }
}
