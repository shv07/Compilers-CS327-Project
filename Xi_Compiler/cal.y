/*
 * Collaborators:
 * Deepak
 */
%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>  
#include <math.h>/* For math functions, cos(), sin(), etc. */
#include "cal.h"  /* Contains definition of `symrec'        */
#define kMyString "Line 1"\
                  "Line 2"
int  yylex(void);
void yyerror (char  *); 
int Adr = 0;
int label=0;
int current = 0;
struct symrec *sym_table = (struct symrec *)0;
void putsym (symrec* ptr, int size);
struct StmtsNode *stmtsnode;
struct StmtNode *stmtnode;


%}
%union { // yylval ka defination
int val;  /* For returning numbers.                   */
int len;
symrec *tptr;   /* For returning symbol-table pointers      */
char *string;
struct nody * nn;
}


%token <tptr> IDENTIFIER
%token <val> INUM
%token <string> USE
%token <string> INT
%token <string> BOOL
%token <string> STRING
%token <string> IF
%token <string> ELSE
%token <string> WHILE
%token <string> GOTO
%token <string> CONTINUE
%token <string> MAIN
%token <string> BREAK
%token <string> RETURN
%token <string> SUDODEC

/* Now we define nodes */
%type <string> FunctionDeclaration
%type <string> Main_F
%type <string> Op_F
%type <string> ParameterList
%type <string> Parameter
%type <val> TypeSpecifier
%type <val> IsArray
%type <nn> StatementList
%type <nn> Statement
%type <nn> CompoundStatement
%type <val> RelationalOperator
%type <nn> Expression
%type <nn> SimplifiedExpression
%type <nn> AndExpression
%type <nn> UnaryExpression
%type <nn> RelationalExpression
%type <nn> AddExpression
%type <nn> Term
%type <nn> Factor
%type <nn> Change
%type <nn> NotChange
%type <nn> UExp
%type <nn> CustomDecAss

%type <string> Call
%type <string> ArgList
%type <nn> IterStatement
%type <nn> CondStatement
%type <string> ReturnStatement
%type <string> ReturnProcedure
%type <string> ReturnFunction
%type <string> TypeSpecificationList

%right '='
%left '-' '+'
%left '*' '/'
%left NEG     /* Negation--unary minus */
%right '^'    /* Exponentiation        */

%%

FunctionDeclaration:
  Op_F Main_F {}
  ;

Main_F:
  MAIN '(' ParameterList ')' CompoundStatement  {printf("%s", $5->code);
  }
  ;

Op_F:
  IDENTIFIER ':' '(' ParameterList ')' TypeSpecificationList CompoundStatement {}
  | {//printf("op func empty aaya!\n");
  }
  ;

ParameterList:
  ParameterList ',' Parameter {}
  | Parameter {}
  | {//printf("parameters are empty\n");
  }
  ;

Parameter: 
  IDENTIFIER ':' TypeSpecifier {}
  ;

TypeSpecifier:
  INT IsArray {$$=$2;}
  | BOOL IsArray {$$=$2;}
  ;

IsArray:
  '[' INUM ']' {
                // printf("we getting to isArray\n"); 
                $$=$2;
                }
  | {$$=0;}
  ;

CustomDecAss:
  IDENTIFIER ':' TypeSpecifier ';' {//typspecifier will be array size
                              $$ = (struct nody *)(malloc(sizeof(struct nody)));
                              $$->code = (char *)malloc(sizeof(char) * 10000);
                              if ($3 > 0){
                                // printf("array");
                              }
                              else {
                                // printf("variable");
                              }
                              putsym($1 ,$3);
                              // printf("blhblh id: %s, addr: %d\n", $1->name, $1->addr);
                              $$->id_rec = $1;
                              $$->isAssign = 0;
                             }
  | Change '=' Expression ';' { 
                                $$ = (struct nody *)(malloc(sizeof(struct nody)));
                                $$->code = (char *)malloc(sizeof(char) * 10000);
                                $$->isAssign = 1;
                                sprintf($$->code, "%s\n"
                                                  "%s\n"
                                                  "sw $t0 0($t9)\n"
                                                  "%s\n"
                                                  "lw $t1 0($t9)\n"
                                                  "sw $t0 0($t1)\n",
                                                  $1->code,
                                                  $1->addr_code,
                                                  $3->code); // stored value at $t0
                                $$->id_rec = NULL;
                              }
  ;

StatementList:
  Statement StatementList {
                                      $$ = (struct nody* ) malloc(sizeof(struct nody));
                                      $$->code = (char *) malloc(sizeof(char)*10000);
                                      sprintf($$->code, "%s\n%s\n%s\n",$$->code, $1->code, $2->code);
}
  | {
                                      $$ = (struct nody* ) malloc(sizeof(struct nody));
                                      $$->code = (char *) malloc(sizeof(char)*10000);
                                      sprintf($$->code, "\n");
}
  ;

