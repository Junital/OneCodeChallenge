/***********************************************
 * 题目：[COCI2006-2007#6] PRASE
 * 描述：妈妈会在某个孩子已经取走的食物数量多于其他人之和时提醒他，请问要提醒多少次。
 * 思路：模拟。
 * 对象：Mother模拟妈妈。
 * 注意：存储格式，注意时间和空间限制。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速定义循环

class Mother
{
private:
    int FoodCnt;               // 食物份数
    int NoticeTime;            // 提醒孩子的次数
    map<string, int> Children; // 每个孩子拿的食物份数

public:
    /* 初始化时，输入食物的份数。 */
    Mother(int foodcnt) : FoodCnt(foodcnt)
    {
        NoticeTime = 0;
        rep(i, 0, FoodCnt - 1)
        {
            /* 开始提醒孩子，随时注意孩子的份数。 */
            string str; // 孩子的名字
            cin >> str;

            int ChildPastFood = Children[str];  // 这位孩子已经拿的份数
            int OthersFood = i - ChildPastFood; // 其他人拿的份数

            if (ChildPastFood > OthersFood)
            {
                NoticeTime++;
            }

            Children[str]++;
        }
    }

    /* 获得提醒的次数 */
    int getNoticeTime()
    {
        return NoticeTime;
    }
};

int main()
{
    int FoodCnt;
    cin >> FoodCnt;

    Mother m(FoodCnt);

    cout << m.getNoticeTime() << endl;
    return 0;
}
