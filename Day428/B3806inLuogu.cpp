/*****************************************************************
 * 题目：[语言月赛 202307] 枚举结构
 * 描述：为数据结构设计类型错误警告。
 * 思路：扩展。
 * 对象：Enumerate模拟枚举结构。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

/* 枚举类型。 */
class Enumerate
{
private:
    char Var;
    int Start;
    char Var_Check;
    int End;

    /* 检查合法性 */
    bool check()
    {
        if (!(Var >= 'a' && Var <= 'z' && Var_Check == Var))
        {
            return false;
        }
        return true;
    }

    /* 获得迭代数。 */
    ll get_iter_time()
    {
        if (!check())
        {
            cout << "Invalid" << endl;
            return -1;
        }
        else
        {
            cout << "valid" << endl;
            return abs((ll)End - Start) + 1;
        }
    }

public:
    Enumerate(char var, int start, char var_check, int end)
        : Var(var), Start(start), Var_Check(var_check), End(end)
    {
        cout << get_iter_time() << endl;
    }
};

int main()
{
    char var, var_check;
    int start, end;

    cin >> var >> start >> var_check >> end;

    Enumerate Enu(var, start, var_check, end);
    return 0;
}