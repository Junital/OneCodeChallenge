/*****************************************************************
 * 题目：[集训队互测 2015] 未来程序·改
 * 描述：自己做一个编译器。
 * 思路：太复杂，不太能一下子完成。
 * 空间：无
 * 注意：待定。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

//------------------------------
// 词法分析器相关定义
//------------------------------

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
        if (input[pos] == '<')
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

//------------------------------
// 语法分析器（递归下降）
//------------------------------

class Parser
{
public:
    Parser(Lexer &lexer) : lexer(lexer) { nextToken(); }

    // PROGRAM ::= # include < iostream > # include < cstdio > using namespace std ; FUNC_AND_VAR
    void parseProgram()
    {
        match(T_INCLUDE);
        match(T_IOS);
        match(T_INCLUDE);
        match(T_CSTDIO);
        match(T_USING);
        match(T_NAMESPACE);
        match(T_STD);
        match(T_SEMICOLON);
        parseFuncAndVar();
        if (currentToken.type != T_EOF)
            error("Extra tokens after program end.");
    }

private:
    Lexer &lexer;
    Token currentToken;

    void nextToken() { currentToken = lexer.getNextToken(); }

    void error(const string &msg)
    {
        cerr << "Parser Error: " << msg << "\n";
        exit(1);
    }

    string tokenName(TokenType t)
    {
        switch (t)
        {
        case T_INCLUDE:
            return "#include";
        case T_IOS:
            return "<iostream>";
        case T_CSTDIO:
            return "<cstdio>";
        case T_USING:
            return "using";
        case T_NAMESPACE:
            return "namespace";
        case T_STD:
            return "std";
        case T_SEMICOLON:
            return ";";
        case T_INT:
            return "int";
        case T_IF:
            return "if";
        case T_ELSE:
            return "else";
        case T_FOR:
            return "for";
        case T_WHILE:
            return "while";
        case T_RETURN:
            return "return";
        case T_LPAREN:
            return "(";
        case T_RPAREN:
            return ")";
        case T_LBRACE:
            return "{";
        case T_RBRACE:
            return "}";
        case T_LBRACKET:
            return "[";
        case T_RBRACKET:
            return "]";
        case T_COMMA:
            return ",";
        default:
            return "token";
        }
    }

    void match(TokenType t)
    {
        if (currentToken.type == t)
            nextToken();
        else
            error("Expected token " + tokenName(t) + " but found \"" + currentToken.value + "\"");
    }

    // FUNC_AND_VAR ::= ε
    //    | int NAME ( OPTPARAMS ) { STATEMENTS } FUNC_AND_VAR
    //    | int DEFINEVAR DEFINEVARS ; FUNC_AND_VAR
    void parseFuncAndVar()
    {
        while (currentToken.type == T_INT)
        {
            // 首先读 int 后面的标识符
            match(T_INT);
            if (currentToken.type != T_IDENTIFIER)
                error("Expected identifier after int.");
            // 保存标识符名字
            string name = currentToken.value;
            match(T_IDENTIFIER);
            if (currentToken.type == T_LPAREN)
            { // 函数定义
                match(T_LPAREN);
                parseOptParams();
                match(T_RPAREN);
                match(T_LBRACE);
                parseStatements();
                match(T_RBRACE);
            }
            else
            { // 变量定义
                // 此处：DEFINEVAR 已经读入了 NAME（及可能的数组部分）
                parseDefineVarRest(); // 处理 NAME 后面的 [ INT_CONSTANT ]（可重复）
                parseDefineVars();
                match(T_SEMICOLON);
            }
        }
    }

    // OPTPARAMS ::= ε | int NAME PARAMS
    void parseOptParams()
    {
        if (currentToken.type == T_INT)
        {
            match(T_INT);
            if (currentToken.type != T_IDENTIFIER)
                error("Expected parameter name.");
            match(T_IDENTIFIER);
            parseParams();
        }
        // 否则为空
    }

    // PARAMS ::= ε | , int NAME PARAMS
    void parseParams()
    {
        while (currentToken.type == T_COMMA)
        {
            match(T_COMMA);
            match(T_INT);
            if (currentToken.type != T_IDENTIFIER)
                error("Expected parameter name.");
            match(T_IDENTIFIER);
        }
    }

    // STATEMENTS ::= ε | STATEMENT STATEMENTS
    void parseStatements()
    {
        while (isStatementStart())
            parseStatement();
    }

    // 判断是否能开始一个语句
    bool isStatementStart()
    {
        // 这里简单判断：{, int, if, for, while, return, 或表达式开始的标识符等
        if (currentToken.type == T_LBRACE ||
            currentToken.type == T_INT ||
            currentToken.type == T_IF ||
            currentToken.type == T_FOR ||
            currentToken.type == T_WHILE ||
            currentToken.type == T_RETURN)
            return true;
        // 对于表达式起始：identifier, cin, cout, endl, int_constant, +, -, !, (
        if (currentToken.type == T_IDENTIFIER || currentToken.type == T_CIN ||
            currentToken.type == T_COUT || currentToken.type == T_ENDL ||
            currentToken.type == T_INT_CONSTANT || currentToken.type == T_PLUS ||
            currentToken.type == T_MINUS || currentToken.type == T_NOT ||
            currentToken.type == T_LPAREN)
            return true;
        return false;
    }

    // STATEMENT ::=
    //    EXPRESSION ;
    //    | { STATEMENTS }
    //    | int DEFINEVAR DEFINEVARS ;
    //    | if ( EXPRESSION ) STATEMENT
    //    | if ( EXPRESSION ) STATEMENT else STATEMENT
    //    | for ( STATEMENT_IN_FOR ; OPTEXPRESSION ; STATEMENT_IN_FOR ) STATEMENT
    //    | while ( EXPRESSION ) STATEMENT
    //    | return EXPRESSION ;
    void parseStatement()
    {
        if (currentToken.type == T_LBRACE)
        {
            match(T_LBRACE);
            parseStatements();
            match(T_RBRACE);
        }
        else if (currentToken.type == T_INT)
        {
            // 变量定义语句
            match(T_INT);
            parseDefineVarRest();
            parseDefineVars();
            match(T_SEMICOLON);
        }
        else if (currentToken.type == T_IF)
        {
            match(T_IF);
            match(T_LPAREN);
            parseExpression();
            match(T_RPAREN);
            parseStatement();
            if (currentToken.type == T_ELSE)
            {
                match(T_ELSE);
                parseStatement();
            }
        }
        else if (currentToken.type == T_FOR)
        {
            match(T_FOR);
            match(T_LPAREN);
            parseStatementInFor();
            match(T_SEMICOLON);
            parseOptExpression();
            match(T_SEMICOLON);
            parseStatementInFor();
            match(T_RPAREN);
            parseStatement();
        }
        else if (currentToken.type == T_WHILE)
        {
            match(T_WHILE);
            match(T_LPAREN);
            parseExpression();
            match(T_RPAREN);
            parseStatement();
        }
        else if (currentToken.type == T_RETURN)
        {
            match(T_RETURN);
            parseExpression();
            match(T_SEMICOLON);
        }
        else
        {
            // 表达式语句
            parseExpression();
            match(T_SEMICOLON);
        }
    }

    // STATEMENT_IN_FOR ::= OPTEXPRESSION | int DEFINEVAR DEFINEVARS
    void parseStatementInFor()
    {
        if (currentToken.type == T_INT)
        {
            match(T_INT);
            parseDefineVarRest();
            parseDefineVars();
        }
        else
        {
            parseOptExpression();
        }
    }

    // OPTEXPRESSION ::= ε | EXPRESSION
    void parseOptExpression()
    {
        if (isExpressionStart())
            parseExpression();
    }

    bool isExpressionStart()
    {
        if (currentToken.type == T_INT_CONSTANT ||
            currentToken.type == T_IDENTIFIER ||
            currentToken.type == T_CIN ||
            currentToken.type == T_COUT ||
            currentToken.type == T_ENDL ||
            currentToken.type == T_PLUS ||
            currentToken.type == T_MINUS ||
            currentToken.type == T_NOT ||
            currentToken.type == T_LPAREN)
            return true;
        return false;
    }

    // 表达式部分，这里简单实现：先处理 UNIT9，再处理 << 与 >> 运算符
    // EXPRESSION ::= UNIT9 | EXPRESSION << UNIT9 | EXPRESSION >> UNIT9
    void parseExpression()
    {
        parseUnit9();
        while (currentToken.type == T_SHIFT_LEFT || currentToken.type == T_SHIFT_RIGHT)
        {
            nextToken();
            parseUnit9();
        }
    }

    // UNIT9 ::= UNIT8 | UNIT8 = UNIT9
    void parseUnit9()
    {
        parseUnit8();
        if (currentToken.type == T_ASSIGN)
        {
            match(T_ASSIGN);
            parseUnit9();
        }
    }

    // 以下各级表达式（为了简单起见，优先级划分大致实现）
    // UNIT8 ::= UNIT7 | UNIT8 || UNIT7
    void parseUnit8()
    {
        parseUnit7();
        while (currentToken.type == T_OR)
        {
            match(T_OR);
            parseUnit7();
        }
    }
    // UNIT7 ::= UNIT6 | UNIT7 && UNIT6
    void parseUnit7()
    {
        parseUnit6();
        while (currentToken.type == T_AND)
        {
            match(T_AND);
            parseUnit6();
        }
    }
    // UNIT6 ::= UNIT5 | UNIT6 ^ UNIT5
    void parseUnit6()
    {
        parseUnit5();
        while (currentToken.type == T_XOR)
        {
            match(T_XOR);
            parseUnit5();
        }
    }
    // UNIT5 ::= UNIT4 | UNIT5 == UNIT4 | UNIT5 != UNIT4
    void parseUnit5()
    {
        parseUnit4();
        while (currentToken.type == T_EQ || currentToken.type == T_NE)
        {
            nextToken();
            parseUnit4();
        }
    }
    // UNIT4 ::= UNIT3 | UNIT4 < UNIT3 | UNIT4 <= UNIT3 | UNIT4 > UNIT3 | UNIT4 >= UNIT3
    void parseUnit4()
    {
        parseUnit3();
        while (currentToken.type == T_LT || currentToken.type == T_LE ||
               currentToken.type == T_GT || currentToken.type == T_GE)
        {
            nextToken();
            parseUnit3();
        }
    }
    // UNIT3 ::= UNIT2 | UNIT3 + UNIT2 | UNIT3 - UNIT2
    void parseUnit3()
    {
        parseUnit2();
        while (currentToken.type == T_PLUS || currentToken.type == T_MINUS)
        {
            nextToken();
            parseUnit2();
        }
    }
    // UNIT2 ::= UNIT1 | UNIT2 * UNIT1 | UNIT2 / UNIT1 | UNIT2 % UNIT1
    void parseUnit2()
    {
        parseUnit1();
        while (currentToken.type == T_MUL || currentToken.type == T_DIV ||
               currentToken.type == T_MOD)
        {
            nextToken();
            parseUnit1();
        }
    }
    // UNIT1 ::= UNIT0 | + UNIT1 | - UNIT1 | ! UNIT1
    void parseUnit1()
    {
        if (currentToken.type == T_PLUS || currentToken.type == T_MINUS || currentToken.type == T_NOT)
        {
            nextToken();
            parseUnit1();
        }
        else
        {
            parseUnit0();
        }
    }
    // UNIT0 ::= INT_CONSTANT | UNIT0 [ EXPRESSION ] | ( EXPRESSION ) | NAME ( OPTARGUS ) | NAME | cin | cout | endl
    void parseUnit0()
    {
        if (currentToken.type == T_INT_CONSTANT)
        {
            match(T_INT_CONSTANT);
        }
        else if (currentToken.type == T_IDENTIFIER)
        {
            match(T_IDENTIFIER);
            // 可能是函数调用或数组下标
            if (currentToken.type == T_LPAREN)
            {
                match(T_LPAREN);
                parseOptArgus();
                match(T_RPAREN);
            }
            else
            {
                // 数组下标可连续出现
                while (currentToken.type == T_LBRACKET)
                {
                    match(T_LBRACKET);
                    parseExpression();
                    match(T_RBRACKET);
                }
            }
        }
        else if (currentToken.type == T_CIN)
        {
            match(T_CIN);
        }
        else if (currentToken.type == T_COUT)
        {
            match(T_COUT);
        }
        else if (currentToken.type == T_ENDL)
        {
            match(T_ENDL);
        }
        else if (currentToken.type == T_LPAREN)
        {
            match(T_LPAREN);
            parseExpression();
            match(T_RPAREN);
        }
        else
        {
            error("Unexpected token in expression: \"" + currentToken.value + "\"");
        }
    }
    // OPTARGUS ::= ε | EXPRESSION ARGUS
    void parseOptArgus()
    {
        if (isExpressionStart())
        {
            parseExpression();
            parseArgus();
        }
    }
    // ARGUS ::= ε | , EXPRESSION ARGUS
    void parseArgus()
    {
        while (currentToken.type == T_COMMA)
        {
            match(T_COMMA);
            parseExpression();
        }
    }

    // 变量定义部分
    // DEFINEVAR ::= NAME | DEFINEVAR [ INT_CONSTANT ]
    // 此处在 parseFuncAndVar() 中已经读入了第一个标识符，
    // 故此函数处理后续可能的数组下标部分
    void parseDefineVarRest()
    {
        while (currentToken.type == T_LBRACKET)
        {
            match(T_LBRACKET);
            if (currentToken.type != T_INT_CONSTANT)
                error("Expected int constant in array size.");
            match(T_INT_CONSTANT);
            match(T_RBRACKET);
        }
    }
    // DEFINEVARS ::= ε | , DEFINEVAR DEFINEVARS
    void parseDefineVars()
    {
        while (currentToken.type == T_COMMA)
        {
            match(T_COMMA);
            if (currentToken.type != T_IDENTIFIER)
                error("Expected identifier in variable definition.");
            match(T_IDENTIFIER);
            parseDefineVarRest();
        }
    }
};

// ------------------------------
// main 函数：读入整个文件内容并启动词法、语法分析
// ------------------------------

int main()
{
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        cout << arr[i] << endl;
    }

    cin.clear();

    // 读取整个输入文件（源代码）
    string remaining_content(
        (istreambuf_iterator<char>(cin)), // 从当前位置开始
        istreambuf_iterator<char>()       // 结束标志
    );

    Lexer lexer(remaining_content);
    Parser parser(lexer);
    parser.parseProgram();

    cout << "Parsing completed successfully!" << "\n";
    return 0;
}
