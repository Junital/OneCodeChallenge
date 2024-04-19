/**********************************************************
 * 题目：[NOIP2005 普及组] 校门外的树
 * 描述：一个线段，其中某些区间要被挖去，求之后线段长度。
 * 思路：大佬提出了珂朵莉树。
 * 对象：DeleteSegment模拟挖去线段。
 * 注意：注意时间和溢出问题。
 *********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class DeleteSegment
{
private:
    struct Segment
    {
        int l, r; // 线段左右端点
        int v;    // 值
        Segment(int L, int R = -1, int V = 0) : l(L), r(R), v(V) {}

        bool operator<(const Segment &other) const
        {
            return l < other.l;
        }
    };

    set<Segment> Segments; // 存储线段
    int TotalLen;          // 整体长度

    /* 分段 */
    set<Segment>::iterator split(int pos)
    {
        set<Segment>::iterator it = Segments.lower_bound({pos});

        if (it != Segments.end() && it->l == pos)
        {
            return it;
        }

        it--; // 回到较小的区间
        int L = it->l;
        int R = it->r;
        int V = it->v;
        Segments.erase(it);                               // 删除此区间，换成两个小的区间
        Segments.insert(Segment(L, pos - 1, V));          // 添加左侧区间
        return Segments.insert(Segment(pos, R, V)).first; // 返回右侧区间的迭代器
    }

public:
    DeleteSegment(int total) : TotalLen(total)
    {
        Segments.insert(Segment(0, TotalLen, 1));
    }

    /* 删除，输入头和尾。 */
    void del(int first, int last)
    {
        /* 需要注意的是set的erase是左闭右开的。 */
        set<Segment>::iterator itr = split(last + 1), itl = split(first);

        Segments.erase(itl, itr);                 // 删除这个区间
        Segments.insert(Segment(first, last, 0)); // 换一个大空间，值设为0
    }

    /* 输出最后留下的线段。 */
    int getLeft()
    {
        int ans = 0;
        for (auto seg : Segments)
        {
            ans += (seg.r - seg.l + 1) * (seg.v);
        }

        return ans;
    }
};

int main()
{
    int total, deltime;
    cin >> total >> deltime;

    DeleteSegment ds(total);
    // cout << ds.getLeft() << endl;

    rep(i, 1, deltime)
    {
        int left, right;
        cin >> left >> right;

        ds.del(left, right);
    }
    cout << ds.getLeft() << endl;

    return 0;
}