%{
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
  
#include "ershov.h"  /* Contains definition of `symrec'        */
#define MAX(a,b)((a>b)?a:b)
int R;
int count_temps;
int  yylex(void);
void yyerror (char  *); 
struct StmtsNode *final;
void expparse(struct StmtNode* ptr);
void tparse(struct reg_node* ptr);
%}
%union {
int   val;  /* For returning numbers.                   */
struct symrec  *tptr;   /* For returning symbol-table pointers      */
char c[10000];
char nData[100];
struct reg_node *node;
struct StmtsNode *stmtsnode;
struct StmtNode *stmtnode;
}


%token  <val> NUM        /* Integer   */
%token <tptr> VAR   
%type  <node>  exp
%type <node> x
%type <stmtnode> stmt;
%type <stmtsnode> stmts;
%right '='
%left '-' '+'
%left '*' '/'
%left '(' ')'

%%
/* Grammar Starts */
prog: stmts   {final = $1;
				// printf("start\n");
				
				}
;
stmts:	stmt	{$$=(struct StmtsNode *) malloc(sizeof(struct StmtsNode));
				$$->left = $1;
				$$->right = NULL;
				// printf("stmts\n");
				}
		| stmt stmts	{$$=(struct StmtsNode *) malloc(sizeof(struct StmtsNode));
						$$->left = $1;
						$$->right = $2;
					// printf("junk");
						}
;
stmt:	VAR '=' exp '\n'	{
							// printf("entered something stmt\n");
							$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
							$$->down = $3;
							$$->left_id_details = $1;
							// printf("stnmt var got || %s\n", $$->left_id_details->name);
							}		
		//|error '\n' {yyerrok;}
;
exp:	x				{$$ = $1;
						// printf("we should be hre\n");
						}
		|exp '+' exp	{$$=(struct reg_node *) malloc(sizeof(struct reg_node));
						if($1->ersh==$3->ersh)
							 $$->ersh = $1->ersh + 1;
						 else
							 $$->ersh = MAX($1->ersh,$3->ersh);
						//printf("%d lineno: %d\n",$$->ersh, __LINE__);
						$$->left = $1;
						$$->right = $3;
						$$->op = strdup("add");
					// printf("add exp\n");
					}
						
		|exp '-'exp		{$$=(struct reg_node *) malloc(sizeof(struct reg_node));
						if($1->ersh==$3->ersh)
							 $$->ersh = $1->ersh + 1;
						 else
							 $$->ersh = MAX($1->ersh,$3->ersh);
						$$->op = strdup("sub");
						//printf("%d lineno: %d\n",$$->ersh, __LINE__);
						$$->left = $1;
						$$->right = $3;}
						
		|exp '*'exp		{$$=(struct reg_node *) malloc(sizeof(struct reg_node));
						if($1->ersh==$3->ersh)
							 $$->ersh = $1->ersh + 1;
						 else
							 $$->ersh = MAX($1->ersh,$3->ersh);
						
						$$->op = strdup("mul");
						//printf("%d lineno: %d\n",$$->ersh, __LINE__);
						$$->left = $1;
						$$->right = $3;}
						
		|exp '/'exp		{$$=(struct reg_node *) malloc(sizeof(struct reg_node));
						if($1->ersh==$3->ersh)
							 $$->ersh = $1->ersh + 1;
						 else
							 $$->ersh = MAX($1->ersh,$3->ersh);
						//printf("%d lineno: %d\n",$$->ersh, __LINE__);
						$$->op = strdup("div");	
						$$->left = $1;
						$$->right = $3;}
						
		|'('exp')'		{$$=$2;
						}
;
x:		NUM		{
				$$ = (struct reg_node *)malloc(sizeof(struct reg_node));
				$$->ersh = 1;
				$$->value = $1;
				$$->int_flag =1; 
				// printf("num got\n");
				}
		|VAR	{
				$$ = (struct reg_node *)malloc(sizeof(struct reg_node));$$->ersh = 1;
				//printf("%d lineno: %d\n",$$->ersh, __LINE__);
				$$->name = strdup($1->name);
				$$->id_rec = $1;
				$$->int_flag = 0;
				$$->left = NULL;
				$$->right = NULL;
				// printf("var got\n");
				//$1->addr;
				}
;
/*Grammar ends*/
%%  
// void parse(struct StmtsNode* final){
// 	//printf("sss");
// 	if(final->right==NULL){
// 		expparse(final->left);
		
// 	}
// 	else{
// 		expparse(final->left);
// 		parse(final->right);
// 	}
// }	
void expparse(struct StmtNode* ptr){
	//	printf("kop %d\n",ptr->down->ersh);
	ptr->down->base = 1;
	tparse(ptr->down);
	printf("%s\n", ptr->down->code);

}

