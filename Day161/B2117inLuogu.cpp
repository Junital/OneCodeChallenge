/**********************************************************
 * 题目：整理药名
 * 描述：药名的规范是，第一个字母大写，其他都小写。
 * 思路：字符串整理。
 * 对象：Medicaments模拟药品。
 * 注意：如何封装才比较好？
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Medicaments
{
private:
    vector<string> Medi; // 药品

    /* 统一化名称 */
    string Regularize(string Name)
    {
        int Len = Name.length();
        assert(Len > 0);

        if (Name[0] >= 'a' && Name[0] <= 'z')
        {
            Name[0] -= 'a' - 'A';
        }

        rep(i, 1, Len - 1)
        {
            if (Name[i] >= 'A' && Name[i] <= 'Z')
            {
                Name[i] += 'a' - 'A';
            }
        }

        return Name;
    }

public:
    /* 输入药名，加入数据库 */
    void append(string Name)
    {
        Medi.push_back(Regularize(Name));
    }

    void print()
    {
        for (auto m : Medi)
        {
            cout << m << endl;
        }
    }
};

int main()
{
    int Num;
    Medicaments medic;
    cin >> Num;

    rep(i, 1, Num)
    {
        string Str;
        cin >> Str;
        medic.append(Str);
    }

    medic.print();
    return 0;
}