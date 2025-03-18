#include <bits/stdc++.h>

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

using namespace std;

enum TokenType
{
    T_INCLUDE,
    T_IOS,
    T_CSTDIO,
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
            pos = start;
            return Token{T_LT, "<"};
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
    int DimenSize;          // 维度数量

    /* 初始化，输入维度，获取内存。 */
    Variable(vector<int> dimens)
        : Dimensions(dimens), DimenSize(dimens.size())
    {
        int size = 1;
        for (auto d : Dimensions)
        {
            size *= d;
        }

        Values.resize(size, 0);
    }

    /* 获得索引。 */
    int get_idx(vector<int> Idx)
    {
        int idx_size = Idx.size();
        assert(idx_size == DimenSize);
        int idx = 0;
        int base = 1;
        // 修改循环顺序为逆序
        for (int i = DimenSize - 1; i >= 0; i--)
        {
            assert(Idx[i] < Dimensions[i]);
            idx += Idx[i] * base;
            base *= Dimensions[i];
        }
        assert(idx >= 0 && idx < (int)Values.size());
        return idx;
    }

    /* 输入维度，输出对应的值。 */
    int *at(vector<int> Idx)
    {
        int idx = get_idx(Idx);

        return &Values[idx];
    }

    /* 设置对应的值。 */
    void assgin(vector<int> Idx, int value)
    {
        *at(Idx) = value;
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
    VariableStack()
    {
    }

    /* 加入变量（以及它的维度）。 */
    void push(string name, vector<int> dimensions)
    {
        Variables[name].push(Variable(dimensions));
        Memory.top().push_back(name); // 空间内加入变量名称。
    }

    /* 获取变量的引用。 */
    int *get_ref(string name, vector<int> idx)
    {
        if (Variables[name].empty())
        {
            throw invalid_argument("Unexpected varible " + name + ".");
        }
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
        auto vars = Memory.top();
        for (auto name : vars)
        {
            // cout << name << " ";
            Variables[name].pop();
        }
        // cout << endl;
        Memory.pop();
    }

    /* 获取返回值数量（用于确定函数是否返回） */
    size_t get_return_num()
    {
        return Returns.size();
    }

    /* 加入新返回值。 */
    void add_return(int return_num)
    {
        Returns.push(return_num);
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
    vector<int> Inputs;               // 输入数字
    int InputIdx;                     // 输入索引
    map<string, Function> Funcs;      // 函数
    vector<Token> Tokens;             // 所有Token
    int TokenIdx;                     // Token索引
    VariableStack vs;                 // 变量内存栈
    stack<stack<Token>> Nums;         // 所有INT变量
    stack<stack<Token>> Ops;          // 所有操作符
    stack<map<string, int *>> RefMap; // 变量引用映射
    stack<int> BraceCnt;              // 记录大括号数量（因为可能在{}里突然return）

    /* 获取目前位置的变量。 */
    pair<string, vector<int>> get_variable()
    {
        Token token = Tokens[TokenIdx - 1];
        // cout << token.value << endl;

        if (token.type != T_IDENTIFIER)
        {
            string context = Tokens[TokenIdx - 2].value + " " + token.value + " " + Tokens[TokenIdx].value + "\n";
            throw invalid_argument(context + "Variable's name " +
                                   token.value + " error.");
        }
        string var_name = token.value; // 变量名
        token = Tokens[TokenIdx++];

        /* 多维数组有维度，需要存储。 */
        vector<int> dimensions; // 如果不是数组，就不用加入内容。

        /* 找到数组的维度。 */
        while (token.type == T_LBRACKET)
        {
            if (token.type != T_LBRACKET)
            {
                throw invalid_argument("Array must start with [.");
            }

            int begin_pos = TokenIdx;
            TokenIdx--;
            int end_pos = match_group_symbol() - 1;

            Nums.push(stack<Token>());
            Ops.push(stack<Token>());
            RefMap.push(map<string, int *>());

            int value = run_expression(begin_pos, end_pos);

            Nums.pop();
            Ops.pop();
            RefMap.pop();

            dimensions.push_back(value);

            TokenIdx--;
            token = Tokens[TokenIdx++];
            if (token.type != T_RBRACKET)
            {
                throw invalid_argument("Array must end with ].");
            }

            token = Tokens[TokenIdx++];
        }

        // cout << to_variable_string(make_pair(var_name, dimensions)) << endl;
        return make_pair(var_name, dimensions);
    }

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

    /* 找到末尾。 */
    int find_block_end(int begin_pos)
    {
        int idx = begin_pos;
        int end_pos;

        if (Tokens[begin_pos].type == T_LBRACE)
        {
            int temp_idx = TokenIdx;
            TokenIdx = begin_pos;
            end_pos = match_group_symbol();
            TokenIdx = temp_idx;

            return end_pos;
        }
        else if (Tokens[begin_pos].type == T_FOR ||
                 Tokens[begin_pos].type == T_WHILE)
        {
            idx++;
            if (Tokens[idx].type != T_LPAREN)
            {
                throw invalid_argument("( is expected.");
            }

            int temp_idx = TokenIdx;
            TokenIdx = idx;
            end_pos = match_group_symbol();
            TokenIdx = temp_idx;

            return find_block_end(end_pos + 1);
        }
        else if (Tokens[begin_pos].type == T_IF)
        {
            idx++;
            if (Tokens[idx].type != T_LPAREN)
            {
                throw invalid_argument("( is expected.");
            }

            int temp_idx = TokenIdx;
            TokenIdx = idx;
            end_pos = match_group_symbol();
            TokenIdx = temp_idx;

            end_pos = find_block_end(end_pos + 1);
            if (Tokens[end_pos + 1].type == T_ELSE)
            {
                end_pos = find_block_end(end_pos + 2);
            }

            return end_pos;
        }
        else
        {
            while (Tokens[idx].type != T_SEMICOLON)
            {
                idx++;
            }
            return idx;
        }
    }

    /* 确定操作符的优先级（需要根据上一个token继续确定）。 */
    int OpLevel(Token token)
    {
        if (token.type == T_NOT)
        {
            return 2;
        }
        else if (token.type == T_PLUS || token.type == T_MINUS)
        {
            if (token.value == "$+" || token.value == "$-")
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
        else if (token.type == T_RPAREN || token.type == T_RBRACKET)
        {
            return 12;
        }
        else if (token.type == T_LPAREN || token.type == T_LBRACKET)
        {
            return 12;
        }

        throw invalid_argument("Wrong Operator.");
    }

    /* 判断是否右结合。 */
    bool judge_right_combine(Token token)
    {
        return token.type == T_NOT || token.value == "$+" ||
               token.value == "$-" || token.type == T_ASSIGN;
    }

    /* 将变量转化为字符串。 */
    string to_variable_string(pair<string, vector<int>> var)
    {
        string res;
        res += var.first;
        for (auto e : var.second)
        {
            res += "[";
            res += to_string(e);
            res += "]";
        }

        return res;
    }

    /* 将字符串转化为变量。 */
    pair<string, vector<int>> string_to_var(string var_str)
    {
        int str_size = var_str.size();
        string var_name;
        vector<int> idx;

        int i = 0;
        while (i < str_size && var_str[i] != '[')
        {
            var_name += var_str[i];
            i++;
        }

        while (i < str_size)
        {
            if (var_str[i] != '[')
            {
                throw invalid_argument("Unknown token in variable string.");
            }
            i++;
            if (!isdigit(var_str[i]))
            {
                throw invalid_argument("Array's idx can't be negative.");
            };
            int number = 0;
            while (isdigit(var_str[i]))
            {
                number = number * 10 + (var_str[i] - '0');
                i++;
            }
            idx.push_back(number);
            assert(var_str[i] == ']');
            i++;
        }

        return make_pair(var_name, idx);
    }

    int token_to_value(Token t)
    {
        if (t.type == T_INT_CONSTANT)
        {
            return stoi(t.value);
        }
        else if (t.type == T_IDENTIFIER)
        {
            return *RefMap.top()[t.value];
        }
        else
        {
            throw invalid_argument("Unknown token to transfer into a value.");
        }
    }

    Token value_to_token(int v)
    {
        return {T_INT_CONSTANT, to_string(v)};
    }

    /* 计算操作。 */
    void calculate()
    {
        Token top_op = Ops.top().top();
        Ops.top().pop();

        if (judge_right_combine(top_op))
        {
            Token A = Nums.top().top();
            int a = token_to_value(A);
            Nums.top().pop();

            /* !运算符 */
            if (top_op.type == T_NOT)
            {
                Nums.top().push(value_to_token(a == 0 ? 1 : 0));
                return;
            }
            /* +运算符（正号） */
            else if (top_op.type == T_PLUS)
            {
                Nums.top().push(value_to_token(a));
                return;
            }
            /* -运算符（负号） */
            else if (top_op.type == T_MINUS)
            {
                Nums.top().push(value_to_token(-a));
                return;
            }
            /* =运算符 */
            else if (top_op.type == T_ASSIGN)
            {
                /* Ans = A */
                Token Ans = Nums.top().top();
                Nums.top().pop();

                Nums.top().push(value_to_token(a));
                auto variable = string_to_var(Ans.value);
                vs.set_value(variable.first, variable.second, a);
                return;
            }
            else
            {
                throw invalid_argument("Unknown right combine symbol.");
            }
        }
        else
        {
            Token B = Nums.top().top();
            Nums.top().pop();
            Token A = Nums.top().top();
            Nums.top().pop();

            int a = token_to_value(A);
            int b = token_to_value(B);

            /* *运算符 */
            if (top_op.type == T_MUL)
            {
                Nums.top().push(value_to_token(a * b));
                return;
            }
            /* /运算符 */
            else if (top_op.type == T_DIV)
            {
                Nums.top().push(value_to_token(a / b));
                return;
            }
            /* %运算符 */
            else if (top_op.type == T_MOD)
            {
                Nums.top().push(value_to_token(a % b));
                return;
            }
            /* +运算符 */
            else if (top_op.type == T_PLUS)
            {
                Nums.top().push(value_to_token(a + b));
                return;
            }
            /* -运算符 */
            else if (top_op.type == T_MINUS)
            {
                Nums.top().push(value_to_token(a - b));
                return;
            }
            /* <=运算符 */
            else if (top_op.type == T_LE)
            {
                Nums.top().push(value_to_token(a <= b ? 1 : 0));
                return;
            }
            /* >=运算符 */
            else if (top_op.type == T_GE)
            {
                Nums.top().push(value_to_token(a >= b ? 1 : 0));
                return;
            }
            /* <运算符 */
            else if (top_op.type == T_LT)
            {
                Nums.top().push(value_to_token(a < b ? 1 : 0));
                return;
            }
            /* >运算符 */
            else if (top_op.type == T_GT)
            {
                Nums.top().push(value_to_token(a > b ? 1 : 0));
                return;
            }
            /* ==运算符 */
            else if (top_op.type == T_EQ)
            {
                Nums.top().push(value_to_token(a == b ? 1 : 0));
                return;
            }
            /* !=运算符 */
            else if (top_op.type == T_NE)
            {
                Nums.top().push(value_to_token(a != b ? 1 : 0));
                return;
            }
            /* ^运算符 */
            else if (top_op.type == T_XOR)
            {
                Nums.top().push(value_to_token((a && !b) || (!a && b) ? 1 : 0));
                return;
            }
            /* &&运算符 */
            else if (top_op.type == T_AND)
            {
                Nums.top().push(value_to_token((a && b) ? 1 : 0));
                return;
            }
            /* ||运算符 */
            else if (top_op.type == T_OR)
            {
                Nums.top().push(value_to_token((a || b) ? 1 : 0));
                return;
            }
            else
            {
                throw invalid_argument("Unknown token " + top_op.value + " in calculator.");
            }
        }
    }

    /* 运行一个表达式。 */
    int run_expression(int begin_pos, int end_pos)
    {
        if (begin_pos > end_pos)
        {
            return 0;
        }

        int i = begin_pos;
        while (i <= end_pos)
        {
            /* 如果是常数，直接加入。 */
            if (Tokens[i].type == T_INT_CONSTANT)
            {
                Nums.top().push(Tokens[i]);
            }
            /* 如果是变量，计算或取值后加入。 */
            else if (Tokens[i].type == T_IDENTIFIER)
            {
                /* 函数情况 */
                if (i + 1 <= end_pos &&
                    Tokens[i + 1].type == T_LPAREN)
                {
                    string func_name = Tokens[i].value;
                    vector<int> args;
                    i += 2;
                    int brace_cnt = 1;

                    while (brace_cnt > 0)
                    {
                        int begin = i;
                        while (Tokens[i].type != T_COMMA &&
                               brace_cnt > 0)
                        {
                            if (Tokens[i].type == T_LPAREN)
                            {
                                brace_cnt++;
                            }
                            else if (Tokens[i].type == T_RPAREN)
                            {
                                brace_cnt--;
                            }
                            if (brace_cnt > 0)
                            {
                                i++;
                            }
                        }

                        int end = i - 1;

                        if (end >= begin)
                        {
                            Nums.push(stack<Token>());
                            Ops.push(stack<Token>());
                            RefMap.push(map<string, int *>());

                            args.push_back(run_expression(begin, end));

                            Nums.pop();
                            Ops.pop();
                            RefMap.pop();
                        }

                        if (Tokens[i].type == T_COMMA)
                        {
                            i++;
                        }
                    }

                    /* 特殊函数putchar */
                    if (func_name == "putchar" && (int)args.size() == 1)
                    {
                        Nums.top().push({T_INT_CONSTANT, to_string(putchar(args[0]))});
                    }
                    else
                    {
                        int temp_idx = TokenIdx;
                        int return_num = run_function(func_name, args);
                        Nums.top().push({T_INT_CONSTANT, to_string(return_num)});
                        TokenIdx = temp_idx;
                        assert(!Nums.top().empty());
                    }
                }
                /* 变量情况 */
                else
                {
                    int temp = TokenIdx;
                    TokenIdx = i + 1;
                    auto res = get_variable();
                    i = TokenIdx - 2;
                    TokenIdx = temp;

                    string var_str = to_variable_string(res);
                    int *ref = vs.get_ref(res.first, res.second);
                    assert(!RefMap.empty());
                    // cout << var_str << " " << *ref << endl;
                    RefMap.top()[var_str] = ref;

                    Nums.top().push({T_IDENTIFIER,
                                     var_str});
                }
            }
            /* 运算符情况（目前假设代码是没有语法问题的） */
            else if (OPERATORS.count(Tokens[i].type) > 0)
            {
                /* 左括号，优先压栈。 */
                if (Tokens[i].type == T_LPAREN)
                {
                    Ops.top().push(Tokens[i]);
                }
                /* 右括号，优先把括号内的算完。 */
                else if (Tokens[i].type == T_RPAREN)
                {
                    while (Ops.top().top().type != T_LPAREN)
                    {
                        calculate();
                    }
                    Ops.top().pop();
                }
                else
                {
                    while (!Ops.top().empty())
                    {
                        /* 遇到优先级低的加入，先把优先级高的搞定。 */
                        if (OpLevel(Ops.top().top()) < OpLevel(Tokens[i]) ||
                            (OpLevel(Ops.top().top()) == OpLevel(Tokens[i]) &&
                             !judge_right_combine(Tokens[i])))
                        {
                            calculate();
                        }
                        else
                        {
                            break;
                        }
                    }
                    Ops.top().push(Tokens[i]);
                }
            }
            else
            {
                throw invalid_argument("Error token " + Tokens[i].value + " in expression.");
            }
            i++;
        }

        while (!Ops.top().empty())
        {
            calculate();
        }

        Token ans = Nums.top().top();
        Nums.top().pop();
        if (!Nums.top().empty())
        {
            cout << Nums.top().top().value << endl;
            throw invalid_argument("Unused number in expression");
        }
        int ans_num = token_to_value(ans);
        RefMap.top().clear();
        return ans_num;
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
        /* 如果遇到左括号，那么加入空间。 */
        else if (token.type == T_LBRACE)
        {
            vs.add_block();
            Nums.push(stack<Token>());
            Ops.push(stack<Token>());
            RefMap.push(map<string, int *>());
            BraceCnt.top()++;

            return token;
        }
        /* 如果遇到右括号，那么释放空间。 */
        else if (token.type == T_RBRACE)
        {
            Nums.pop();
            Ops.pop();
            RefMap.pop();
            vs.remove_block();
            BraceCnt.top()--;

            return token;
        }
        /* 输入指令cin >> 变量1 >> 变量2；。 */
        else if (token.type == T_CIN)
        {
            token = Tokens[TokenIdx++];
            while (token.type != T_SEMICOLON)
            {
                int value = Inputs[InputIdx++];

                TokenIdx++;
                auto res = get_variable();
                vs.set_value(res.first, res.second, value);
                token = Tokens[TokenIdx - 1];
            }

            return token;
        }
        /* 输入指令cout << 表达式1 << 表达式2; */
        else if (token.type == T_COUT)
        {
            token = Tokens[TokenIdx++];
            while (token.type != T_SEMICOLON)
            {
                // cout << token.type << " " << token.value << endl;
                if (token.type != T_SHIFT_LEFT)
                {
                    throw invalid_argument("<< should be split symbol in cout.");
                }

                token = Tokens[TokenIdx++];
                if (token.type == T_ENDL)
                {
                    cout << endl;
                    token = Tokens[TokenIdx++];
                }
                else
                {
                    int begin_pos = TokenIdx - 1;
                    while (token.type != T_SHIFT_LEFT &&
                           token.type != T_SEMICOLON)
                    {
                        token = Tokens[TokenIdx++];
                    }
                    int end_pos = TokenIdx - 2;

                    Nums.push(stack<Token>());
                    Ops.push(stack<Token>());
                    RefMap.push(map<string, int *>());

                    cout << run_expression(begin_pos, end_pos);

                    Nums.pop();
                    Ops.pop();
                    RefMap.pop();
                }
            }
            return token;
        }
        /* 输入指令return expression; */
        else if (token.type == T_RETURN)
        {
            int begin_pos = TokenIdx;
            token = Tokens[TokenIdx++];
            while (token.type != T_SEMICOLON)
            {
                token = Tokens[TokenIdx++];
            }
            int end_pos = TokenIdx - 2;

            Nums.push(stack<Token>());
            Ops.push(stack<Token>());
            RefMap.push(map<string, int *>());

            vs.add_return(run_expression(begin_pos, end_pos));

            Nums.pop();
            Ops.pop();
            RefMap.pop();

            int brace_cnt = BraceCnt.top();
            rep(i, 1, brace_cnt + 1)
            {
                Nums.pop();
                Ops.pop();
                RefMap.pop();
                vs.remove_block();
            }
            return token;
        }
        /* 输入指令 if (expression) STATEMENT */
        else if (token.type == T_IF)
        {
            token = Tokens[TokenIdx++];
            if (token.type != T_LPAREN)
            {
                throw invalid_argument("( must follow if.");
            }

            int begin_pos = TokenIdx;
            TokenIdx--;
            int end_pos = match_group_symbol() - 1;

            Nums.push(stack<Token>());
            Ops.push(stack<Token>());
            RefMap.push(map<string, int *>());

            int condition = run_expression(begin_pos, end_pos);

            Nums.pop();
            Ops.pop();
            RefMap.pop();

            bool has_else = false;

            int yes_begin = TokenIdx;
            int yes_end;
            int no_begin;
            int no_end;

            /* 开始找else，如果出现新的if或者超过}的范围，停止寻找。 */
            yes_end = find_block_end(yes_begin);
            has_else = (Tokens[yes_end + 1].type == T_ELSE);

            /* 如果有else，之后运行的代码为else之后；
               否则，之后运行的代码在if控制的范围之后。 */
            if (has_else)
            {
                no_begin = yes_end + 2;
                no_end = find_block_end(no_begin);
            }
            else
            {
                no_begin = yes_end + 1;
            }

            int cur_return_num = vs.get_return_num();

            /* 如果条件为true。 */
            if (condition)
            {
                TokenIdx = yes_begin;
                while (TokenIdx <= yes_end)
                {
                    int new_return_num = vs.get_return_num();
                    if (new_return_num > cur_return_num)
                    {
                        return Tokens[TokenIdx - 1];
                    }
                    run_statement(TokenIdx);
                }

                /* 运行完，如果有else，那么运行else后的内容。 */
                if (has_else)
                {
                    TokenIdx = no_end;
                    return Tokens[TokenIdx++];
                }
                /* 如果没有else，那么运行if后面的内容。 */
                else
                {
                    TokenIdx = yes_end;
                    return Tokens[TokenIdx++];
                }
            }
            /* 如果条件为false */
            else
            {
                /* 如果有else，先运行else里的。 */
                if (has_else)
                {
                    TokenIdx = no_begin;
                    while (TokenIdx <= yes_end)
                    {
                        int new_return_num = vs.get_return_num();
                        if (new_return_num > cur_return_num)
                        {
                            return Tokens[TokenIdx - 1];
                        }
                        run_statement(TokenIdx);
                    }
                    return Tokens[TokenIdx - 1];
                }
                /* 如果没else，直接返回。 */
                else
                {
                    TokenIdx = yes_end;
                    return Tokens[TokenIdx++];
                }
            }
        }
        /* 输入指令 while (expression) STATEMENT */
        else if (token.type == T_WHILE)
        {
            token = Tokens[TokenIdx++];
            if (token.type != T_LPAREN)
            {
                throw invalid_argument("( must follow while.");
            }

            int begin_pos = TokenIdx;
            TokenIdx--;
            int end_pos = match_group_symbol() - 1;

            int while_begin = TokenIdx;
            int while_end = find_block_end(while_begin);
            int cur_return_num = vs.get_return_num();

            Nums.push(stack<Token>());
            Ops.push(stack<Token>());
            RefMap.push(map<string, int *>());

            int condition = run_expression(begin_pos, end_pos);

            Nums.pop();
            Ops.pop();
            RefMap.pop();

            while (condition)
            {
                TokenIdx = while_begin;
                while (TokenIdx <= while_end)
                {
                    int new_return_num = vs.get_return_num();
                    if (new_return_num > cur_return_num)
                    {
                        return Tokens[TokenIdx - 1];
                    }
                    run_statement(TokenIdx);
                }

                Nums.push(stack<Token>());
                Ops.push(stack<Token>());
                RefMap.push(map<string, int *>());

                condition = run_expression(begin_pos, end_pos);

                Nums.pop();
                Ops.pop();
                RefMap.pop();
            }

            TokenIdx = while_end;
            return Tokens[TokenIdx++];
        }
        /* 输入指令 for (expression; expression; expression) STATEMENT */
        else if (token.type == T_FOR)
        {
            token = Tokens[TokenIdx++];
            if (token.type != T_LPAREN)
            {
                throw invalid_argument("( must follow for.");
            }

            int init_begin = TokenIdx;
            int init_end = find_block_end(init_begin) - 1;

            int condition_begin = init_end + 2;
            int condition_end = find_block_end(condition_begin) - 1;

            TokenIdx--;
            int iter_begin = condition_end + 2;
            int iter_end = match_group_symbol() - 1;

            int for_begin = TokenIdx;
            int for_end = find_block_end(for_begin);

            int cur_return_num = vs.get_return_num();

            Nums.push(stack<Token>());
            Ops.push(stack<Token>());
            RefMap.push(map<string, int *>());

            run_expression(init_begin, init_end);

            Nums.pop();
            Ops.pop();
            RefMap.pop();

            Nums.push(stack<Token>());
            Ops.push(stack<Token>());
            RefMap.push(map<string, int *>());

            int condition = run_expression(condition_begin, condition_end);

            Nums.pop();
            Ops.pop();
            RefMap.pop();

            while (condition)
            {
                TokenIdx = for_begin;
                while (TokenIdx <= for_end)
                {
                    int new_return_num = vs.get_return_num();
                    if (new_return_num > cur_return_num)
                    {
                        return Tokens[TokenIdx - 1];
                    }
                    run_statement(TokenIdx);
                }

                Nums.push(stack<Token>());
                Ops.push(stack<Token>());
                RefMap.push(map<string, int *>());

                run_expression(iter_begin, iter_end);

                Nums.pop();
                Ops.pop();
                RefMap.pop();

                Nums.push(stack<Token>());
                Ops.push(stack<Token>());
                RefMap.push(map<string, int *>());

                condition = run_expression(condition_begin, condition_end);

                Nums.pop();
                Ops.pop();
                RefMap.pop();
            }

            TokenIdx = for_end;
            return Tokens[TokenIdx++];
        }
        /* 计算表达式。 */
        else
        {
            int begin_pos = TokenIdx - 1;
            while (token.type != T_SEMICOLON)
            {
                token = Tokens[TokenIdx++];
            }
            int end_pos = TokenIdx - 2;

            Nums.push(stack<Token>());
            Ops.push(stack<Token>());
            RefMap.push(map<string, int *>());

            run_expression(begin_pos, end_pos);
            Nums.pop();
            Ops.pop();
            RefMap.pop();

            return token;
        }

        throw invalid_argument("Unknown token " + token.value + ".");
    };

    /* 运行一个函数，返回值必须是int。 */
    int run_function(string func_name, vector<int> argu_values)
    {
        vs.add_block(); // 一个函数当然算一个代码块
        Nums.push(stack<Token>());
        Ops.push(stack<Token>());
        RefMap.push(map<string, int *>());
        BraceCnt.push(0);

        Function f = Funcs[func_name];
        if (f.Arguments.size() != argu_values.size())
        {
            throw invalid_argument("Unmatched argument number");
        }

        int size = f.Arguments.size();
        rep(i, 0, size - 1)
        {
            vs.push(f.Arguments[i], vector<int>());                      // 参数只能是整型
            vs.set_value(f.Arguments[i], vector<int>(), argu_values[i]); // 赋值
        }

        int return_num = vs.get_return_num();
        int new_return_num = return_num;

        TokenIdx = f.BeginPos;
        Token cur = Tokens[TokenIdx++];
        int pos = f.BeginPos + 1;

        /* 如果返回值的数量没变，说明函数还没结束 */
        while (pos <= f.EndPos && new_return_num == return_num)
        {
            cur = run_statement(pos);
            pos = TokenIdx;
            new_return_num = vs.get_return_num();
        }

        BraceCnt.pop();

        /* 判断是否显式返回。 */
        if (new_return_num > return_num)
        {
            int return_value = vs.fetch_return();
            return return_value;
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
        Nums.push(stack<Token>());
        Ops.push(stack<Token>());
        RefMap.push(map<string, int *>());

        Token token;
        TokenIdx = 0;
        InputIdx = 0;
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
            }
            // 如果不是，代表是语句，需要立刻执行。
            else
            {
                token = run_statement(temp_pos);
            }
        }

        /* 将加法、减法进行处理，如果是右结合，则进行处理。 */
        rep(i, 1, token_size - 1)
        {
            if (Tokens[i].type == T_PLUS || Tokens[i].type == T_MINUS)
            {
                Token last = Tokens[i - 1];
                // 如果前面没有变量，那就说明是右结合
                if (last.type != T_RPAREN && last.type != T_RBRACKET &&
                    last.type != T_IDENTIFIER && last.type != T_INT_CONSTANT)
                {
                    Tokens[i].value = "$" + Tokens[i].value;
                }
            }
        }
    }

public:
    /* 初始化，根据输入和代码进行预处理。 */
    Interpreter(vector<int> inputs, string code) : Inputs(inputs)
    {
        Lexer lexer(code);

        Tokens = lexer.get_tokens();
    }

    /* 运行。 */
    void run()
    {
        /* 预处理。 */
        init();

        run_function("main", vector<int>());
    }
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen(argc == 1 ? "input2.txt" : argv[1], "r", stdin); // 自己调试用
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
}