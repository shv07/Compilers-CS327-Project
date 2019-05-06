/*
 * Collaborators:
 * Deepak
 */

struct symrec
{
  char *name; /* name of symbol */
  int addr; /* location of top of variable in memory */
  char *type;
  char *code;
  struct symrec *next; /* link field */
};
typedef struct symrec symrec;

struct nody
{
  char *code;
  char *addr_code;
  char *find_value;
  int isAssign;
  symrec *id_rec;
};

/* The symbol table: a chain of `struct symrec'.     */
extern struct symrec *sym_table_head;

symrec *getsym (char *sym_name);
void putsym (struct symrec * ptr, int size);


/* For storing ershov numbers and code for nodes
 * that are constructed for expressions for code generation
 * **/
// struct reg_node{
// 	char code[1000]; // for storing the generated code
// 	int ersh;
// 	int base;
// 	struct reg_node *left; // child nodes
// 	struct reg_node *right;	// child nodes
// 	int int_flag; // flag weather the node corresponds to num
// 	int value; // value of int
// 	char* name; // variable name
// 	char* op; // operator
// 	struct symrec *id_rec; // symbol table record pointer
	
// };
// struct StmtsNode{
// 	// Used to store a collection of statements
// 	struct StmtNode *left; // a single statement node ptr
// 	struct  StmtsNode *right; // a collection of stmt node ptr
//   // int iswhile;
//   char* code;
//   // int isif;
// };
// struct StmtNode{
// 	struct StmtsNode *down; // stores the ptr to reg_node that has code
//   int iswhile;
//   char* code;
//   int isif;
// };

struct condy
{
  char* code;
};
