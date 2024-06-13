/**********************************************************
 * 题目：二进制分类
 * 描述：将十进制数转为二进制数，比较其中1的数量和0的数量。
 * 思路：感觉可以有方法直接判断。
 * 对象：ABBinary模拟AB类二进制。
 * 注意：一定要总结合适的规律。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ABBinary
{
private:
    /* 计算一个数后面0的个数 */
    int countDivisibleByTwo(int n)
    {
        int count = 0;
        while (n % 2 == 0 && n != 0)
        {
            n /= 2;
            count++;
        }
        return count;
    }

public:
    /* 测试函数 */
    void test()
    {
        int one_num = 1;
        int zero_num = 0;

        rep(i, 1, 100)
        {
            if (one_num > zero_num)
            {
                cout << "A" << endl;
            }
            else
            {
                cout << "B" << endl;
            }

            bitset<32> binary(i);
            cout << binary << " " << one_num << " " << zero_num << endl;

            if (zero_num == 0)
            {
                zero_num = one_num;
                one_num = 1;
            }
            else if (!(i & 1))
            {
                zero_num--;
                one_num++;
            }
            else
            {
                int change = countDivisibleByTwo(i + 1);
                one_num -= (change - 1);
                zero_num += (change - 1);
            }
        }
    }

    /* 输入一个数字，输出1~n中A类型的个数和B类型的个数。 */
    void count(int MaxNum)
    {
        int one_num = 1;
        int zero_num = 0;
        int Acount = 0;
        int Bcount = 0;

        rep(i, 1, MaxNum)
        {
            if (one_num > zero_num)
            {
                Acount++;
            }
            else
            {
                Bcount++;
            }

            if (zero_num == 0)
            {
                zero_num = one_num;
                one_num = 1;
            }
            else if (!(i & 1))
            {
                zero_num--;
                one_num++;
            }
            else
            {
                int change = countDivisibleByTwo(i + 1); // 获得i后面连续1的个数
                one_num -= (change - 1);
                zero_num += (change - 1);
            }
        }

        cout << Acount << " " << Bcount << endl;
    }
};

int main()
{
    ABBinary abb;

    int MaxNum;
    cin >> MaxNum;

    abb.count(MaxNum);
    return 0;
}
