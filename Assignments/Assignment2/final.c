#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct productions{
	struct productions* next;
	char left;
	char right[5];
};
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

int main(){
	struct productions head;
	FILE * fp;
    char * line = NULL;
    fp = fopen("assignment2-sample-grammar1.txt", "r");
    int ter;
    int non_ter;
	int i = 0;
	size_t len = 0;
    ssize_t read;
	struct productions curr;
	while ((read = getline(&line, &len, fp)) != -1) {
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
        	struct productions temp;
        	temp.next = NULL;
        	temp.left = line[0];
        	line = line + 2*sizeof(char);
        	strcpy(temp.right,line);
        	curr.next = &temp;
        	curr = temp;
        	i = i + 1;
        }
    }
    fclose(fp);
    if (line)
        free(line);
            fclose(fp);
	
	return 0;
}
