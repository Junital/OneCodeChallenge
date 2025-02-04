/*****************************************************************
 * 题目：[语言月赛202306] 信
 * 描述：根据信封和信纸的重量计算礼物，从而计算惊喜值。
 * 思路：模拟。
 * 对象：SuprisedValue模拟惊喜值。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

struct Letter
{
    int Envelope;
    int Paper;
    int TotalWeight;
};

class SurpisedValue
{
private:
    int EnvelopeWeight; // 信封重量
    int PaperWeight;    // 信纸重量
    int UpThres;        // 开心阈值
    int DownThres;      // 失望阈值

public:
    /* 初始化 */
    SurpisedValue(int envelope_weight, int paper_weight,
                  int up_thres, int down_thres)
        : EnvelopeWeight(envelope_weight), PaperWeight(paper_weight),
          UpThres(up_thres), DownThres(down_thres) {}

    /* 请求，输入信数组。 */
    pair<long long, long long> query(vector<Letter> letters)
    {
        int down_count = 0;
        int up_count = 0;

        long long max_value = 0;
        long long value = 0;

        for (auto l : letters)
        {
            int PureWeight = l.TotalWeight - (l.Envelope * EnvelopeWeight +
                                              l.Paper * PaperWeight);
            if (PureWeight > 0)
            {
                down_count = 0;
                up_count++;

                value += PureWeight;
                if (PureWeight > l.TotalWeight - PureWeight)
                {
                    value += (PureWeight + 1) / 2;
                }

                if (up_count >= UpThres)
                {
                    value *= 2;
                }

                max_value = max(max_value, value);
            }
            else
            {
                up_count = 0;
                down_count++;

                if (down_count >= DownThres)
                {
                    value /= 2;
                }
            }
        }

        return make_pair(max_value, value);
    }
};

int main()
{
    int size, envelope_weight, paper_weight,
        up_thres, down_thres;

    cin >> size >> envelope_weight >>
        paper_weight >> up_thres >> down_thres;

    SurpisedValue sv(envelope_weight, paper_weight,
                     up_thres, down_thres);

    vector<Letter> letters(size);
    for (int i = 0; i < size; i++)
    {
        cin >> letters[i].Envelope >> letters[i].Paper >>
            letters[i].TotalWeight;
    }

    auto res = sv.query(letters);
    cout << res.first << " " << res.second << endl;
    return 0;
}