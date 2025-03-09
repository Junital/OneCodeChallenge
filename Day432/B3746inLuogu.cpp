/*****************************************************************
 * 题目：[语言月赛202304] 洛谷评测机模拟器
 * 描述：平均分配评测任务，将任务放入最小累计时间的节点中。
 * 思路：模拟节点，进行最小堆维护。
 * 空间：EvaluationMachine模拟评测机。
 * 注意：统计最小累计时间会溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

namespace EvaluationMachine
{
    struct Node
    {
        int id;
        ll time_sum;
        Node(int id, ll time_sum) : id(id), time_sum(time_sum) {}
    };

    // 自定义比较器，用于构建最小堆
    struct CompareNode
    {
        bool operator()(const Node &a, const Node &b) const
        {
            if (a.time_sum == b.time_sum)
            {
                return a.id > b.id;
            }
            return a.time_sum > b.time_sum;
        }
    };

    /* 模拟评测系统。 */
    class EvaluationSystem
    {
    private:
        int NodeNum;
        priority_queue<Node, vector<Node>, CompareNode> Nodes;

    public:
        /* 初始化，更新节点。 */
        EvaluationSystem(int node_num) : NodeNum(node_num)
        {
            rep(i, 0, NodeNum - 1)
            {
                Nodes.push(Node(i, 0));
            }
        }

        vector<vector<int>> assgin(vector<int> tasks)
        {
            vector<vector<int>> res(NodeNum);

            int task_num = tasks.size();

            rep(i, 0, task_num - 1)
            {
                Node cur = Nodes.top();
                Nodes.pop();

                cur.time_sum += tasks[i];
                Nodes.push(cur);

                res[cur.id].push_back(i + 1);
            }

            return res;
        }
    };
};

using namespace EvaluationMachine;

int main()
{
    int node_num, task_num;
    cin >> node_num >> task_num;

    EvaluationSystem es(node_num);
    vector<int> tasks(task_num);

    rep(i, 0, task_num - 1)
    {
        cin >> tasks[i];
    }

    auto res = es.assgin(tasks);

    for (auto row : res)
    {
        int size = row.size();
        if (!size)
        {
            cout << 0 << " ";
        }
        else
        {
            for (auto element : row)
            {
                cout << element << " ";
            }
        }
        cout << endl;
    }
    return 0;
}