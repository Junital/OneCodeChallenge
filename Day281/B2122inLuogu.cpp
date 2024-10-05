/**************************************************
 * 题目：单词翻转
 * 描述：输入一个句子，对句子中每个单词进行翻转。
 * 思路：先前有做过相关函数。
 * 对象：ReverseSentence模拟单词翻转。
 * 注意：注意分割单词。
 **************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ReverseSentence
{
private:
    /* 得到字符串的翻转。 */
    string getReverse(string str)
    {
        string rev;       // 逆转后的字符串
        stack<char> chst; // 存储char的栈

        for (auto ch : str)
        {
            chst.push(ch);
        }

        while (!chst.empty())
        {
            rev.push_back(chst.top());
            chst.pop();
        }

        return rev;
    }

public:
    /* 根据句子进行分割，将单词逐一放入数组。 */
    vector<string> decode(string sentence)
    {
        stringstream ss(sentence);
        string word;
        vector<string> words;

        while (ss >> word)
        {
            words.push_back(getReverse(word));
        }

        return words;
    }
};

int main()
{
    ReverseSentence rs;
    string sentence;
    getline(cin, sentence);

    auto res = rs.decode(sentence);
    for (auto str : res)
    {
        cout << str << endl;
    }
    return 0;
}
