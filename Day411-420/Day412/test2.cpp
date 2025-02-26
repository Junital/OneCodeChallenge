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

const vector<pair<TokenType, TokenType>> GroupingTokenTypes = {{T_LBRACE, T_RBRACE},
                                                               {T_LBRACKET, T_RBRACKET},
                                                               {T_LPAREN, T_RPAREN}};

struct Token
{
    TokenType type;
    string value;
};

const set<TokenType> OPERATORS = {
    T_LPAREN,
    T_RPAREN,
    T_NOT,
    T_PLUS,
    T_MINUS,
    T_MUL,
    T_DIV,
    T_MOD,
    T_GE,
    T_GT,
    T_LE,
    T_LT,
    T_EQ,
    T_NE,
    T_XOR,
    T_AND,
    T_OR,
    T_ASSIGN};

class Lexer
{
public:
    Lexer(const string &input) : input(input), pos(0) {}

    vector<Token> get_tokens()
    {
        reset();

        vector<Token> tokens;
        Token token = getNextToken();

        while (token.type != T_EOF)
        {
            tokens.push_back(token);
            token = getNextToken();
        }

        return tokens;
    }

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

/* 函数 */
struct Function
{
    vector<string> Arguments; // 参数
    int BeginPos;             // 代码开始的大括号位置
    int EndPos;               // 代码结束的大括号位置

    /* 打印函数内的代码。 */
    void print(Lexer &lexer)
    {
        cout << lexer.sub_code(BeginPos, EndPos) << endl;
    }
};

/* 存储数组、整数变量。 */
struct Variable
{
    vector<int> Dimensions; // 数组维度
    vector<int> Values;     // 数组值

    /* 初始化，输入维度，获取内存。 */
    Variable(vector<int> dimens) : Dimensions(dimens)
    {
        int size = 1;
        for (auto d : Dimensions)
        {
            size *= d;
        }

        Values.resize(size, 0);
    }

    /* 输入维度，输出对应的值。 */
    int at(vector<int> Idx)
    {
        assert(Idx.size() == Dimensions.size());

        int dimen_size = Dimensions.size();
        int idx = 0;
        rep(i, 0, dimen_size)
        {
            idx += Idx[i] * Dimensions[i];
        }

        return Values[idx];
    }

    /* 设置对应的值。 */
    void assgin(vector<int> Idx, int value)
    {
        assert(Idx.size() == Dimensions.size());

        int dimen_size = Dimensions.size();
        int idx = 0;
        rep(i, 0, dimen_size)
        {
            idx += Idx[i] * Dimensions[i];
        }

        Values[idx] = value;
    }

    /* 大小。 */
    size_t size()
    {
        return Values.size();
    }
};

/* 这是存储所有变量的地方 */
class VariableStack
{
private:
    map<string, stack<Variable>> Variables; // 放所有变量
    stack<vector<string>> Memory;           // 每个元素代表一个代码块，模拟内存栈。
    stack<int> Returns;                     // 用于方便函数调用的返回值传递。

public:
    /* 初始化。 */
    VariableStack() {}

    /* 加入变量（以及它的维度）。 */
    void push(string name, vector<int> dimensions)
    {
        Variables[name].push(Variable(dimensions));
        cout << name << " " << Variables[name].top().size() << endl;
        Memory.top().push_back(name); // 空间内加入变量名称。
    }

    /* 获取变量的值。 */
    int get_value(string name, vector<int> idx)
    {
        return Variables[name].top().at(idx);
    }

    /* 设置变量的值。 */
    void set_value(string name, vector<int> idx, int value)
    {
        Variables[name].top().assgin(idx, value);
    }

    /* 加入新代码块。 */
    void add_block()
    {
        Memory.push(vector<string>()); // 加一个命名空间
    }

    /* 去除新代码块。 */
    void remove_block()
    {
        /* 这个代码块里提到的变量都删掉。 */
        for (auto name : Memory.top())
        {
            Variables[name].pop();
        }
        Memory.pop();
    }

    /* 获取返回值数量（用于确定函数是否返回） */
    size_t get_return_num()
    {
        return Returns.size();
    }

    /* 提供返回值。 */
    int fetch_return()
    {
        int value = Returns.top();
        Returns.pop();
        return value;
    }
};

class Interpreter
{
private:
    vector<int> Inputs;          // 输入数字
    map<string, Function> Funcs; // 函数
    vector<Token> Tokens;        // 所有Token
    int TokenIdx;                // Token索引
    VariableStack vs;            // 变量内存栈

