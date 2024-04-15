/***********************************************
 * 题目：[NOIP2005 普及组] 陶陶摘苹果
 * 描述：给一些苹果，看陶陶的身高能摘到几个。
 * 思路：upper_bound。
 * 对象：ReachApple模拟摘苹果。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ReachApple
{
private:
    const int ChairHeight = 30;
    const int AppleNum = 10;
    vector<int> Apples;

public:
    ReachApple()
    {
        Apples.resize(AppleNum + 1);
        Apples[0] = -1;

        rep(i, 1, AppleNum)
        {
            cin >> Apples[i];
        }

        sort(Apples.begin(), Apples.end());

        // for (auto apple : Apples)
        // {
        //     cout << apple << " ";
        // }
        // cout << endl;
    }

    int reach(int Height)
    {
        return upper_bound(Apples.begin(), Apples.end(), Height + ChairHeight) -
               Apples.begin() - 1;
    }
};

int main()
{
    ReachApple ra;

    int height;
    cin >> height;
    cout << ra.reach(height) << endl;

    return 0;
}