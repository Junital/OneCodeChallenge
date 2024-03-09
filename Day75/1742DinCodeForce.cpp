/***********************************************
 * 题目：Coprime
 * 描述：输入的数字最大公约数必须是1，然后找到每个数组值最大的一对。
 * 思路：数论。
 * 对象：Coprime用于模拟并计算。
 * 注意：事件上的限制。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义快速倒序循环

class Coprime
{
private:
    int T;

    inline int gcd(int x, int y)
    {
        if (y == 0)
        {
            return x;
        }
        return gcd(y, x % y);
    }

    /* 先输入一个数组，然后通过遍历找到值最大的组合。 */
    int search_cal(vector<int> Arr)
    {
        int ArrSize = Arr.size();
        int MaxValue = -1; // 答案
        int MaxSum = 2 * ArrSize;

        per(sum, MaxSum, MaxSum / 2) // 再砍了一半，不知道会不会有问题。
        {
            int maxi = min(ArrSize, sum - 1);
            int mini = (sum + 1) / 2;
            per(i, maxi, mini) // 这里微调一下
            {
                int j = sum - i;
                // cout << i << " " << j << endl;
                if (Arr[i - 1] == Arr[j - 1] && Arr[i - 1] != 1)
                {
                    continue;
                }
                if (gcd(Arr[j - 1], Arr[i - 1] % Arr[j - 1]) == 1)
                {
                    if (MaxValue == -1)
                    {
                        MaxValue = i + j;
                        return MaxValue;
                    }
                }
            }
        }
        return MaxValue;
    }

public:
    /* 初始化，输入需要计算的次数。 */
    Coprime(int t) : T(t)
    {
        rep(i, 1, T)
        {
            int arrsize;
            vector<int> arr;

            cin >> arrsize;
            arr.resize(arrsize);

            rep(j, 0, arrsize - 1)
            {
                cin >> arr[j];
            }

            cout << search_cal(arr) << endl; // 搜索并计算最大的值。
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    Coprime c(t);
}