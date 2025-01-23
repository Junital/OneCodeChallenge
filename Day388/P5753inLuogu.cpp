/***********************************************
 * 题目：[NOI2000] 瓷片项链
 * 描述：问烧制几个瓷片能获得最大总长度。
 * 思路：遍历？
 * 对象：BurnCeramicTile模拟烧瓷片。
 * 注意：注意提高可拓展性。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

class BurnCeramicTile
{
private:
public:
    /* 输入总体积和损耗，输出半径。 */
    double burn(double volumn, double loss)
    {
        return 0.3 * sqrt(max(volumn - loss, 0.0));
    }

    /* 请求，输入总体积和损耗，输出能获得最大长度的份数。 */
    int query(double volumn, double loss)
    {
        int i = 1;
        double max_len = 0.0;

        while (true)
        {
            double single_vol = volumn / i;
            double len = burn(single_vol, loss) * i;

            if (len == max_len)
            {
                return 0;
            }
            else if (len > max_len)
            {
                max_len = len;
            }
            else
            {
                i--;
                break;
            }
            i++;
        }

        if (max_len == 0.0)
        {
            return 0;
        }
        return i;
    }
};

int main()
{
    double vol, loss;
    cin >> vol >> loss;

    BurnCeramicTile bct;
    cout << bct.query(vol, loss) << endl;
    return 0;
}