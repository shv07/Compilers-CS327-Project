#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
Parses the Parse Table. Returns the value at row = "row_index" and column="column_index" in the parse table which is passed as .csv file with file name= filname
*/

char* TableParser(char *filname, int row_index, char column_index , int columns)
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
			
			for (int j = tmp1+1; j<strlen(tmp); j++)
			{
				if(tmp[tmp1+1]==',')
				{
					result="NULL";
					break;
				}
				if(tmp[j]==',')
					break;
				result[j-tmp1-1]=tmp[j];
			}
			free(tmp);					
			break;					
		}
	
		count_row++;		
	}
	return result;
}

void main()
{
	char *a=TableParser("assignment2sampleparsetable2.csv", 0, 'b',5);
	printf("\n%s\n", a);
}
