 #include <stdio.h>
 void revstr() {
 int ch = getchar();
 if (ch == '\n') return;
 revstr();
 putchar(ch);
}
int main() {
 revstr();
 return 0;
}