    /* 匹配括号 */
    int match_group_symbol()
    {
        Token cur = Tokens[TokenIdx++];

        for (auto group_pair : GroupingTokenTypes)
        {
            if (cur.type == group_pair.first) // 匹配各种括号
            {
                int brace_cnt = 1; // 括号计数器

                while (brace_cnt > 0)
                {
                    cur = Tokens[TokenIdx++];
                    if (cur.type == T_EOF)
                    {
                        throw invalid_argument("Braces are not matched.");
                    }
                    else if (cur.type == group_pair.first)
                    {
                        brace_cnt++; // 左括号加
                    }
                    else if (cur.type == group_pair.second)
                    {
                        brace_cnt--; // 右括号减
                    }
                }

                return TokenIdx - 1;
            }
        }

        throw invalid_argument("Wrong position.");
    }

    /* 确定操作符的优先级（需要根据上一个token继续确定）。 */
    int OpLevel(int pos)
    {
        token = Tokens[pos];
        last = Tokens[pos - 1];
        if (token.type == T_RPAREN || token.type == T_RBRACKET)
        {
            return 1;
        }
        else if (token.type == T_NOT)
        {
            return 2;
        }
        else if (token.type == T_PLUS || token.type == T_MINUS)
        {
            if (last.type != T_RPAREN && last.type != T_RBRACKET &&
                last.type != T_IDENTIFIER && last.type != T_INT_CONSTANT)
            {
                return 2;
            }
            else
            {
                return 4;
            }
        }
        else if (token.type == T_MUL || token.type == T_DIV ||
                 token.type == T_MOD)
        {
            return 3;
        }
        else if (token.type == T_GE || token.type == T_LE ||
                 token.type == T_GT || token.type == T_LT)
        {
            return 5;
        }
        else if (token.type == T_EQ || token.type == T_NE)
        {
            return 6;
        }
        else if (token.type == T_XOR)
        {
            return 7;
        }
        else if (token.type == T_AND)
        {
            return 8;
        }
        else if (token.type == T_OR)
        {
            return 9;
        }
        else if (token.type == T_ASSIGN)
        {
            return 10;
        }
        else if (token.type == T_SHIFT_LEFT || token.type == T_SHIFT_RIGHT)
        {
            return 11;
        }

        throw invalid_argument("Wrong Operator.");
    }

    /* 运行一个表达式。 */
    void run_expression(int begin_pos, int end_pos)
    {
        stack<int> ExpMem; // 表达式内存
        stack<Token> Ops;  // 存储操作符
        for (int i = begin_pos; i <= end_pos; i++)
        {
        }
        return;
    }

    /* 获取目前位置的变量。 */
    pair<string, vector<int>> get_variable()
    {
        Token token = Tokens[TokenIdx - 1];
        cout << token.value << endl;

        if (token.type != T_IDENTIFIER)
        {
            throw invalid_argument("Variable's name error.");
        }
        string var_name = token.value; // 变量名
        token = Tokens[TokenIdx++];

        /* 多维数组有维度，需要存储。 */
        vector<int> dimensions; // 如果不是数组，就不用加入内容。

        /* 找到数组的维度。 */
        while (token.type != T_COMMA &&
               token.type != T_SEMICOLON)
        {
            if (token.type != T_LBRACKET)
            {
                throw invalid_argument("Array must start with [.");
            }

            token = Tokens[TokenIdx++];
            if (token.type != T_INT_CONSTANT)
            {
                throw invalid_argument("Array's dimension must be INT, not a expression.");
            }
            dimensions.push_back(stoi(token.value));

            token = Tokens[TokenIdx++];
            if (token.type != T_RBRACKET)
            {
                throw invalid_argument("Array must end with ].");
            }

            token = Tokens[TokenIdx++];
        }

        return make_pair(var_name, dimensions);
    }

    /* 运行一个语句，返回结束token */
    Token run_statement(int pos)
    {
        TokenIdx = pos;

        Token token = Tokens[TokenIdx++];
        /* 如果是int开头的语句，那么只可能是声明 int a[2][2], b;这种。 */
        if (token.type == T_INT)
        {
            token = Tokens[TokenIdx++];

            /* 不到新的语句，就不会停止。 */
            while (token.type != T_SEMICOLON)
            {
                auto res = get_variable();
                vs.push(res.first, res.second); // 加入变量。

                token = Tokens[TokenIdx - 1];
                if (token.type == T_COMMA)
                {
                    token = Tokens[TokenIdx++];
                }
            }

            return token;
        }
        /* 如果遇到右括号，那么释放空间。 */
        else if (token.type == T_RBRACE)
        {
            vs.remove_block();
        }
        /* 输入指令cin >> 变量1 >> 变量2；。 */
        else if (token.type == T_CIN)
        {
            token = Tokens[TokenIdx++];
            while (token.type != T_SEMICOLON)
            {
                int value;
                cin >> value;

                auto res = get_variable();
                vs.set_value(res.first, res.second, value);
                token = Tokens[TokenIdx - 1];
            }

            return token;
        }
        /* 计算表达式。 */
        else
        {
            int begin_pos = TokenIdx;
            while (token.type != T_SEMICOLON)
            {
                token = Tokens[TokenIdx++];
            }
            int end_pos = TokenIdx - 1;
            run_expression(begin_pos, end_pos);

            return token;
        }

        throw invalid_argument("Unkown token.");
    };

