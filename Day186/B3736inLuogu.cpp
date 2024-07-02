/***********************************************
 * 题目：[信息与未来 2018] 最大公约数
 * 描述：求三个数字的最大公约数。
 * 思路：尝试遍历式求公约。
 * 对象：ArrGcd模拟多个数的最大公约数。
 * 注意：注意数据范围。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ArrGcd
{
private:
    /* 求最大公因数 */
    template <typename Type>
    inline Type gcd(Type x, Type y)
    {
        if (y == 0)
        {
            return x;
        }
        return gcd(y, x % y);
    }

public:
    /* 输入一个数组，求出这个数组的最大公约数。 */
    template <typename Container>
    Container arr_gcd(vector<Container> Arr)
    {
        int ArrSize = Arr.size();
        assert(ArrSize >= 2);
        Container ans = gcd(Arr[0], Arr[1]);

        rep(i, 2, ArrSize - 1)
        {
            ans = gcd(ans, Arr[i]);
        }

        return ans;
    }
};

int main()
{
    const int arrsize = 3;
    ArrGcd ag;
    vector<int> arr(arrsize);
    cin >> arr[0] >> arr[1] >> arr[2];

    cout << ag.arr_gcd(arr) << endl;
    return 0;
}