Statement:
  CompoundStatement {
                                      $$ = (struct nody* ) malloc(sizeof(struct nody));
                                      $$->code = (char *) malloc(sizeof(char)*10000);
                                      sprintf($$->code, "%s\n%s\n",$$->code, $1->code);
                                      }
  | CondStatement {
                                      $$ = (struct nody* ) malloc(sizeof(struct nody));
                                      $$->code = (char *) malloc(sizeof(char)*10000);
                                      sprintf($$->code, "\n");
}
  | IterStatement {
    $$ = (struct nody* ) malloc(sizeof(struct nody));
    $$->code = (char *) malloc(sizeof(char)*10000);
    sprintf($$->code, "%s\n%s\n",$$->code, $1->code);
    }
  | ReturnStatement {}
  | CustomDecAss {//printf("code: %s", $1->code);
  }
  ;

CompoundStatement:
  '{' StatementList '}' {
                                      $$ = (struct nody* ) malloc(sizeof(struct nody));
                                      $$->code = (char *) malloc(sizeof(char)*10000);
                                      sprintf($$->code, "%s\n%s\n",$$->code, $2->code);
                                      // printf("%s", $$->code);
}
  ;

IterStatement:
  WHILE Expression CompoundStatement {//printf("Got out of while statement\n");
                                      $$ = (struct nody* ) malloc(sizeof(struct nody));
                                      $$->code = (char *) malloc(sizeof(char)*10000);
                                      sprintf($$->code, "%s\n%s Label%d",$$->code, $2->code,current+1);
                                      sprintf($$->code, "%s\n%s \nj Label%d\n",$$->code, $3->code, current);
                                      sprintf($$->code, "%s \nLabel%d:\n",$$->code, current+1);
  }
  ;

CondStatement:
  IF Expression CompoundStatement {}
  | IF Expression CompoundStatement ELSE CompoundStatement {}
  ;

ReturnStatement:
  ReturnFunction {}
  | ReturnProcedure {}
  ;

ReturnFunction:
  RETURN Expression ';' {}
  ;

ReturnProcedure:
  RETURN ';' {}
  ;

Expression:
  SimplifiedExpression {$$ = $1;}
  ;

SimplifiedExpression:
  SimplifiedExpression '|' AndExpression {}
  | AndExpression {$$ = $1;}
  ;

AndExpression:
  AndExpression '&' UnaryExpression {}
  | UnaryExpression {$$ = $1;}
  ;

UnaryExpression:
  '!' UnaryExpression {}
  | RelationalExpression {$$ = $1;}
  ;

RelationalExpression:
  AddExpression RelationalOperator AddExpression { 

        $$ = (struct nody* ) malloc(sizeof(struct nody));
        $$->code = (char *) malloc(sizeof(char)*10000);
      sprintf($$->code, "%s\n%s\n"
                        "sw $t0, 0($t9)\n"
                        "%s\n"
                        "lw $t1, 0($t9)",
                        $$->code,
                        $1->code,
                        $3->code);
                        sprintf($$->code, "%s\nLabel%d:\n",$$->code, label);
                        current = label++;
    if($2==1) sprintf($$->code, "%s\nble $t1, $t0, ", $$->code);
    if($2==2) sprintf($$->code, "%s\nbge $t0, $t1, ", $$->code);
    if($2==3) sprintf($$->code, "%s\nble $t0, $t1, ",$$->code);
    if($2==4){
                        sprintf($$->code, "%s\nbge $t1, $t0, ", $$->code);

    }
    if($2==5){
                        sprintf($$->code, "%s\nbeq $t0, $t1, ", $$->code);

    }
    if($2==6){
                        sprintf($$->code, "%s\nbne $t0, $t1, ", $$->code);

    }
  }
  | AddExpression {$$ = $1;}
  ;

RelationalOperator:
  "<=" {$$ = 1;}
  | '<' {$$ = 2;}
  | '>' {$$ = 3;}
  | ">=" {$$ = 4;}
  | "==" {$$ = 5;}
  | "!=" {$$ = 6;}
  ;

AddExpression:
  Term '+' AddExpression {
                        sprintf($$->code, "%s\n"
                                          "%s\n"
                                          "sw $t0 0($t9)\n"
                                          "%s\n"
                                          "lw $t1 0($t9)\n"
                                          "add $t0 $t1 $t0\n",
                                          $$->code, $1->code, $3->code);
    // $$->code += $1->code sw $t0 0($t9) + $3->code lw $t1 0($t9) add $t0 $t1 $t0}
  }

  | Term '-' AddExpression {
                            sprintf($$->code, "%s\n"
                                          "%s\n"
                                          "sw $t0 0($t9)\n"
                                          "%s\n"
                                          "lw $t1 0($t9)\n"
                                          "sub $t0 $t1 $t0\n",
                                          $$->code, $1->code, $3->code);
  }
  | Term {$$ = $1;}
  ;

