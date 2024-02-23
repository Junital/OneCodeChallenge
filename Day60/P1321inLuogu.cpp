/***********************************************
 * 题目：单词覆盖还原
 * 描述：找到字符串上boy、girl贴片的个数。
 * 思路：对于每个字符找到不一样的情况。
 * 函数：FindCoveredWords找到覆盖的单词个数。
 * 注意：时间限制，复杂度不能太高。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速定义循环

/* 找到覆盖单词的个数，目前只支持boy和girl */
pair<int, int> FindCoveredWords(string Str)
{
    int StrLen = Str.size(); // 字符串长度
    int BoyCnt = 0;          // 记录boy的个数
    int GirlCnt = 0;         // 记录girl的个数

    /* 思路：循环，查看字符并做出对应的跳转。 */
    for (int i = 0; i <= StrLen;)
    {
        int Jump = 1; // 跳转个数

        if (Str[i] == 'b')
        {
            BoyCnt++;
            if (Str[i + 1] == 'o')
            {
                if (Str[i + 2] == 'y')
                {
                    Jump = 3;
                }
                else
                {
                    Jump = 2;
                }
            }
        }
        else if (Str[i] == 'o')
        {
            BoyCnt++;
            if (Str[i + 1] == 'y')
            {
                Jump = 2;
            }
        }
        else if (Str[i] == 'y')
        {
            BoyCnt++;
        }
        else if (Str[i] == 'g')
        {
            GirlCnt++;
            if (Str[i + 1] == 'i')
            {
                if (Str[i + 2] == 'r')
                {
                    if (Str[i + 3] == 'l')
                    {
                        Jump = 4;
                    }
                    else
                    {
                        Jump = 3;
                    }
                }
                else
                {
                    Jump = 2;
                }
            }
        }
        else if (Str[i] == 'i')
        {
            GirlCnt++;
            if (Str[i + 1] == 'r')
            {
                if (Str[i + 2] == 'l')
                {
                    Jump = 3;
                }
                else
                {
                    Jump = 2;
                }
            }
        }
        else if (Str[i] == 'r')
        {
            GirlCnt++;
            if (Str[i + 1] == 'l')
            {
                Jump = 2;
            }
        }
        else if (Str[i] == 'l')
        {
            GirlCnt++;
        }

        i += Jump;
    }

    return make_pair(BoyCnt, GirlCnt);
}

int main()
{
    string str;

    cin >> str;

    cout << FindCoveredWords(str).first << endl;
    cout << FindCoveredWords(str).second << endl;

    return 0;
}