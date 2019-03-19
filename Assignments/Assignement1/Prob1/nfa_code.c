#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct node
{
	int id;
	struct node *up;
	struct node *down;
	char smb1;
	char smb2;
}node;

struct node array[100];

typedef struct split{
	char* first;
	char* second;
	char sign;
}split;

struct split foo(char inp[], int n){
	//int n = strlen(inp);
	struct split a;
	char out1[n];
	char out2[n];
	char sign;
	int i;
	if(inp[n-1]=='*'){
		
		for(i = 0; i<n-1; i++){
			out1[i] = inp[i];
		}
		out1[n-1] = '\0';
		sign = '*';	
		//printf("out1 %s\n",out1);
		a.first = strdup(out1);
		a.sign = sign;
		a.second = '\0';
		return a;
	}
	else{
		int c = 0;
		int i;
		
		for(i = 0; i<n; i++){
			if(inp[i]=='('){
				c = c + 1;
			}
			if(inp[i]==')'){
				c = c - 1;}
			if(c==1 &&(inp[i]=='.' ||inp[i]=='+')){
				out1[i-1] = '\0';
				break;
			}
			if(i!=0){
				out1[i-1] = inp[i];	
		//		printf("%s\n",out1);//,inp[i]);	
			}
		}
		//i = i +1;
		char sign = inp[i];	
		a.first = strdup(out1);
		a.sign = sign;
		i = i + 1;
		int j = i;
		while(j<n-1){
			out2[j-i] = inp[j];
			++j;
		}
		out2[j-i] = '\0';
	//	printf("aaaaaaaaaa %s %s\n",a.first, out1);
		a.second = strdup(out2);
		return a;
	}
	
}




void printit(int count, char graph[count][count+1]){
	for(int i=0;i<count;++i)
	{
		char arr[count+1];
		//arr[0] = i+'0';//converts integer to character
		for(int j = 0; j<count;++j)
		{	
			arr[j] = graph[i][j];
		}
		arr[count] = '\0';
		printf("%s\n", arr);
	}
}





int nfa(char inp[], struct node* q, struct  node* f, int count){
	printf("%s\n", inp);
	// printf("Input - %s\n", inp);
	if (strlen(inp) == 3){ // if the input string contains only 1 alphabet( it would be stored in parenthisis)
		// printf("%s\n",inp);
		// we would directly join the two nodes
		q->up = f;
		q->smb1 = inp[1];
	//	printf("smb1 %c\n", q->smb1);
	}

	else{
		char A[100];
		char B[100];
		char op;

		struct split s;
		int n = strlen(inp);
	
		s = foo(inp,n);
		
		printf("first %s, %d\n", s.first, strlen(s.first));
		printf("sign  %c\n", s.sign);
		
		printf("second %s\n", s.second);
		if (s.second != NULL){strcpy(B, s.second);}
		else{B[0] = '\0';}
		if (s.first!= NULL){strcpy(A, s.first);}
		else{A[0] = '\0';}

		op = s.sign;

	 	if (op == '+'){
			struct node* n1 = &array[count];
			++count;
			struct node* n2 = &array[count];
			++count;
			struct node* n3 = &array[count];
			++count;
			struct node* n4 = &array[count];
			++count;

			count = nfa(A,n1, n2,count);
			count = nfa(B,n3, n4,count);
			q->up = n1;
			q->smb1 = 'e';
			q->down = n3;
			q->smb2 = 'e';
			n2->down = f;
			n2->smb2 = 'e';
			n4->up = f;
			n4->smb1 = 'e';
		}


		else if(op == '.'){
			struct node* n = &array[count];
			++count;
			count = nfa(A, q, n,count);
			count = nfa(B, n, f,count);
		}
		else if(op == '*'){
			
			struct node* n1 = &array[count];
			++count;
			struct node* n2 = &array[count];
			++count;
			q->up = n1;
			q->smb1 = 'e';
			q->smb2 = 'e';
			q->down = f;
			n2->up = n1;
			n2->smb1 = 'e';
			n2->down = f;
			n2->smb2 = 'e';
			// printf("**  %s\n", A);
			count = nfa(A, n1, n2,count);
		}
	}
	return count;
}














