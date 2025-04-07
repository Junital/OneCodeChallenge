/*****************************************************************
 * 题目：下头论文
 * 描述：时间管理，每个任务需要一定时间，但是有些时候没空。
 * 思路：遍历一次？
 * 对象：TaskManage模拟任务管理。
 * 注意：如果有加法操作，小心别溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
    /* 四舍五入 */
    int Approximate(double Num)
    {
        double Ceil = ceil(Num);
        double Floor = floor(Num);

        if (Ceil - Num <= Num - Floor)
        {
            return (int)Ceil;
        }
        else
        {
            return (int)Floor;
        }
    }
};

using namespace Tools;

class TaskManage
{
private:
    vector<int> busy_time;
    vector<int> task_occupy;
    int TaskNum;
    int BusyNum;

    int64_t get_cur_begin(int64_t idx, int64_t cur)
    {
        return max(int64_t(busy_time[idx - 1]), cur);
    }

    int64_t get_space(int64_t idx, int64_t cur)
    {
        return busy_time[idx] - get_cur_begin(idx, cur) - 1;
    }

    int64_t get_max_busy()
    {
        return int64_t(busy_time[BusyNum - 1]);
    }

public:
    /* 初始化 */
    TaskManage(int task_num, int busy_num)
        : TaskNum(task_num), BusyNum(busy_num + 1)
    {
        busy_time.resize(BusyNum);
        busy_time[0] = 0;
        task_occupy.resize(TaskNum);

        /* 输入任务占用时间。 */
        for (int i = 0; i < TaskNum; i++)
        {
            cin >> task_occupy[i];
        }

        /* 输入不空闲的时间点。 */
        for (int i = 1; i < BusyNum; i++)
        {
            cin >> busy_time[i];
        }
    }

    /* 计算最优方案。 */
    int64_t get_optimal_time()
    {
        int64_t ans = 0;

        int busy_iter = 1;

        for (auto task : task_occupy)
        {
            while (busy_iter < BusyNum &&
                   task > get_space(busy_iter, ans))
            {
                // cout << get_space(busy_iter, ans) << " ";
                busy_iter++;
            }
            // cout << endl;

            if (busy_iter >= BusyNum) // 超过了最后的时间
            {
                ans = max(ans, get_max_busy()) + task; // 至少是在最后时间点的基础上再加。
            }
            else
            {
                ans = get_cur_begin(busy_iter, ans) + task;
            }
        }

        return ans;
    }
};

int main()
{
    int task_num, busy_num;
    cin >> task_num >> busy_num;

    TaskManage tm(task_num, busy_num);
    cout << tm.get_optimal_time() << endl;
    return 0;
}