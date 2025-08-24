#include <bits/stdc++.h>
using namespace std;

// 找出二维数组中的山峰（上下左右邻居都严格小于当前值）
vector<pair<int, int>> findPeaks(const vector<vector<int>> &grid)
{
    vector<pair<int, int>> peaks;
    int n = grid.size();
    if (n == 0)
        return peaks;
    int m = grid[0].size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int cur = grid[i][j];
            bool isPeak = true;
            // 上
            if (i > 0 && grid[i - 1][j] >= cur)
                isPeak = false;
            // 下
            if (isPeak && i < n - 1 && grid[i + 1][j] >= cur)
                isPeak = false;
            // 左
            if (isPeak && j > 0 && grid[i][j - 1] >= cur)
                isPeak = false;
            // 右
            if (isPeak && j < m - 1 && grid[i][j + 1] >= cur)
                isPeak = false;

            if (isPeak)
                peaks.emplace_back(i, j);
        }
    }
    return peaks;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    int t;
    cin >> t;
    for (int k = 0; k < t; ++k)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 输入为 1-based，转换为 0-based
        --x1;
        --y1;
        --x2;
        --y2;
        swap(grid[x1][y1], grid[x2][y2]);
    }

    auto peaks = findPeaks(grid);
    cout << peaks.size() << '\n';
    for (auto &p : peaks)
    {
        // 输出 1-based 坐标
        cout << (p.first + 1) << ' ' << (p.second + 1) << '\n';
    }

    return 0;
}
