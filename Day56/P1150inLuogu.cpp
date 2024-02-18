/***********************************************
 * 题目：Peter 的烟
 * 描述：每k个烟蒂可以换一根新烟，请问能吸多少烟？
 * 思路：模拟。
 * 对象：Cigarette模拟香烟。
 * 注意：模拟要清晰，不要溢出。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long // 定义长整型

/* 模拟香烟，烟蒂可以换新烟。 */
class Cigarette
{
private:
    int CigaNum;   // 香烟的个数
    int ChangeNum; // 新烟需要的旧烟蒂个数

public:
    /* 初始化，需要明确香烟个数和新烟需要的烟蒂个数。 */
    Cigarette(int ciganum, int changenum) : CigaNum(ciganum), ChangeNum(changenum)
    {
    }

    /* 获得总共能吸到的烟个数。 */
    ll getTotalCiga()
    {
        ll TotalCiga = CigaNum; // 总共吸到的烟
        int Smoke = CigaNum;    // 目前已经吸的烟
        while (Smoke >= ChangeNum)
        {
            int Change = Smoke / ChangeNum; // 换到的烟

            TotalCiga += Change;                  // 总数增加
            Smoke = (Smoke % ChangeNum) + Change; // 下次可以吸的烟
        }

        return TotalCiga;
    }
};

int main()
{
    int ciganum, changenum;
    cin >> ciganum >> changenum;

    Cigarette Ciga(ciganum, changenum);
    cout << Ciga.getTotalCiga() << endl;
}