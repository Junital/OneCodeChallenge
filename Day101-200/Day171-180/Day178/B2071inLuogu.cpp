/**********************************************************
 * 题目：余数相同问题
 * 描述：求出三个数字得到相同余数的最小除数。
 * 思路：关键是如何求得最小公约数。
 * 对象：SameRemainder模拟相同余数。
 * 注意：注意数据范围。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class SameRemainder
{
public:
    /* 求出除数。 */
    int find_division(vector<int> Nums)
    {
        vector<int> Diffs;
        int NumSize = Nums.size();

        rep(i, 1, NumSize - 1)
        {
            Diffs.push_back(abs(Nums[i] - Nums[i - 1]));
        }

        int division = 2;
        while (1)
        {
            bool continu_sign = false;
            rep(i, 0, NumSize - 2)
            {
                if (Diffs[i] % division != 0)
                {
                    continu_sign = true;
                }
            }

            if (continu_sign)
            {
                division++;
            }
            else
            {
                break;
            }
        }

        return division;
    }
};

int main()
{
    SameRemainder sr;
    int a, b, c;
    vector<int> Arr;

    cin >> a >> b >> c;
    Arr.push_back(a);
    Arr.push_back(b);
    Arr.push_back(c);

    cout << sr.find_division(Arr) << endl;
    return 0;
}
