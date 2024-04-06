/***********************************************
 * 题目：小 D 与笔试
 * 描述：给定一个题库，然后进行考试，每个题目给出四个选项，
        要求根据题库，选出正确的答案。
 * 思路：map存储。
 * 对象：RememberExam模拟记忆考试。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class RememberExam
{
private:
    int RememberNum;                 // 需要记忆的数量
    map<string, string> ProblemRepo; // 题库
    const string A = "A";            // 选项A
    const string B = "B";            // 选项B
    const string C = "C";            // 选项C
    const string D = "D";            // 选项D

public:
    /* 初始化，输入需要记忆题目的数量。 */
    RememberExam(int remnum) : RememberNum(remnum)
    {
        rep(i, 1, RememberNum)
        {
            string Ques, Ans;
            cin >> Ques >> Ans;

            ProblemRepo[Ques] = Ans;
        }
    }

    /* 考察，输入题目和四个选项，选出正确的那个。 */
    string Exam(string Ques,
                string OptionA, string OptionB,
                string OptionC, string OptionD)
    {
        map<string, string> Problem;
        Problem[OptionA] = A;
        Problem[OptionB] = B;
        Problem[OptionC] = C;
        Problem[OptionD] = D;

        return Problem[ProblemRepo[Ques]];
    }
};

int main()
{
    int remnum, querynum;
    cin >> remnum >> querynum;

    RememberExam re(remnum);

    rep(i, 1, querynum)
    {
        string Q, A, B, C, D;
        cin >> Q >> A >> B >> C >> D;

        cout << re.Exam(Q, A, B, C, D) << endl;
    }

    return 0;
}
