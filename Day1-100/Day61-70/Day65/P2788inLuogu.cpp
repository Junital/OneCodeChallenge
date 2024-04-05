/***********************************************
 * 题目：数学1（math1）- 加减算式
 * 描述：输入一个加减算式，输出计算结果。
 * 思路：编译器，应该不需要语法树。
 * 函数：PlusMinusOP计算加减算式。
 * 注意：注意结果不要溢出。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class PlusMinusOP
{
private:
    string Formula;
    ll Answer;

    /* 计算操作 */
    ll OP(ll Num1, char op, ll Num2)
    {
        if (op == '+')
        {
            return Num1 + Num2;
        }
        else if (op == '-')
        {
            return Num1 - Num2;
        }

        return (ll)1 << 63; // 返回最小值
    }

    /* 输入索引，获得下一个数字。 */
    ll getNum(int &Point)
    {
        ll Num = 0;
        while (Formula[Point] >= '0' && Formula[Point] <= '9')
        {
            ll Digit = Formula[Point] - '0';
            Num = Num * 10 + Digit;

            Point++;
        }

        return Num;
    }

    /* 输入索引，获得操作符。 */
    char getOP(int &Point)
    {
        if (Formula[Point] == '+' || Formula[Point] == '-')
        {
            return Formula[Point++];
        }
        else
        {
            return 0;
        }
    }

public:
    /* 初始化，输入公式。 */
    PlusMinusOP(string formula) : Formula(formula) {}

    /* 获得结果。 */
    ll getRes()
    {
        int StrLen = Formula.size();
        int i = 0; // 迭代器

        ll Num1, Num2;
        char op;

        Num1 = getNum(i);

        while (i < StrLen)
        {
            op = getOP(i);
            Num2 = getNum(i);

            // cout << op << " " << Num2 << endl;

            Num1 = OP(Num1, op, Num2);
        }

        Answer = Num1;

        return Num1;
    }
};

int main()
{
    string formula;
    cin >> formula;

    PlusMinusOP pmop(formula);

    cout << pmop.getRes() << endl;
}