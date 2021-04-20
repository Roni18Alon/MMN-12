#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>



/*declaration of functions*/
int readText(int dataStructureType , char* p);
void printText(int dataStructureType , char* p);



int main()
{

printf("\nPlease choose the data structure. Enter 1 For linked list, and 2 for buffer\n\n");

int type;
scanf("%d", &type);

/*buffer*/

if(type==2)
{
char *p;
p=(char*)calloc(0,sizeof(char));
int error=readText(type,p);
printText(type,p);
	if ( error==1)
		{
		printf("\nmemory allocation failed\n\n");
		}

}
else if(type==1)
	{
		printf("\nRoni you need to do the second option- inked list\n\n");
	}


return 0;
}


int readText(int dataStructureType , char* p)
{
int error =0;	
if (dataStructureType==2)				/*buffer*/
{
	
	int counter=0;		
	char c= getchar();
	char *q;
		while(c!=EOF)
		{
	
		if (c!='\n'){		
			p[counter]=c;
			counter++;

			q=(char*)realloc(p,counter);
			if (!q) {
				error =1;
				exit(0);
			}
			p=q;
			c=getchar(); /*get the next char*/
		}
		else c=getchar();
		}
	}
return error;
}

void printText(int dataStructureType , char* p)
{
	int counter;
	if (dataStructureType==2)/*buffer*/
		{
		for (counter=0 ; ((char*)p)[counter] != '\0' ; counter++) 
		{
            if (counter%60 == 0 && counter!=0)
            {
                putchar('\n'); /*each row have 60 char*/
                
             } 											
       	 putchar(((char*)p)[counter]); /*print the char*/
        }
        putchar('\n');
	
	}
}





