/***********************************************
 * 题目：小鱼比可爱
 * 描述：给一个数组，要求输出每个元素前面有几个比它小的元素。
 * 思路：学习了一下大佬的想法，打算用动态开点的线段树实现。
 * 对象：SearchForeLow搜索前方小的值。
 * 注意：溢出问题，求和可能ll。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define MAXVAL 2147483646                         // 定义最大值

/* 可以搜索前方最小的值。 */
class SearchForeLow
{
private:
    const static int MAXN = 105; // 最大鱼的个数。
    int NodeCnt;                 // 目前结点的个数
    int Root;                    // 根节点
    int Sum[MAXN * 2];           // 所有值前缀和
    int Left[MAXN * 2];          // 左边
    int Right[MAXN * 2];         // 右边

    /* 求和，将一个区间进行合并， */
    void pushup(int root)
    {
        Sum[root] = Sum[Left[root]] + Sum[Right[root]];
    }

    /* 输入根节点、查询左区间、查询右区间、目前左区间、目前右区间。 */
    int query(int &root, int qL, int qR, int cl, int cr)
    {
        // cout << root << " " << cl << " " << cr << endl;

        if (!root)
        {
            return 0;
        }

        if (qL <= cl && cr <= qR)
        {
            return Sum[root];
        }

        int Mid = cl + ((cr - cl) >> 1); // 区间中间数
        int Ans = 0;                     // 答案目前为0

        if (qL <= Mid)
        {
            Ans += query(Left[root], qL, qR, cl, Mid);
        }
        if (qR > Mid)
        {
            Ans += query(Right[root], qL, qR, Mid + 1, cr);
        }

        return Ans;
    }

    /* 区间修改，输入根节点、结点编号、修改值、目前左区间、目前右区间。 */
    void update(int &root, int Idx, int Value, int cl, int cr) // 这里root需要引用是因为需要递归进行改写
    {
        // cout << NodeCnt << " " << root << " " << cl << " " << cr << endl;
        // cout << Left[root] << endl;

        if (root == 0)
        {
            NodeCnt++;
            root = NodeCnt;
            Sum[root] = Left[root] = Right[root] = 0;
        }

        if (cl == cr)
        {
            Sum[root] += Value;
            return;
        }

        int Mid = cl + ((cr - cl) >> 1);
        if (Idx <= Mid)
        {
            update(Left[root], Idx, Value, cl, Mid);
        }
        else
        {
            update(Right[root], Idx, Value, Mid + 1, cr);
        }

        pushup(root);
    }

public:
    /* 初始化，不需要输入什么。 */
    SearchForeLow()
    {
        NodeCnt = 1;
        Root = 1;
        memset(Sum, 0, sizeof(Sum));
        memset(Left, 0, sizeof(Left));
        memset(Right, 0, sizeof(Right));
    }

    /* 加点并查询 */
    int AddQuery(int value)
    {
        int Ans = query(Root, 0, value - 1, 0, MAXVAL); // 统计0到值-1的数字之和

        // cout << Ans << endl;
        update(Root, value, +1, 0, MAXVAL);

        return Ans;
    }
};

int main()
{
    int Num;
    SearchForeLow sfl;

    cin >> Num;
    rep(i, 1, Num)
    {
        int value;
        cin >> value;
        cout << sfl.AddQuery(value) << " ";
    }
    cout << endl;
    return 0;
}