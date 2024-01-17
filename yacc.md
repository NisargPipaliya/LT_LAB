## Yacc

```
Source Code -> lex(Scanner) -(tokens)-> Yacc(syntax analyzer/parser) -(parse tree)-> 
                |                           |
                |--> symbol table     <---  |

                Types od Errors
                - Compile Time              - Runtime
                    - Lexical error             - Stackoverflow
                    - Syntax error              - index out of bound
                    - Semantic error            - memory out of bound(heap overflow)
```
```c
// it has syntax error, and not lexical error.
(a=5)if{
    printf(a);
}
```

### Sementic error
- data type mismatch
- type casting conv.


```
lex( Extension .lex)
    - Token Recognization
        - Regular Lang
            - Regular Expression

Yacc(Extension .y)
    - Syntax Checking
        - Context Free Lang
            - Context Free Grammer
                - Parse Tree
    - Works on LALR parser.

In Shift reduce and operator predence parser, we go bottom-up therefore we do not remove Left factoring and left recursion.

In shift reduce parser, we have shift-shift conflict and shift-reduce conflict.
Operator Precedence
    - we need operand operator operand format
    - applies to grammer with operator
    - not applicable to unary minus
    - not applicable to null
```

```c
%{
global variables, prototype, comments
%}

Defination section

%%
production rule section
%%
c code
```