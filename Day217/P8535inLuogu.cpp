/**********************************************************
 * 题目：「Wdoi-2」森罗结界
 * 描述：根据目前的像素数量组成数值最大的汉字数字。
 * 思路：仅仅换为1、2，零钱思想，多出来的凑一下
 * 对象：YamaPalace模拟森罗结界。
 * 注意：注意输出格式。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++)

/**********
 * 1:5
 * 2:8
 * 3:15
 * 4:30
 * 5:23
 * 6:11
 * 7:16
 * 8:10
 * 9:18
 * 0:24
 *********/

class YamaPalace
{
private:
    const int mod = 5;
    const int bonus = 3;

public:
    /* 输入数量，返回最大的值。 */
    void solve(int Num)
    {
        int x = Num / mod;

        if (Num % mod >= bonus)
        {
            cout << "2";
            rep(i, 1, x - 1)
            {
                cout << "1";
            }
        }
        else
        {
            rep(i, 1, x)
            {
                cout << "1";
            }
        }

        cout << endl;
    }
};

int main()
{
    YamaPalace yp;

    int Num;
    cin >> Num;
    yp.solve(Num);
    return 0;
}
