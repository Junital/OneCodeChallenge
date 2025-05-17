#include <bits/stdc++.h>

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

using namespace std;

enum TokenType
{
    T_INCLUDE,
    T_IOS,    // iostream
    T_CSTDIO, // cstdio
    T_USING,
    T_NAMESPACE,
    T_STD,
    T_SEMICOLON,
    T_INT,
    T_IF,
    T_ELSE,
    T_FOR,
    T_WHILE,
    T_RETURN,
    T_LPAREN,
    T_RPAREN,
    T_LBRACE,
    T_RBRACE,
    T_LBRACKET,
    T_RBRACKET,
    T_COMMA,
    T_ASSIGN,
    T_SHIFT_LEFT,
    T_SHIFT_RIGHT,
    T_PLUS,
    T_MINUS,
    T_MUL,
    T_DIV,
    T_MOD,
    T_LT,
    T_LE,
    T_GT,
    T_GE,
    T_EQ,
    T_NE,
    T_AND,
    T_OR,
    T_XOR,
    T_NOT,
    T_CIN,
    T_COUT,
    T_ENDL,
    T_IDENTIFIER,
    T_INT_CONSTANT,
    T_EOF,
    T_UNKNOWN
};

struct Token
{
    TokenType type;
    string value;
};

class Lexer
{
public:
    Lexer(const string &input) : input(input), pos(0) {}

    Token getNextToken()
    {
        skipWhitespace();
        if (pos >= input.size())
            return Token{T_EOF, ""};

        // 处理预处理指令，如 #include
        if (input[pos] == '#')
        {
            int start = pos;
            while (pos < input.size() && !isspace(input[pos]) && input[pos] != '<')
                pos++;
            string directive = input.substr(start, pos - start);
            if (directive == "#include")
                return Token{T_INCLUDE, directive};
            else
                return Token{T_UNKNOWN, directive};
        }
        // 处理 <iostream> 或 <cstdio>
        if (input[pos] == '<' && isalpha(input[pos + 1]))
        {
            pos++; // 跳过 <
            int start = pos;
            while (pos < input.size() && input[pos] != '>')
                pos++;
            string header = input.substr(start, pos - start);
            pos++; // 跳过 >
            if (header == "iostream")
                return Token{T_IOS, header};
            if (header == "cstdio")
                return Token{T_CSTDIO, header};
            return Token{T_UNKNOWN, header};
        }
        // 处理关键字和标识符
        if (isalpha(input[pos]) || input[pos] == '_')
        {
            int start = pos;
            while (pos < input.size() && (isalnum(input[pos]) || input[pos] == '_'))
                pos++;
            string word = input.substr(start, pos - start);
            if (word == "using")
                return Token{T_USING, word};
            if (word == "namespace")
                return Token{T_NAMESPACE, word};
            if (word == "std")
                return Token{T_STD, word};
            if (word == "int")
                return Token{T_INT, word};
            if (word == "if")
                return Token{T_IF, word};
            if (word == "else")
                return Token{T_ELSE, word};
            if (word == "for")
                return Token{T_FOR, word};
            if (word == "while")
                return Token{T_WHILE, word};
            if (word == "return")
                return Token{T_RETURN, word};
            if (word == "cin")
                return Token{T_CIN, word};
            if (word == "cout")
                return Token{T_COUT, word};
            if (word == "endl")
                return Token{T_ENDL, word};
            // 否则为标识符（注意：文法要求标识符不以数字开头，这里默认正确）
            return Token{T_IDENTIFIER, word};
        }
        // 处理数字常量（INT_CONSTANT）
        if (isdigit(input[pos]))
        {
            int start = pos;
            while (pos < input.size() && isdigit(input[pos]))
                pos++;
            string number = input.substr(start, pos - start);

            if (input[start] == '0' && pos - start > 1)
            {
                throw invalid_argument("The INT can't be 0XXX like number.");
            }
            return Token{T_INT_CONSTANT, number};
        }
        // 处理符号
        char cur = input[pos++];
        switch (cur)
        {
        case ';':
            return Token{T_SEMICOLON, ";"};
        case '{':
            return Token{T_LBRACE, "{"};
        case '}':
            return Token{T_RBRACE, "}"};
        case '(':
            return Token{T_LPAREN, "("};
        case ')':
            return Token{T_RPAREN, ")"};
        case '[':
            return Token{T_LBRACKET, "["};
        case ']':
            return Token{T_RBRACKET, "]"};
        case ',':
            return Token{T_COMMA, ","};
        case '+':
            return Token{T_PLUS, "+"};
        case '-':
            return Token{T_MINUS, "-"};
        case '*':
            return Token{T_MUL, "*"};
        case '/':
            return Token{T_DIV, "/"};
        case '%':
            return Token{T_MOD, "%"};
        case '!':
            if (peek() == '=')
            {
                pos++;
                return Token{T_NE, "!="};
            }
            else
                return Token{T_NOT, "!"};
        case '=':
            if (peek() == '=')
            {
                pos++;
                return Token{T_EQ, "=="};
            }
            else
                return Token{T_ASSIGN, "="};
        case '<':
            if (peek() == '<')
            {
                pos++;
                return Token{T_SHIFT_LEFT, "<<"};
            }
            else if (peek() == '=')
            {
                pos++;
                return Token{T_LE, "<="};
            }
            else
                return Token{T_LT, "<"};
        case '>':
            if (peek() == '>')
            {
                pos++;
                return Token{T_SHIFT_RIGHT, ">>"};
            }
            else if (peek() == '=')
            {
                pos++;
                return Token{T_GE, ">="};
            }
            else
                return Token{T_GT, ">"};
        case '&':
            if (peek() == '&')
            {
                pos++;
                return Token{T_AND, "&&"};
            }
            break;
        case '|':
            if (peek() == '|')
            {
                pos++;
                return Token{T_OR, "||"};
            }
            break;
        case '^':
            return Token{T_XOR, "^"};
        default:
            return Token{T_UNKNOWN, string(1, cur)};
        }
        return Token{T_UNKNOWN, string(1, cur)};
    }

