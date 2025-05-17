# First集和Follow集

```c++
PROGRAM ::= # include < iostream > # include < cstdio > using namespace std ; FUNC_AND_VAR

FUNC_AND_VAR ::=
| ε
| int NAME ( OPTPARAMS ) { STATEMENTS } FUNC_AND_VAR
| int DEFINEVAR DEFINEVARS ; FUNC_AND_VAR

OPTPARAMS ::=
| ε
| int NAME PARAMS

PARAMS ::=
| ε
| , int NAME PARAMS

STATEMENTS ::=
| ε
| STATEMENT STATEMENTS

STATEMENT ::=
| EXPRESSION ;
| { STATEMENTS }
| int DEFINEVAR DEFINEVARS ;
| if ( EXPRESSION ) STATEMENT
| if ( EXPRESSION ) STATEMENT else STATEMENT
| for ( STATEMENT_IN_FOR ; OPTEXPRESSION ; STATEMENT_IN_FOR ) STATEMENT
| while ( EXPRESSION ) STATEMENT
| return EXPRESSION ;

STATEMENT_IN_FOR ::=
| OPTEXPRESSION
| int DEFINEVAR DEFINEVARS

OPTEXPRESSION ::=
| ε
| EXPRESSION

EXPRESSION ::=
| UNIT9
| EXPRESSION << UNIT9
| EXPRESSION >> UNIT9

UNIT0 ::=
| INT_CONSTANT
| UNIT0 [ EXPRESSION ]
| ( EXPRESSION )
| NAME ( OPTARGUS )    // 注：此处的 NAME 是一个函数名
| NAME    // 注：此处的 NAME 是一个变量名
| cin
| cout
| endl

UNIT1 ::=
| UNIT0
| + UNIT1
| - UNIT1
| ! UNIT1

UNIT2 ::=
| UNIT1
| UNIT2 * UNIT1
| UNIT2 / UNIT1
| UNIT2 % UNIT1

UNIT3 ::=
| UNIT2
| UNIT3 + UNIT2
| UNIT3 - UNIT2

UNIT4 ::=
| UNIT3
| UNIT4 < UNIT3
| UNIT4 <= UNIT3
| UNIT4 > UNIT3
| UNIT4 >= UNIT3

UNIT5 ::=
| UNIT4
| UNIT5 == UNIT4
| UNIT5 != UNIT4

UNIT6 ::=
| UNIT5
| UNIT6 ^ UNIT5

UNIT7 ::=
| UNIT6
| UNIT7 && UNIT6

UNIT8 ::=
| UNIT7
| UNIT8 || UNIT7

UNIT9 ::=
| UNIT8
| UNIT8 = UNIT9

OPTARGUS ::=
| ε
| EXPRESSION ARGUS

ARGUS ::=
| ε
| , EXPRESSION ARGUS

DEFINEVARS ::=
| ε
| , DEFINEVAR DEFINEVARS

DEFINEVAR ::=
| NAME
| DEFINEVAR [ INT_CONSTANT ]

NAME ::= 仅包含大小写字母、数字、下划线的非空字符串，且不以数字开头。

INT_CONSTANT ::= 仅包含数字的非空字符串，且不以0开头，或这个字符串就是0。
```

## First

|非终结符$X$|$\text{First}(X)$|
|---|---|
|`PROGRAM`|#include|
|`FUNC_AND_VAR`|$\varepsilon$、int|
|`OPTPARAMS`|$\varepsilon$、int|
|`PARAMS`|$\varepsilon$、int|
|`STATEMENTS`|$\varepsilon$、`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!、{、int、if、for、while、return|
|`STATEMENT`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!、{、int、if、for、while、return|
|`STATEMENT_IN_FOR`|$\varepsilon$、`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!、int|
|`OPTEXPRESSION`|$\varepsilon$、`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!|
|`EXPRESSION`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!|
|`UNIT0`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl|
|`UNIT0`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl|
|`UNIT1`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!|
|`UNIT2`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!|
|`UNIT3`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!|
|`UNIT4`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!|
|`UNIT5`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!|
|`UNIT6`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!|
|`UNIT7`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!|
|`UNIT8`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!|
|`UNIT9`|`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!|
|`OPTARGUS`|$\varepsilon$、`INT_CONSTANT`、(、`NAME`、cin、cout、endl、+、-、!|
|`ARGUS`|$\varepsilon$、,|
|`DEFINEVARS`|,、$\varepsilon$|
|`DEFINEVAR`|`NAME`|