char* epselon_closure(int s, int count,char nfa[count][count+1] )
{
char *epselon=malloc (sizeof (char) *count);       //to store and return the epselon closure states in form of array of characters

	epselon[0]=s+'0';                //ASCII character corresponding to 48+s i.e. for s=0,1,2,3,....; the values are 0,1,2,..,9,:,;,<,=........
	int stack[count+count];          //stack to store the states from where the epselon transition has to be found out
	stack[0]=s;
	int pointer=1;
	for(int i=0;i<count;i++)        //initially push all the states with epselon transition from "s" at 1 transition in the stack as well as in the "epselon" array
	{
		if(nfa[s][i]=='e')
		{
			epselon[pointer]=i+'0';
			stack[pointer]=i;
			pointer++;		
		}
		
	}
	int top=pointer-1;
	while(top>=0)                   // pop a state from the stack one bby one and find its the states from there at single epselon transition. if that state is new add it in epselon and also push
	{				//it in stack
	
		int t=stack[top];
		top--;
		for(int i=0;i<count;i++)
		{
			if(nfa[t][i]=='e')
			{	
				int flag=0; 
				for(int tmp=0;tmp<pointer;tmp++)
				{
					if(epselon[tmp]==i+'0')
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					top++;
					epselon[pointer]=i+'0';
					stack[top]=i;
					pointer++;
				}
			}
		}
	}
	return epselon;
}
	

int already_exist(char *final_states,char state,int l)     //returns 1 if a char, "state " already exists in string, "final_states" else returns 0
{
    int result=0;
    for(int i=0;i<l;i++)
    {
        if(final_states[i]==state)
        {
            result=1;
            break;
        }
    }
    return result;
}


char  *move(int crnt_state, char crnt_alph, int count, char NFA[count][count+1])    //returns the set of states that can be reached by the NFA state, "crnt_state" on seeing alphabet, "srnt_alph" 
{										    //includes the states reachable at one transition and the epselon closure of the destination
    int tmp;int flag=0;char *next_states=malloc(sizeof(char)*count*2);		    //returns "N" if no one step transition possible from crnt_state on seeing crnt_alph
    for(int i =0;i<count;i++)
    {   
        if(NFA[crnt_state][i]==crnt_alph)
        {
            tmp=i;
            flag=1;
            break;
        }
    }
    
    
    if(flag==0)
    {
  
        return "N";
        
    }
        
    else
    {
        strcpy(next_states,epselon_closure(tmp,count,NFA));
        return next_states;
    }
        
}

