/***********************************************
 * 题目：[COCI2014-2015#3] STROJOPIS
 * 描述：给定打字每个拇指对应的按键，输入一个字符串，统计每根手指按的次数。
 * 思路：统计。
 * 对象：KeyBoard模拟键盘。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

class KeyBorad
{
private:
    map<char, string> Ch2Finger;              // 字符和手指的对应关系
    map<string, int> FingerClickCnt;          // 手指按的次数
    const string LEFTPINKY = "leftPinky";     // 左手小拇指
    const string LEFTRING = "leftRing";       // 左手无名指
    const string LEFTMIDDLE = "leftMiddle";   // 左手中指
    const string LEFTINDEX = "leftIndex";     // 左手食指
    const string RIGHTPINKY = "rightPinky";   // 左手小拇指
    const string RIGHTRING = "rightRing";     // 左手无名指
    const string RIGHTMIDDLE = "rightMiddle"; // 左手中指
    const string RIGHTINDEX = "rightIndex";   // 左手食指

    void init()
    {
        Ch2Finger['1'] = LEFTPINKY;
        Ch2Finger['Q'] = LEFTPINKY;
        Ch2Finger['A'] = LEFTPINKY;
        Ch2Finger['Z'] = LEFTPINKY;

        Ch2Finger['2'] = LEFTRING;
        Ch2Finger['W'] = LEFTRING;
        Ch2Finger['S'] = LEFTRING;
        Ch2Finger['X'] = LEFTRING;

        Ch2Finger['3'] = LEFTMIDDLE;
        Ch2Finger['E'] = LEFTMIDDLE;
        Ch2Finger['D'] = LEFTMIDDLE;
        Ch2Finger['C'] = LEFTMIDDLE;

        Ch2Finger['4'] = LEFTINDEX;
        Ch2Finger['R'] = LEFTINDEX;
        Ch2Finger['F'] = LEFTINDEX;
        Ch2Finger['V'] = LEFTINDEX;
        Ch2Finger['5'] = LEFTINDEX;
        Ch2Finger['T'] = LEFTINDEX;
        Ch2Finger['G'] = LEFTINDEX;
        Ch2Finger['B'] = LEFTINDEX;

        Ch2Finger['6'] = RIGHTINDEX;
        Ch2Finger['Y'] = RIGHTINDEX;
        Ch2Finger['H'] = RIGHTINDEX;
        Ch2Finger['N'] = RIGHTINDEX;
        Ch2Finger['7'] = RIGHTINDEX;
        Ch2Finger['U'] = RIGHTINDEX;
        Ch2Finger['J'] = RIGHTINDEX;
        Ch2Finger['M'] = RIGHTINDEX;

        Ch2Finger['8'] = RIGHTMIDDLE;
        Ch2Finger['I'] = RIGHTMIDDLE;
        Ch2Finger['K'] = RIGHTMIDDLE;
        Ch2Finger[','] = RIGHTMIDDLE;

        Ch2Finger['9'] = RIGHTRING;
        Ch2Finger['O'] = RIGHTRING;
        Ch2Finger['L'] = RIGHTRING;
        Ch2Finger['.'] = RIGHTRING;

        Ch2Finger['0'] = RIGHTPINKY;
        Ch2Finger['P'] = RIGHTPINKY;
        Ch2Finger[';'] = RIGHTPINKY;
        Ch2Finger['/'] = RIGHTPINKY;
        Ch2Finger['\''] = RIGHTPINKY;
        Ch2Finger['['] = RIGHTPINKY;
        Ch2Finger[']'] = RIGHTPINKY;
        Ch2Finger['='] = RIGHTPINKY;
        Ch2Finger['-'] = RIGHTPINKY;
    }

    void FingerCnt(string Str)
    {
        for (auto ch : Str)
        {
            FingerClickCnt[Ch2Finger[ch]]++;
        }

        cout << FingerClickCnt[LEFTPINKY] << endl;
        cout << FingerClickCnt[LEFTRING] << endl;
        cout << FingerClickCnt[LEFTMIDDLE] << endl;
        cout << FingerClickCnt[LEFTINDEX] << endl;
        cout << FingerClickCnt[RIGHTINDEX] << endl;
        cout << FingerClickCnt[RIGHTMIDDLE] << endl;
        cout << FingerClickCnt[RIGHTRING] << endl;
        cout << FingerClickCnt[RIGHTPINKY] << endl;
    }

public:
    /* 初始化，输入一个字符串。 */
    KeyBorad(string str)
    {
        init();

        FingerCnt(str);
    }
};

int main()
{
    string str;
    cin >> str;

    KeyBorad kb(str);

    return 0;
}