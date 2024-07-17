/**********************************************************
 * 题目：「RdOI R2」数(number)
 * 描述：给定限制，求出三个数字，其中任意两个数只和能被第三个数整除。
 * 思路：先测试一下有哪些数。
        经过测试发现，最大的数为另外两个数相加 x = y + z。
        同时, x = 3 * z, y = 2 * z
 * 对象：TripleNumber模拟三个互相整除的数。
 * 注意：注意数据范围，封装要好一些。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

struct ThreeNumber
{
    int x, y, z;
};

class TripleNumber
{
private:
    ThreeNumber ComputeBySmall(int Small)
    {
        return {Small * 3, Small * 2, Small};
    }

    ThreeNumber ComputeByMiddle(int Middle)
    {
        return {Middle / 2 * 3, Middle, Middle / 2};
    }

public:
    /* 输入限制和差值，从而计算三个数字。 */
    ThreeNumber get_three(string constraint, int diff)
    {
        if (constraint == "x-y" || constraint == "y-z")
        {
            return ComputeBySmall(diff);
        }
        else if (constraint == "x-z")
        {
            return ComputeByMiddle(diff);
        }

        return {-1, -1, -1};
    }
};

int main()
{
    string constraint;
    int Diff; // 差值

    TripleNumber tn;

    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        cin >> constraint >> Diff;
        ThreeNumber three = tn.get_three(constraint, Diff);

        cout << three.x << " " << three.y << " " << three.z << endl;
    }
    return 0;
}