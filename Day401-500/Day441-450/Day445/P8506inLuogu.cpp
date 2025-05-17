/*****************************************************************
 * 题目：标题计数
 * 描述：给定Markdown字符串，识别是否是一级标题。
 * 思路：简单判断。
 * 空间：Markdown模拟md解析器。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

namespace Markdown
{
    enum MarkdownType
    {
        H1,
        H2,
        H3,
        H4,
        H5,
        H6,
        QUOTE,
        LIST,
        ORDERED_LIST,
        PLAIN_TEXT
    };

    struct MarkdownChunk
    {
        MarkdownType type;
        string content;
        MarkdownChunk(MarkdownType t, string c) : type(t), content(c) {}
    };

    class MDParser
    {
    private:
        int Idx;
        void skip_space(string line)
        {
            while (Idx < line.length() && line[Idx] == ' ')
            {
                Idx++;
            }
        }

    public:
        MarkdownChunk parse_single_line(string line)
        {
            int len = line.length();
            /* 去除空白 */
            Idx = 0;
            skip_space(line);

            if (Idx == len)
            {
                return MarkdownChunk(PLAIN_TEXT, "");
            }
            /* 解析标题 */
            if (line[Idx] == '#')
            {
                int cnt = 0;
                while (Idx < len && line[Idx] == '#') // 计算#的个数
                {
                    cnt++;
                    Idx++;
                }
                if (line[Idx] != ' ') // #后面必须有空格
                {
                    return MarkdownChunk(PLAIN_TEXT, line);
                }
                skip_space(line);

                if (Idx == len) // 无非空白内容
                {
                    return MarkdownChunk(PLAIN_TEXT, line);
                }
                if (cnt == 1)
                {
                    return MarkdownChunk(H1, line.substr(Idx));
                }
                else if (cnt == 2)
                {
                    return MarkdownChunk(H2, line.substr(Idx));
                }
                else if (cnt == 3)
                {
                    return MarkdownChunk(H3, line.substr(Idx));
                }
                else if (cnt == 4)
                {
                    return MarkdownChunk(H4, line.substr(Idx));
                }
                else if (cnt == 5)
                {
                    return MarkdownChunk(H5, line.substr(Idx));
                }
                else if (cnt == 6)
                {
                    return MarkdownChunk(H6, line.substr(Idx));
                }
            }
            /* 解析引用 */
            else if (line[Idx] == '>')
            {
                skip_space(line);
                if (Idx == len) // 无非空白内容
                {
                    return MarkdownChunk(PLAIN_TEXT, line);
                }
                return MarkdownChunk(QUOTE, line.substr(Idx));
            }
            /* 解析列表 */
            else if (line[Idx] >= '0' && line[Idx] <= '9')
            {
                skip_space(line);
                if (Idx == len) // 无非空白内容
                {
                    return MarkdownChunk(PLAIN_TEXT, line);
                }
                return MarkdownChunk(LIST, line.substr(Idx));
            }
            /* 解析无序列表 */
            else if (line[Idx] == '*')
            {
                skip_space(line);
                if (Idx == len) // 无非空白内容
                {
                    return MarkdownChunk(PLAIN_TEXT, line);
                }
                return MarkdownChunk(ORDERED_LIST, line.substr(2));
            }
            else
            {
                return MarkdownChunk(PLAIN_TEXT, line);
            }
        }
    };
};

using namespace Markdown;

int main()
{
    int size;
    cin >> size;
    string line;

    int h1_count = 0;
    getline(cin, line);
    rep(i, 1, size)
    {
        getline(cin, line);
        MarkdownChunk chunk = MDParser().parse_single_line(line);
        if (chunk.type == H1)
        {
            h1_count++;
        }
    }
    cout << h1_count << endl;
    return 0;
}