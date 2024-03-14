/***********************************************
 * 题目：[COCI2014-2015#3] STROJOPIS
 * 描述：输入一个字符串数组，求出里面*组成的矩形个数。
 * 思路：统计。
 * 函数：MapRect计算矩形个数。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

int MapRect(vector<string> ChMap)
{
    int RectNum = 0; // 统计矩形个数
    int StrLen = ChMap[0].size();
    int StrNum = ChMap.size();

    rep(i, 0, StrNum - 1)
    {
        rep(j, 0, StrLen - 1)
        {
            if (ChMap[i][j] == '*')
            {
                if ((i == 0 && (j == 0 || ChMap[i][j - 1] != '*')) ||
                    (i != 0 && ChMap[i - 1][j] != '*' && ChMap[i][j - 1] != '*'))
                {
                    RectNum++;
                    // cout << i << " " << j << endl;
                }
            }
        }
    }

    return RectNum;
}

int main()
{
    int row, col;
    vector<string> chmap; // 字符地图
    cin >> row >> col;

    rep(i, 1, row)
    {
        string str;
        cin >> str;

        assert(str.size() == col);

        chmap.push_back(str);
    }

    cout << MapRect(chmap) << endl;
}
