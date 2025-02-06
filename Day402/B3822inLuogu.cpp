/*****************************************************************
 * 题目：[NICA #2] GDP
 * 描述：根据公式计算GDP。
 * 思路：输入参数，输出GDP。
 * 对象：GDP。
 * 注意：注意精度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class GDP
{
private:
public:
    /* 输入消费、投资、政府支出、出口贸易额、进口贸易额。 */
    double query(double Cons, double Invest,
                 double GoverSpend, double Export, double Import)
    {
        return Cons + Invest + GoverSpend + Export - Import;
    }
};

int main()
{
    GDP gdp;
    double cons, invest, goverspend, import_trade, export_trade;
    cin >> cons >> invest >> goverspend >> import_trade >> export_trade;

    cout << fixed << setprecision(2) << gdp.query(cons, invest, goverspend, export_trade, import_trade) << endl;

    return 0;
}