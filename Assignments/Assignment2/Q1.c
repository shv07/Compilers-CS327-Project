#include <stdio.h>
#include <stdlib.h>
#include<string.h>


char* TableParser(char *filname, int row_index, char column_index, int columns )
{
	FILE* stream = fopen(filname, "r");
	char line[columns*10];
	int count_row=-1;
	int c_index=0;
	char *result=malloc(sizeof(char)*50);
	while(fgets(line,columns*10, stream))
	{
		char *tmp=strdup(line);
	
		if(count_row==-1)   //for first row
		{			
			for(int i=0;i<strlen(tmp);i++)
			{
				if(tmp[i]==',')
				{
					c_index++;
				}
				if(tmp[i]==column_index)
					break;
			}
		}



		
		if(count_row==row_index)   //for the required row
		{
			int c_index1=0; int tmp1;
			for(int i=0;i<strlen(tmp);i++)
			{				
				if(tmp[i]==',')
				{
					c_index1++;
				}
				if(c_index1==c_index)
				{
					tmp1=i;
					break;
				}
			}
			int j=0;
			for (j = tmp1+1; j<strlen(tmp); j++)
			{
				if(tmp[tmp1+1]==',')
				{
					strcpy(result,"Null\0");
					break;
				}
				if(tmp[j]==',')
					break;
				result[j-tmp1-1]=tmp[j];
					
			}
			if(strcmp(result,"Null\0"))
				result[j-tmp1-1]='\0';
			free(tmp);					
			break;					
		}
	
		count_row++;		
	}
	//strcat(result, "\0");
	return result;
}

int num_rows(FILE* fp){
	// Check if file exists 
    if (fp == NULL)
    { 
        printf("Could not open file"); 
        return 0; 
    } 
	char c;
	int count = 0;
    // Extract characters from file and store in character c 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
        if (c == '\n') // Increment count if this character is newline 
            count = count + 1; 
       
    return count;
}
int stack[20];
int top = 0;

int main(void)
{
    FILE * fp;
    char * line = NULL;
    fp = fopen("assignment2-sample-grammar1.txt", "r");
    int rows;
    rows = num_rows(fp);
    printf("Number of productions %d\n",rows-1);
    
    fclose(fp);
    size_t len = 0;
    ssize_t read;
    fp = fopen("assignment2-sample-grammar1.txt", "r");
    if (fp == NULL){
        exit(EXIT_FAILURE);}
    int ter;
    int non_ter;
	int i = 0;
	char productions[rows-1][10];
    
    while ((read = getline(&line, &len, fp)) != -1) {
    	//printf("Retrieved line of length %zu:\n", read);
        if(i==0){
        	int j = 0;
        	char temp[5];
        	while(line[j]!=' '){
        		temp[j] = (char)line[j];
        		j = j + 1;
        	}
        	temp[j+1] = '\0';
        	non_ter = atoi(temp);
        	
        	int k = 0;
        	j = j + 1;
        	while(line[j]!='\0'){
        		temp[k] = (char)line[j];
        		j = j + 1;
        		k = k + 1;
        	}
        	temp[k+1] = '\0';
        	ter = atoi(temp);
        	printf("non termminals = %d, terminals = %d\n",non_ter,ter);
        	i = i + 1;
        }
        else{
        	int j = 0;
			//productions[i] = strdup(line);
        	//strcpy(productions[i],line);
        	for(j=0;j<strlen(line);j++){
        		int k;
        		k = line[j];
        		if((k>=65&&k<=65+non_ter)||(k>=97&&k<=97+ter)||(k==58)){
        			productions[i][j] = k;
        		}
        		else{
        			productions[i][j] = '\0';
        			break;
        		}
        	}
       // 	printf("%s,%s\n",productions[i],line);
        	i = i + 1;
        }
    }
    fclose(fp);
    
  //  printf("%s\n",productions[6]);
    //printf("%ld\n",strlen(productions[6]));
    
    char inp[100];// = "a$"; 
    printf("Enter Query String : ");
    scanf("%s",inp);
    strcat(inp,"$"); 
    printf("input is : %ld\n", strlen(inp)); 
    int n;
    i = 0;
    stack[0] = 0;
    
    
    
    
    
    
    
    
    
    
    
    n = strlen(inp);
    while(i<n){
    	printf("*******************\n");
    	printf("%d\n",stack[top]);
    	printf("%c\n",inp[i]);
    	printf("%d\n",top);
    	char *a=TableParser("assignment2-sample-parsetable1.csv", stack[top], inp[i],5);
    	
    	printf("%s\n",a);
    	
		int res = strcmp(a, "acc\0");
		if(res==0){
			printf("This is valid\n");
			break;
		}
		res = strcmp(a, "Null\0");
		
		if(res==0){
			printf("INVALID\n");
			break;
		}
		if(a[0]=='r'){
			
			printf("Reduce\n");
			a = a + 1*sizeof(char);
			int produc = atoi(a);
			int temp1 = strlen(productions[produc])-2;
			//printf("temp1 = %d\n",temp1);
			top = top - temp1;
			char *b=TableParser("assignment2-sample-parsetable1.csv", stack[top], productions[produc][0],5);
			top = top + 1;
			b = b + 1*sizeof(char);
			stack[top] = atoi(b);
			//free(a);
			//printf("Shivji\n");
		}	
		if(a[0]=='s'){
			//printf("%ld\n",strlen(a));
			a = a + 1*sizeof(char);
			printf("%s\n",a);
			printf("Shift\n");
			top = top + 1;
			stack[top] = atoi(a);
			i = i + 1;
			
		}	
		
		//printf("\n%s\n", a);
    
    
    
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	return 0;
}



