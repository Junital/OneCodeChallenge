/**********************************************************
 * 题目：[传智杯 #3 决赛] 课程
 * 描述：求两个集合的交集。
 * 思路：使用函数set_intersection。
 * 函数：Intersection模拟交集。
 * 注意：要保证封装性，之后也能用。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

template <typename Container>
Container Intersection(const Container &A, const Container &B)
{
    Container result;
    set_intersection(A.begin(), A.end(), B.begin(), B.end(),
                     inserter(result, result.begin()));
    return result;
}

int main()
{
    int Asize, Bsize;
    cin >> Asize >> Bsize;

    set<int> A;
    set<int> B;

    rep(i, 1, Asize)
    {
        int Num;
        cin >> Num;
        A.insert(Num);
    }

    rep(j, 1, Bsize)
    {
        int Num;
        cin >> Num;
        B.insert(Num);
    }

    set<int> Res = Intersection(A, B);
    cout << Res.size() << endl;
    return 0;
}