    /* 运行一个函数，返回值必须是int。 */
    int run_function(string func_name, vector<int> argu_values)
    {
        vs.add_block(); // 一个函数当然算一个代码块

        Function f = Funcs[func_name];
        if (f.Arguments.size() != argu_values.size())
        {
            throw invalid_argument("Unmatched argument number");
        }

        int size = f.Arguments.size();
        rep(i, 0, size - 1)
        {
            vs.push(f.Arguments[i], vector<int>({argu_values[i]})); // 参数只能是整型
        }

        int return_num = vs.get_return_num();
        int new_return_num = return_num;

        TokenIdx = f.BeginPos;
        Token cur = Tokens[TokenIdx++];
        int pos = f.BeginPos;

        /* 如果返回值的数量没变，说明函数还没结束 */
        while (pos <= f.EndPos && new_return_num == return_num)
        {
            cur = run_statement(pos);
            pos = TokenIdx;
            new_return_num = vs.get_return_num();
        }

        /* 判断是否显式返回。 */
        if (new_return_num > return_num)
        {
            return vs.fetch_return();
        }
        else
        {
            return 0;
        }
    }

    /* 预处理 */
    void init()
    {
        Funcs.clear();  // 清理。
        vs.add_block(); // 这是最底层的代码块

        Token token;
        TokenIdx = 0;
        int token_size = Tokens.size();

        /* 先把
            #include<iostream>
            #include<cstdio>
            using namespace std;匹配掉 */

        token = Tokens[TokenIdx++];
        assert(token.type == T_INCLUDE);
        token = Tokens[TokenIdx++];
        assert(token.type == T_IOS);
        token = Tokens[TokenIdx++];
        assert(token.type == T_INCLUDE);
        token = Tokens[TokenIdx++];
        assert(token.type == T_CSTDIO);
        token = Tokens[TokenIdx++];
        assert(token.type == T_USING);
        token = Tokens[TokenIdx++];
        assert(token.type == T_NAMESPACE);
        token = Tokens[TokenIdx++];
        assert(token.type == T_STD);
        token = Tokens[TokenIdx++];
        assert(token.type == T_SEMICOLON);

        /* 函数：int [func_name] (参数) {}、也有可能是指令。 */
        while (TokenIdx < token_size)
        {
            int temp_pos = TokenIdx;
            token = Tokens[TokenIdx++];
            if (token.type != T_INT)
            {
                throw invalid_argument("The function return type and statement out of functions must start with int.");
            }

            Token temp_name = Tokens[TokenIdx++];
            Token lparen_or_others = Tokens[TokenIdx++];

            // 如果是左括号，代表是函数，否则是语句。
            if (lparen_or_others.type == T_LPAREN)
            {
                /* 开始处理函数。 */
                string func_name = temp_name.value;

                vector<string> args;
                Token argument;
                argument = Tokens[TokenIdx++];

                /* 参数形态：(int a, int b, int c) */
                while (argument.type != T_RPAREN)
                {
                    if (argument.type != T_INT)
                    {
                        throw invalid_argument("The arguments' type of functions must be int.");
                    }

                    argument = Tokens[TokenIdx++];
                    if (argument.type != T_IDENTIFIER)
                    {
                        throw invalid_argument("Error for argument's name.");
                    }
                    args.push_back(argument.value);

                    argument = Tokens[TokenIdx++];
                    if (argument.type == T_COMMA)
                    {
                        argument = Tokens[TokenIdx++];
                    }
                }
                int begin_pos = TokenIdx;
                int end_pos = match_group_symbol();

                Funcs[func_name] = {args, begin_pos, end_pos}; // 加入新函数
                for (int i = begin_pos; i <= end_pos; i++)
                {
                    cout << Tokens[i].value << " ";
                }
                cout << endl;

                token = Tokens[TokenIdx++];
            }
            // 如果不是，代表是语句，需要立刻执行。
            else
            {
                token = run_statement(temp_pos);
            }
        }
    }

public:
    /* 初始化，根据输入和代码进行预处理。 */
    Interpreter(vector<int> inputs, string code) : Inputs(inputs)
    {
        Lexer lexer(code);

        Tokens = lexer.get_tokens();

        /* 检验编译是否正常（可注释掉） */
        // Token token;
        // while (token.type != T_EOF)
        // {

        //     token = lexer.getNextToken();
        //     if (token.type == T_UNKNOWN)
        //     {
        //         throw invalid_argument("Unknown token.");
        //     }
        //     // cout << token.type << " " << token.value << endl;
        // }
    }

    /* 运行。 */
    void run()
    {
        /* 预处理。 */
        // lexer.reset();
        init();

        run_function("main", vector<int>());
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
    inter.run();

    // #ifndef ONLINE_JUDGE
    //     test1();
    // #endif
}