char* str_union(char *a, char *b, int l1, int l2)    				//returns the union of strings a and b
{
    int ptr=l1;
    char *c=malloc(sizeof(char)*(l1+l2*2));
    strcpy(c,a);
    for(int i=0; i<l2;i++)
    {
        int flag=0;
        for (int j=0;j<l1;j++)
        {
            if (b[i]==a[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            {c[ptr]=b[i];ptr++;}
        
    }
    return c;
}

int common_states(char *F, char *S, int f, int s)				//returns 1 if there is at least 1 common character b/w F, S else 0
{
    int flag=0;
    for (int i=0;i<f;i++)
    {
        for(int j=0;j<s;j++)
        {
            if(F[i]==S[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==1) 
            break;
    }
    return flag;
}

//NFA Simulator using the algorithm 3.22

int nfa_simulate(char *s,int count, char nfa[count][count+1])    //returns 1 if nfa accepsts s, else returns 0
{
    char *F=epselon_closure(1,count,nfa);  int result=1;        //result is 0 if the nfa has no transition possible on seeing a character from s when all the characters from s have not been seen by it
    char S[count+count];strcpy(S,epselon_closure(0,count,nfa));	//F - final states of the nfa i.e. the epselon closure of state "1" (as defined by us, "1" is always a final state)
    								//S- similar to the algorithm; stores the epselon-closure(move(crnt_states,crnt_alph )
    int crnt_state=0;
    int crnt_alph_ptr=0;					//crnt_alph_ptr - pointer to the current character of "s" being seen by nfa
    
    while(s[crnt_alph_ptr]!='\n' && crnt_alph_ptr<strlen(s))
    {
        int ptr=0;char tmp[count*2]; strcpy(tmp,"");
        //calculating move(S,c)
        
        for(int i=0;i<strlen(S);i++)
        {
            char *tmp1=move(S[i]-'0',s[crnt_alph_ptr],count,nfa);
            //printf("\n%s",tmp1);
            if(tmp1!="N")
                strcpy(tmp,str_union(tmp,tmp1,strlen(tmp),strlen(tmp1)));
                
        }
        if(tmp!="")
        {
            char tmp_S[count*2]; strcpy(tmp_S,"");
            for(int i=0;i<strlen(tmp);i++)
            {
                char *tmp1=epselon_closure(tmp[i]-'0',count,nfa);
                strcpy(tmp_S,str_union(tmp_S,tmp1,strlen(tmp_S),strlen(tmp1)));
            }
            crnt_alph_ptr++;
            strcpy(S,tmp_S);   //S=epselon-closure(move(S,c))
        }
        /*else
        {
            result=0; break;
        }*/
    }
    //if(result==0)
       //return 0;
    if(common_states(F,S,strlen(F),strlen(S))==1)
        return 1;
    else
        return 0;
        
}






int main()
{	
	int count = 0;
	for(int i=0;i<100;++i)
	{
		struct node n;
		n.id = i;
		n.smb1 = '\0';
		n.smb2  = '\0';
		n.up = NULL;
		n.down = NULL;
		array[i] = n;
	}

///////////////////////////////////////////////////////////////////////////EDIT HERE TO CHANGE THE INPUTS or USE THE TERMINAL. THESE ARE SAMPLE REGX/////////////////////////////////////////
	char in[100] = "((((a)+(b))+((c)+(d))).(f))"; // taking input
	//char in[100] = "((a)+(b))"; // taking input
	//char in[100] = "((a)+(b))*"; // taking input
	
	//char in[100] = "(a)*"; // taking input
	
	//char in[100] = "(((a)+(b)).(c))*"; // taking input
	//char in[100] = "(((a).(b)).(a))";
	
	//char in[100] = "((a).(b))";
	//char in[100] = "((a)*.(b))";
	
	char state_to_calculate_epselon_closure='0';
	char string_to_simulate_nfa[100]="bfd";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	printf("\nEnter the regular expression: "); scanf("%s",in);


	struct node* q = &array[count];
	++count;
	struct node* f = &array[count];
	++count; 
	
	count = nfa(in, q, f,count);
	
	char graph[count][count+1];
	for(int i=0;i<count;++i)
	{
		for (int j=0; j<count; ++j)
		{
			graph[i][j] = '0';
		}
		graph[i][count] = '\0';
	}

	for(int i=0;i<count;++i)
	{
		struct node* temp = &array[i];
		if(temp->up != NULL)
		{
			graph[temp->id][temp->up->id] = temp->smb1;
		}
		if(temp->down != NULL)
		{
			graph[temp->id][temp->down->id] = temp->smb2;
		}

	}
	
	
	printf("number of nodes = %d\n",count);
	printit(count, graph);
	
	printf("\n\n");
	
	printf("\nEnter the state to calculate epselon closure: "); scanf(" %c",&state_to_calculate_epselon_closure);
	printf("\nEnter the string to simulate NFA: "); scanf("%s",string_to_simulate_nfa);

	printf("Epselon Closure of %c: ", state_to_calculate_epselon_closure);
	char *epselon=epselon_closure(state_to_calculate_epselon_closure-'0',count,graph);
	printf("\n%s",epselon);
	free(epselon);
	
	printf("\n");
	printf("\nSimulation of %s: %d\n",string_to_simulate_nfa,nfa_simulate(string_to_simulate_nfa,count,graph));	
    return 0;
}
