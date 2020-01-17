#include<stdio.h>
void rev(char a);
int main()
{
  char a;
  scanf("%c",&a);
  while(a!='EOF')
  {
    rev(a);
    scanf("%c",&a);
  }
}
void rev(char a)
{
  printf("%c",a);
}
