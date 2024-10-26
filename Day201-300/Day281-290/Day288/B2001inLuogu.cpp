/*****************************************************************
 * 题目：入门测试题目
 * 描述：两个整数相加。
 * 思路：为了提升实用性，加入计算器封装。
 * 对象：Calculator模拟计算器。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

template <typename T>
class Calculator
{
private:
    typedef T (*Func)(T, T);

    static T plus(T A, T B)
    {
        // cout << A << " " << B << endl;
        return A + B;
    }

    static T minus(T A, T B)
    {
        return A - B;
    }

    static T multiply(T A, T B)
    {
        return A * B;
    }

    static T divide(T A, T B)
    {
        if (B == 0)
        {
            std::cerr << "Error: Division by zero" << std::endl;
            return 0; // 处理除零的情况，返回0或其他适当的值
        }
        return A / B;
    }

    static T mod(T A, T B)
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

    T getInt(string str, int &Idx)
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
    T query(string expr)
    {
        int Idx = 0;
        T A = getInt(expr, Idx);
        Func op = getOP(expr, Idx);
        T B = getInt(expr, Idx);

        return op(A, B);
    }

    /* 重载请求，输入两个整数和 */
    T query(char op, T A, T B)
    {
        auto it = OpMap.find(op);
        if (it != OpMap.end())
        {
            return it->second(A, B);
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    ll A, B;
    Calculator<ll> C;

    cin >> A >> B;
    cout << C.query('+', A, B) << endl;
    return 0;
}