void rparse(struct reg_node* ptr){
	if (ptr->left->ersh <= ptr->right->ersh){
		ptr->right->base = 1;
		tparse(ptr->right);

		// ptr->code = ptr->right->code; // correct krna hai
		// ptr->code += st (4*ptr->ersh)($t9) tR

		sprintf(ptr->code, "%s \nst %d($t9) t%d\n", ptr->right->code,
													(4*(ptr->ersh)),
													R);

		if (ptr->left->ersh >= R) {
			ptr->left->base = 1;
			tparse(ptr->left);
		}
		else { //small hai little chile
			ptr->left->base = R - ptr->left->ersh+1;
			// printf("%d\n", ptr->base);
			tparse(ptr->left);
		}

		// ptr->code += ptr->left->code;
		// ptr->code += ld r(R-1) (4*(ptr->ersh - 1))($t9)

		sprintf(ptr->code, "%s \n%s \nld t%d %d($t9)\n", ptr->code,
													ptr->left->code,
													(R-1),
													(4*(ptr->ersh)));

		// ptr->code += ptr->op r(R) r(R) r(R-1)

		sprintf(ptr->code, "%s \n%s t%d t%d t%d\n", ptr->code,
														 ptr->op,
														 R,
														 R,
														 R-1);

	}
	else { // left child is strictly larger than right
		ptr->left->base = 1;
		tparse(ptr->left);

		// ptr->code = ptr->left->code; // correct krna hai
		// ptr->code += st (4*ptr->ersh)($t9) tR

		sprintf(ptr->code, "%s \nst %d($t9) t%d\n", ptr->left->code,
													(4*ptr->ersh),
													R);

		if (ptr->right->ersh >= R) {
			ptr->right->base = 1;
			tparse(ptr->right);
		}
		else { //small hai little chile
			ptr->right->base = R - ptr->right->ersh+1;
			tparse(ptr->right);
		}
		// ptr->code += ptr->right->code;
		// ptr->code += ld r(R-1) (4*(ptr->ersh - 1))($t9)
		sprintf(ptr->code, "%s \n%s ld t%d %d($t9)\n", ptr->code,
													ptr->left->code,
													(R-1),
													(4*(ptr->ersh)));

		// ptr->code += ptr->op r(R) r(R-1) r(R)

		sprintf(ptr->code, "%s \n%s t%d t%d t%d\n", ptr->code,
														 ptr->op,
														 R,
														 R-1,
														 R);
	}
}

void tparse(struct reg_node* ptr){
	if(ptr->ersh<=R){ // normal algo
		if(ptr->right!=NULL){ // If it is not a leaf node
			if(ptr->right->ersh == ptr->left->ersh){
				ptr->right->base = ptr->base + 1;
				tparse(ptr->right);
				ptr->left->base = ptr->base;
				tparse(ptr->left);
				
				sprintf(ptr->code, "%s \n%s \n%s t%d t%d t%d\n", ptr->left->code,
																	   ptr->right->code,
																	   ptr->op,
																	   (ptr->ersh + ptr->base-1),
																	   (ptr->ersh + ptr->base-2),
																	   (ptr->ersh + ptr->base-1));
				//sprintf(ptr->code, "\n%s \n%s \n", ptr->left->code, ptr->right->code);
				
			} 
			else if(ptr->right->ersh > ptr->left->ersh){
					ptr->right->base = ptr->base;
					tparse(ptr->right);
					ptr->left->base = ptr->base;
					tparse(ptr->left);
					sprintf(ptr->code, "%s \n%s \n%s t%d t%d t%d\n", ptr->right->code,
																	   	   ptr->left->code,
																	   	   ptr->op,
																	   	   (ptr->ersh + ptr->base-1), 
																	   	   (ptr->left->ersh + ptr->base-1),
																	   	   (ptr->ersh + ptr->base-1)); 
					//printf("%d: cd_strt %s\n cd_end", __LINE__, ptr->code); 
				}
			else{ //ptr->right->ersh < ptr->left->ersh
				ptr->left->base = ptr->base;
				tparse(ptr->left);
				ptr->right->base = ptr->base;
				tparse(ptr->right);
				sprintf(ptr->code, "%s \n%s \n%s t%d t%d t%d\n", ptr->left->code,
																	   ptr->right->code,
																	   ptr->op,
																	   (ptr->ersh + ptr->base-1),
																	   (ptr->right->ersh + ptr->base-1),
																	   (ptr->ersh + ptr->base-1));
				//printf("%d: cd_strt %s\n cd_end", __LINE__, ptr->code);
			}
			
		}
		else{//It is a leaf node
			assert((ptr->right == ptr->left) && ptr->right == NULL);
			if(ptr->int_flag==0){
				sprintf(ptr->code, "lw $t%d %s($t8)\n", ptr->base, ptr->id_rec->addr);
			}
			else{
				sprintf(ptr->code, "li t%d %d\n", ptr->base, ptr->value);
			}
		}
	}
	else rparse(ptr);
}

void stmt_parser(struct StmtsNode* final) {
	if (final->right == NULL) { 
		expparse(final->left);
	}
	else { // child is not NULL
		expparse(final->left);
		if (final->left->down->ersh <= R) {
			printf("\nst %s($t8) t%d\n", final->left->left_id_details->addr,
									 final->left->down->ersh);
		}
		else {
			printf("\nst %s($t8) t%d\n", final->left->left_id_details->addr,
									  R);
		}
		stmt_parser(final->right);
	}
}


int main (int argc, char* argv [])
{
  //  fp=fopen("asmb.asm","w");
   //fprintf(fp,".data\n\n.text\nli $t8,268500992\n");
	R = atoi(argv[1]);
    yyparse ();
	//printf("yyparesed ke bhr\n");
	stmt_parser(final);
		//printf("done\n");
   // fprintf(fp,"\nli $v0,1\nmove $a0,$t0\nsyscall\n");
   // fclose(fp);
}

void yyerror (char *s)  /* Called by yyparse on error */
{
  printf ("%s\n", s);
}