Term:
  Term '*' UExp  {
    
                            sprintf($$->code, "%s\n"
                                          "%s\n"
                                          "sw $t0 0($t9)\n"
                                          "%s\n"
                                          "lw $t1 0($t9)\n"
                                          "mul $t0 $t1 $t0\n",
                                          $$->code, $1->code, $3->code);
  // $$->code = $1->code sw $t0 0($t9) + $3->code lw $t1 0($t9) mul $t0 $t1 $t0}
  }
  | Term '/' UExp  {
                            sprintf($$->code, "%s\n"
                                          "%s\n"
                                          "sw $t0 0($t9)\n"
                                          "%s\n"
                                          "lw $t1 0($t9)\n"
                                          "div $t0 $t1 $t0\n",
                                          $$->code, $1->code, $3->code);
    // $$->code = $1->code sw $t0 0($t9) + $3->code lw $t1 0($t9) div $t0 $t1 $t0
  }
  | UExp {$$ = $1;}
  ;

UExp:
  '-' UExp {$$ = $2;
          sprintf($$->code, "%s\n"
                           "sub $t0 $0 $t0\n",
                           $$->code);
  }
  | Factor {$$ = $1;}
  ;

Factor:
  Change {$$ = $1;}
  | NotChange {$$ = $1;}
  ;

Change:
  IDENTIFIER {
            $1 = getsym ($1->name);
            $$ = (struct nody *)(malloc(sizeof(struct nody)));
            $$->find_value = (char *)malloc(sizeof(char) * 10000);
            $$->code = (char *)malloc(sizeof(char) * 10000);
            $$->addr_code = (char *)malloc(sizeof(char) * 10000);

            sprintf($$->addr_code, "li $t0 %d\n"
                                   "muli $t0 $t0 4\n"
                                   "add $t0 $t0 $t8\n", $1->addr);
            sprintf($$->find_value, "lw $t0 %d($t8)\n", $1->addr);
  }
  | IDENTIFIER '[' Expression ']' {
            $1 = getsym ($1->name);
            $$ = (struct nody *)(malloc(sizeof(struct nody)));
            $$->find_value = (char *)malloc(sizeof(char) * 10000);
            $$->code = (char *)malloc(sizeof(char) * 10000);
            $$->addr_code = (char *)malloc(sizeof(char) * 10000);

            sprintf($$->code, "%s\n", $3->code); // expression calcs on $t0
            sprintf($$->addr_code, "muli $t1 $t0 4\n"
                                    "lw $t0 %d($t8)\n"
                                    "add $t0 $t1 $t0\n", $1->addr); // expression calcs on $t0
            sprintf($$->find_value, "muli $t1 $t0 4\n"
                                    "lw $t2 %d($t8)\n"
                                    "add $t1 $t1 $t2\n"
                                    "lw $t0 0($t1)\n", $1->addr); // expression calcs on $t0

  // $$->find_value = lw $t0 4*($t0)($1->addr)
  // $$->addr = lw $t1 $1->addr($t8) \n muli $t0 $t0 4 \n add $t0 $t1 $t0
  }
  ;

NotChange:
  '(' Expression ')' {$$ = $2;}
  | Call {
            $$ = (struct nody *)(malloc(sizeof(struct nody)));
            $$->find_value = (char *)malloc(sizeof(char) * 10000);
            $$->code = (char *)malloc(sizeof(char) * 10000);
            $$->addr_code = (char *)malloc(sizeof(char) * 10000);
          }
  | INUM { 
            $$ = (struct nody *)(malloc(sizeof(struct nody)));
            $$->find_value = (char *)malloc(sizeof(char) * 10000);
            $$->code = (char *)malloc(sizeof(char) * 10000);
            $$->addr_code = (char *)malloc(sizeof(char) * 10000);

            // stroing the code for getting the value (no other options)
            sprintf($$->code, "li $t0 %d\n", $1);
            }
  | BOOL {}

  ;

TypeSpecificationList:
  TypeSpecificationList ',' TypeSpecifier {}
  | TypeSpecifier {}
  | {}
  ;

Call:
  IDENTIFIER '(' Args ')' {}
  ;

Args:
  ArgList {}
  | {}
  ;

ArgList:
  ArgList ',' Expression {}
  | Expression {}
  ;

%%
/* End of grammar */


/* The symbol table: a chain of `struct symrec'.  */

void putsym (symrec* ptr, int size) {
  // printf("id: %s addr %d\n", ptr->name, Adr);
  ptr->addr = Adr;
  if (size > 0){
    Adr = Adr+4*size;
  }
  else{
    Adr = Adr+4;
  }
  ptr->next = (struct symrec *)sym_table;
  sym_table = ptr;
}

symrec *getsym (char *sym_name) {
  symrec *ptr;
  for (ptr = sym_table; ptr != (symrec *) 0;
       ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name, sym_name) == 0)
      return ptr;
  return 0; 
}
int main ()
{
   yyparse ();
}

void yyerror (char *s)  /* Called by yyparse on error */
{
  printf ("%s\n", s);
}

