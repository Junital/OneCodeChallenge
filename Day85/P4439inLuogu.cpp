/***********************************************
 * 题目：[COCI2017-2018#3] Aron
 * 描述：结伴排队，如果一个人和前面人的衣服颜色是一样的，那么他们是朋友，是一起的。
 * 思路：O(n)遍历。
 * 函数：QueueWithCompany模拟结伴排队。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 输入排队人衣服的颜色，输出实际需要等待的人数。 */
int QueueWithCompany(vector<char> Queue)
{
    int Queue_Size = Queue.size(); // 队伍人数
    int Wait = 2;                  // 需要等待的人数，包括队首的人

    rep(i, 1, Queue_Size - 1)
    {
        if (Queue[i] != Queue[i - 1])
        {
            Wait++;
        }
    }

    return Wait;
}

int main()
{
    int queue_size;
    vector<char> queue;
    cin >> queue_size;

    queue.resize(queue_size);

    rep(i, 0, queue_size - 1)
    {
        cin >> queue[i];
    }

    cout << QueueWithCompany(queue) << endl;
    return 0;
}