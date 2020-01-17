#include<stdio.h>
#include<conio.h>
void strreplace(char *,char,char);
int main()
{
    char s[10],chr,repl_chr;
    printf("\nEnter a string: ");
    scanf("%s", &s);
    printf("\nEnter character to be replaced: ");
    scanf("%s", &chr);
    printf("\nEnter replacement character: ");
    scanf("%s", &repl_chr);
    printf("\nModified string after replacement is: ");
    strreplace(s,chr,repl_chr);
   getch();
   return 0;  
}
void strreplace(char s[], char chr, char repl_chr)
{
     int i=0;
     while(s[i]!='\0')
     {
           if(s[i]==chr)
           {
               s[i]=repl_chr;
           }  
           i++; 
     }
          printf("%s",s);
}
