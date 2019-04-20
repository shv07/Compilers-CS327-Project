/* Data type for links in the chain of symbols.      */
struct symrec
{
  char *name;  /* name of symbol                     */
  char addr[100];           /* value of a VAR          */
  struct symrec *next;    /* link field              */
};
struct reg_node{
	char* code;
	int ersh;
	int base;
}
struct StmtsNode{
	char bodycode[1000];
	struct StmtNode *left;
	struct  StmtsNode *right;	
}
struct StmtNode{
	char bodycode[1000];
	struct  reg_node *down;
}
typedef struct symrec symrec;

/* The symbol table: a chain of `struct symrec'.     */
extern symrec *sym_table;

symrec *putsym ();
symrec *getsym ();

