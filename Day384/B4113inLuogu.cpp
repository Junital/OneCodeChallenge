/*********************************************
 * 题目：[JOI2025 预选赛 R1H2] 铁路旅行 3
 * 描述：P公里之前之后收费不一样，问最后要多少钱。
 * 思路：模拟。
 * 对象：TrainFee模拟列车收费。
 * 注意：注意提高可拓展性。
 ********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class TrainFee
{
private:
    vector<int> Fees;       // 每个分段的费用
    vector<int> Thresholds; // 计费分段
public:
    TrainFee(vector<int> fees, vector<int> thres)
        : Fees(fees), Thresholds(thres)
    {
        assert(Fees.size() == Thresholds.size() + 1);
    }

    /* 请求，输入里程，输出票价。 */
    int query(int Miles)
    {
        int price = 0;

        int fee_size = Fees.size();
        rep(i, 0, fee_size - 1)
        {
            int last_thres;

            if (i > 0)
            {
                last_thres = Thresholds[i - 1];
            }
            else
            {
                last_thres = 0;
            }

            if (i != fee_size - 1 && Miles > Thresholds[i])
            {
                price += (Thresholds[i] - last_thres) * Fees[i];
            }
            else
            {

                price += (Miles - last_thres) * Fees[i];
                break;
            }
        }

        return price;
    }
};

int main()
{
    const int thres_size = 1;
    const int fee_size = 2;

    vector<int> thresholds(thres_size);
    vector<int> fees(fee_size);

    int query_mile;

    cin >> thresholds[0] >> query_mile;
    cin >> fees[0] >> fees[1];

    TrainFee tf(fees, thresholds);
    cout << tf.query(query_mile) << endl;
    return 0;
}