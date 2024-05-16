/***************************************************************
 * 题目：[COCI2006-2007#4] SIBICE
 * 描述：判断线段是否能放在一个矩形中。
 * 思路：判断斜边即可。
 * 对象：SegmentinRect模拟矩形中的线段。
 * 注意：注意浮点数精度。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class SegmentinRect
{
private:
    int Length;        // 矩形的长
    int Width;         // 矩形的宽
    double MaxSegment; // 最长线段

    /* 计算最长线段。 */
    void calMaxSegment()
    {
        MaxSegment = sqrt(Length * Length + Width * Width);
    }

public:
    /* 输入矩形的长和宽。 */
    SegmentinRect(int length, int width)
        : Length(length), Width(width)
    {
        calMaxSegment();
    }

    /* 判断一个线段能不能放在矩形里。 */
    bool judge(int segment)
    {
        if (segment <= MaxSegment)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    int length, width, segmentnum;
    cin >> segmentnum >> length >> width;

    SegmentinRect sr(length, width);

    rep(i, 1, segmentnum)
    {
        int segment;
        cin >> segment;

        if (sr.judge(segment))
        {
            cout << "DA" << endl;
        }
        else
        {
            cout << "NE" << endl;
        }
    }
    return 0;
}
