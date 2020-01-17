#include<stdio.h>
int main()
{
    char c;
   	int count=0,check=0;
    c = getchar();
    while ( c != EOF ) {
       c = getchar();
       if(c == '\n')
       {
       	break;
	   }
    	if(c==' '|| c=='\t'|| c==';'||c==','||c=='.')
    	{
    		check=check+1;
		}
		else{
			check=0;}
    	if(check<2&&(c==' '|| c=='\t'|| c==';'||c==','||c=='.')){
    		count=count+1;}
    }
    printf("%d",count);
    return 0;
}
