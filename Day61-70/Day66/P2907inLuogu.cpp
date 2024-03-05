/***********************************************
 * 题目：[USACO08OPEN] Roads Around The Farm S
 * 描述：群体分裂，只要能分成两个群体，数量相差为K，就会继续分裂。
        问最后会分成几个群体。
 * 思路：见Solve.svg。
 * 函数：GroupSplit模拟群体分裂。
 * 注意：注意时空限制。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 输入一开始群体中个体数量，和分裂差数。 */
int GroupSplit(int Size, int Differ)
{
    stack<int> Groups; // 模拟群体
    int GroupNum = 0;  // 群体个数
    Groups.push(Size); // 先将最初群体输入

    while (!Groups.empty())
    {
        int Group = Groups.top();
        Groups.pop();

        if ((Group - Differ) % 2 == 0 && Group > Differ) // 个体数一定要大于差异数
        {
            int SubGroup = (Group - Differ) / 2;
            Groups.push(SubGroup);
            Groups.push(SubGroup + Differ);
        }
        else
        {
            GroupNum++;
        }
    }

    return GroupNum;
}

int main()
{
    int size, differ;

    cin >> size >> differ;

    cout << GroupSplit(size, differ) << endl;

    return 0;
}