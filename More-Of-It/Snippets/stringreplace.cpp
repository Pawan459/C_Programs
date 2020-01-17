#include<stdio.h>
#include<string.h>
 
int main()
{
    char PS[105];
    char Final[105];
    char ch;
     
    gets(PS);   
     
     
    scanf("%c",&ch);
     
     
    scanf("%s",Final);
     
    for(int i=0;i<strlen(PS);i++)
        {
            if(PS[i]==ch)
                {
                    for(int i=0;i<strlen(Final);i++)
                        printf("%c",Final[i]);
                }
            else
                printf("%c",PS[i]);
        }
     
     
    return 0;
}
