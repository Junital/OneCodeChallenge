/*****************************************************************
 * 题目：「Cfz Round 9」Lone
 * 描述：问一根长度为M的木棍能否分成N个能相互组成三角形的小木棍。
 * 思路：尽可能平均分配。
 * 对象：Sticks4Triangle模拟搭出三角形的木棍。
 * 注意：注意通用性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Sticks4Triangle
{
private:
public:
    /* 请求，输入总长度和需要的数量，输出能否分成小木棍。 */
    bool query(int Len, int Num)
    {
        assert(Len >= Num);
        int MinLen = Len / Num;
        int MaxLen = MinLen + 1;
        int MinNum = Num - (Len % Num);

        if ((MinNum > 1 && MinNum < Num &&
             MinLen + MinLen <= MaxLen))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    Sticks4Triangle s4t;

    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        int len, num;
        cin >> num >> len;

        if (s4t.query(len, num))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}