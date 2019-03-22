#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
    
char** find_productions(FILE* fp, int rows){
	
	char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char** productions = malloc((rows-1)*sizeof(char*));//[rows-1];
    
    for(int i=0; i<rows-1; i++){
    	productions[i] = malloc(10*sizeof(char));
    }
    
    if (fp == NULL){
        exit(EXIT_FAILURE);}
    int ter;
    int non_ter;
	int i = 0;
	
    while ((read = getline(&line, &len, fp)) != -1) {
        if(i==0){
        printf("sdfsdssssssssssss");
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
        	printf("nt %d t %d\n",non_ter,ter);
        	i = i + 1;
        }
        else{
        printf("shiv");
        	int j = 0;
        	//strcpy(productions[i],line);
        	productions[i] = line;
        	printf("%s",productions[i]);
        	i = i + 1;
        }
    }
    if (line)
        free(line);
	return productions;
}
int main(void)
{
    FILE * fp;
    char * line = NULL;
    //size_t len = 0;
    //ssize_t read;
    fp = fopen("assignment2-sample-grammar1.txt", "r");
    int rows;
    rows = num_rows(fp);
//    printf("sdfsdfdsfs");
    printf("Number of productions %d\n",rows-2);
    
//    char productions[rows-1][10];
    char** productions=NULL;
    
    productions = find_productions(fp,rows);
    /*fp = fopen("assignment2-sample-grammar1.txt", "r");
    if (fp == NULL){
        exit(EXIT_FAILURE);}
    int ter;
    int non_ter;
	int i = 0;
	char productions[rows-1][10];
    //char* productions[rows-1];
    
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
        	printf("nt %d t %d\n",non_ter,ter);
        	i = i + 1;
        }
        else{
        	int j = 0;
        	strcpy(productions[i],line);
        	//printf("%s",productions[i]);
        	i = i + 1;
        }
    }
    fclose(fp);
    if (line)
        free(line);*/
            fclose(fp);

    printf("%s",productions[3]);
	printf("sdfsdf");
    free(productions);
    return 0;
}



