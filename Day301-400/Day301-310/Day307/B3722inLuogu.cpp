/*****************************************************************
 * 题目：[语言月赛202303] Milk Sales S
 * 描述：求出B型牛奶累计销量大于A型牛奶最紧迫的时候。
 * 思路：一发现就报警。
 * 对象：ArrSumComp用于比较数组求和。
 * 注意：提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class ArrSumComp
{
private:
public:
    /* 输出两个数组，B求和大于A的最小索引。 */
    int MinLess(vector<int> A, vector<int> B)
    {
        ll ASum = 0, BSum = 0;
        assert(A.size() == B.size());
        int arrsize = A.size();

        rep(i, 0, arrsize - 1)
        {
            ASum += A[i];
            BSum += B[i];

            if (BSum > ASum)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    int arrsize;
    ArrSumComp asc;
    cin >> arrsize;

    vector<int> a(arrsize), b(arrsize);

    rep(i, 0, arrsize - 1)
    {
        cin >> a[i];
    }

    rep(i, 0, arrsize - 1)
    {
        cin >> b[i];
    }

    cout << asc.MinLess(a, b) + 1 << endl;
    return 0;
}
