/***********************************************
 * 题目：小红大战小紫
 * 描述：比较大小，判断谁赢谁输。
 * 思路：简单比较。
 * 函数：JudgeKouYukari用于判断输赢。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

/* 输入小红，小紫的胜场，判断谁赢了。 */
string JudgeKouYukari(int Kou, int Yukari)
{
    if (Kou > Yukari)
    {
        return "kou";
    }
    if (Kou == Yukari)
    {
        return "draw";
    }
    return "yukari";
}

int main()
{
    int Kou, Yukari;
    cin >> Kou >> Yukari;

    cout << JudgeKouYukari(Kou, Yukari) << endl;

    return 0;
}
