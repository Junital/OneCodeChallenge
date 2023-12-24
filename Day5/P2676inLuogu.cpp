/************************************************************
 * 题目：USACO07DEC] Bookshelf B
 * 要求：给一些奶牛的身高，输出至少需要几头牛才能够到某个高度。
 * 作者：Junital
 * 思路：贪心，每次取身高最高的即可。
 * 函数：HighFirstPile高的奶牛优先使用，看需要几头牛才能到达高度。
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

/* 用于计算至少需要几头牛才能到达指定高度，输入参数为（从高到底的身高排序，需要到达的高度） */
int HighFirstPile(priority_queue<int, vector<int>, less<int>> &cow_queue, int H)
{
    int current_height = 0; // 目前的高度
    int cow_num = 0;        // 参加堆叠的奶牛数量

    while (current_height < H)
    {
        current_height += cow_queue.top(); // 取出身高最高的奶牛进行堆叠
        cow_queue.pop();                   // 奶牛从序列中离开（因为一个奶牛不能贡献两个身高）
        cow_num++;                         // 堆叠的奶牛数量加1
    }

    return cow_num;
}

int main()
{
    priority_queue<int, vector<int>, less<int>> cow_queue;

    int N;    // 奶牛的数量
    int High; // 需要到达的高度

    cin >> N >> High;

    for (int i = 1; i <= N; i++)
    {
        int h; // 每个奶牛的身高
        cin >> h;
        cow_queue.push(h); // 将奶牛从大到小排列
    }

    cout << HighFirstPile(cow_queue, High) << endl; // 计算

    return 0;
}
