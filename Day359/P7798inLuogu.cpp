/*****************************************************************
 * 题目：[COCI2015-2016#6] PUTOVANJE
 * 描述：在保证饱食度的同时想吃到尽量多的水果。
 * 思路：模拟。
 * 对象：EatFruit模拟吃水果。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class EatFruit
{
private:
public:
    /* 输入一串水果（饱食度）和最大饱食度，输出最多能吃的水果个数。 */
    int eat(vector<int> fruits, int threshold)
    {
        int max_num = 0;

        int fruit_num = fruits.size();

        rep(start, 0, fruit_num - 1)
        {
            int num = 0;
            int saturation = 0;

            if (fruit_num - start <= max_num)
            {
                break;
            }
            rep(i, start, fruit_num - 1)
            {
                if (saturation + fruits[i] <= threshold)
                {
                    num++;
                    saturation += fruits[i];
                }
            }

            max_num = max(max_num, num);
        }

        return max_num;
    }
};

int main()
{
    int size, thres;
    cin >> size >> thres;

    vector<int> fruits(size);
    rep(i, 0, size - 1)
    {
        cin >> fruits[i];
    }

    EatFruit ef;
    cout << ef.eat(fruits, thres) << endl;
    return 0;
}
