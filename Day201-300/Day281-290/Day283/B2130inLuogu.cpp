/*********************************************
 * 题目：简单算术表达式求值
 * 描述：输入一个简单算术表达式，计算结果。
 * 思路：考察读取整型、运算符并进行计算。
 * 对象：Calculator模拟计算器。
 * 注意：可能有空格。
 ********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Calculator
{
private:
    typedef int (*Func)(int, int);

    static int plus(int A, int B)
    {
        // cout << A << " " << B << endl;
        return A + B;
    }

    static int minus(int A, int B)
    {
        return A - B;
    }

    static int multiply(int A, int B)
    {
        return A * B;
    }

    static int divide(int A, int B)
    {
        if (B == 0)
        {
            std::cerr << "Error: Division by zero" << std::endl;
            return 0; // 处理除零的情况，返回0或其他适当的值
        }
        return A / B;
    }

    static int mod(int A, int B)
    {
        if (B == 0)
        {
            std::cerr << "Error: Modulo by zero" << std::endl;
            return 0; // 处理除零的情况，返回0或其他适当的值
        }
        return A % B;
    }

    const map<char, Func> OpMap = {
        {'+', &plus},
        {'-', &minus},
        {'*', &multiply},
        {'/', &divide},
        {'%', &mod}};

    int getInt(string str, int &Idx)
    {
        int it_idx = Idx;
        int res = 0;
        while (str[it_idx] == ' ')
        {
            it_idx++;
        }

        while (str[it_idx] >= '0' && str[it_idx] <= '9')
        {
            res *= 10;
            res += str[it_idx] - '0';
            it_idx++;
        }
        // cout << it_idx << endl;
        Idx = it_idx;

        return res;
    }

    Func getOP(string str, int &Idx)
    {
        int it_idx = Idx;
        while (str[it_idx] == ' ')
        {
            it_idx++;
        }

        auto it = OpMap.find(str[it_idx]);
        if (it != OpMap.end())
        {
            Idx = it_idx + 1;
            return it->second;
        }
        else
        {
            return NULL;
        }
    }

public:
    /* 请求，进行计算。 */
    int query(string expr)
    {
        int Idx = 0;
        int A = getInt(expr, Idx);
        Func op = getOP(expr, Idx);
        int B = getInt(expr, Idx);

        return op(A, B);
    }
};

int main()
{
    Calculator c;
    string expr;
    getline(cin, expr);

    cout << c.query(expr) << endl;
    return 0;
}