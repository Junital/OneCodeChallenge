#include <bits/stdc++.h>
#define maxn 107
#define maxnode 5007
#define maxval 2147483646
using namespace std;

int n, a[maxn];
int tree[maxnode][3], rt = 1, nodenum = 1;

void PushUp(int rt)
{
    tree[rt][0] = tree[tree[rt][1]][0] + tree[tree[rt][2]][0];
}

int query(int L, int R, int l, int r, int &rt)
{
    if (rt == 0)
        return 0; //[1] 若该点不存在，返回0（说明该点没有值）
    if (L <= l && r <= R)
        return tree[rt][0];
    int m = (l + r) >> 1;
    int ANS = 0;
    if (L <= m)
        ANS += query(L, R, l, m, tree[rt][1]);
    if (R > m)
        ANS += query(L, R, m + 1, r, tree[rt][2]);
    return ANS;
}

void update(int L, int C, int l, int r, int &rt)
{
    cout << nodenum << " " << rt << " " << l << " " << r << endl;

    if (rt == 0)
    { //[2] 若该点不存在，新建改点
        nodenum++;
        rt = nodenum;
        tree[nodenum][0] = tree[nodenum][1] = tree[nodenum][2] = 0;
    }
    if (l == r)
    {
        tree[rt][0] += C;
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, C, l, m, tree[rt][1]);
    else
        update(L, C, m + 1, r, tree[rt][2]);
    PushUp(rt);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int val;
        scanf("%d", &val);
        printf("%d ", query(0, val - 1, 0, maxval, rt));
        update(val, +1, 0, maxval, rt);
    }
}