    /* 设置开始的位置。 */
    void set_pos(int position)
    {
        pos = position;
    }

    /* 重置。 */
    void reset()
    {
        pos = 0;
    }

    /* 获取目前位置。 */
    int get_cur_pos()
    {
        return pos;
    }

    /* (调试用，输出代码。) */
    string sub_code(int begin_pos, int end_pos)
    {
        return input.substr(begin_pos, end_pos + 1 - begin_pos);
    }

private:
    string input;
    size_t pos;

    void skipWhitespace()
    {
        while (pos < input.size() && isspace(input[pos]))
            pos++;
    }
    char peek()
    {
        if (pos < input.size())
            return input[pos];
        return '\0';
    }
};

class Statement
{
private:
    int BeginPos; // 代码开始位置
    int EndPos;   // 代码结束位置
};

class Function
{
private:
    string Name;              // 函数名称
    vector<string> Arguments; // 参数
    int BeginPos;             // 代码开始位置
    int EndPos;               // 代码结束位置

    void init(Lexer &lexer)
    {
        if (BeginPos != lexer.get_cur_pos())
        {
            throw invalid_argument("Lexer wrong.");
        }

        Token token;
        token = lexer.getNextToken();

        if (token.type != T_LBRACE)
        {
            throw invalid_argument("The function code must be wrapped in curly braces.");
        }

        int brace_cnt = 1; // 大括号计数器

        while (brace_cnt > 0)
        {
            token = lexer.getNextToken();
            if (token.type == T_EOF)
            {
                throw invalid_argument("Braces are not matched.");
            }
            else if (token.type == T_LBRACE)
            {
                brace_cnt++; // 左括号加
            }
            else if (token.type == T_RBRACE)
            {
                brace_cnt--; // 右括号减
            }
        }

        EndPos = lexer.get_cur_pos() - 1;
    }

public:
    Function(string name, vector<string> args,
             int begin_pos, Lexer &lexer)
        : Name(name), Arguments(args), BeginPos(begin_pos)
    {
        init(lexer); // 将代码分段。

        print(lexer);
    }

    void print(Lexer &lexer)
    {
        cout << lexer.sub_code(BeginPos, EndPos) << endl;
    }
};

class Interpreter
{
private:
    vector<int> Inputs;
    vector<Function> Funcs;
    Lexer lexer;

    /* 预处理 */
    void init()
    {
        Funcs.clear(); // 清理。
        Token token;

        /* 先把
            #include<iostream>
            #include<cstdio>
            using namespace std;匹配掉 */

        token = lexer.getNextToken();
        assert(token.type == T_INCLUDE);
        token = lexer.getNextToken();
        assert(token.type == T_IOS);
        token = lexer.getNextToken();
        assert(token.type == T_INCLUDE);
        token = lexer.getNextToken();
        assert(token.type == T_CSTDIO);
        token = lexer.getNextToken();
        assert(token.type == T_USING);
        token = lexer.getNextToken();
        assert(token.type == T_NAMESPACE);
        token = lexer.getNextToken();
        assert(token.type == T_STD);
        token = lexer.getNextToken();
        assert(token.type == T_SEMICOLON);

        /* 函数：int [func_name] (参数) {}、也有可能是指令。 */
        while (token.type != T_EOF)
        {
            token = lexer.getNextToken();
            if (token.type != T_INT)
            {
                throw invalid_argument("The function return type and statement out of functions must start with int.");
            }

            Token temp_name = lexer.getNextToken();
            Token lparen_or_others = lexer.getNextToken();

            // 如果是左括号，代表是函数，否则是语句。
            if (lparen_or_others.type == T_LPAREN)
            {
                /* 开始处理函数。 */
                string func_name = temp_name.value;

                vector<string> args;
                Token argument;
                argument = lexer.getNextToken();

                while (argument.type != T_RPAREN)
                {
                    if (argument.type != T_INT)
                    {
                        throw invalid_argument("The arguments' type of functions must be int.");
                    }

                    argument = lexer.getNextToken();
                    args.push_back(argument.value);

                    if (argument.type != T_RPAREN)
                    {
                        argument = lexer.getNextToken();
                    }
                }
                int begin_pos = lexer.get_cur_pos();

                Funcs.push_back(
                    Function(func_name, args, begin_pos, lexer)); // 加入新函数

                token = lexer.getNextToken();
            }
        }
    }

public:
    /* 初始化，根据输入和代码进行预处理。 */
    Interpreter(vector<int> inputs, string code)
        : Inputs(inputs), lexer(code)
    {
        /* 检验编译是否正常（可注释掉） */
        Token token;
        while (token.type != T_EOF)
        {

            token = lexer.getNextToken();
            if (token.type == T_UNKNOWN)
            {
                throw invalid_argument("Unknown token.");
            }
            // cout << token.type << " " << token.value << endl;
        }

        /* 预处理。 */
        lexer.reset();
        init();
    }
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen(argc == 1 ? "input.txt" : argv[1], "r", stdin); // 自己调试用
#endif

    int size;
    cin >> size;

    vector<int> inputs(size);
    rep(i, 0, size - 1)
    {
        cin >> inputs[i];
    }

    string str, code;
    while (cin >> str)
    {
        code += str + '\n';
    }

    Interpreter inter(inputs, code);

    // #ifndef ONLINE_JUDGE
    //     test1();
    // #endif
}