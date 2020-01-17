#include <stdio.h>
#include <stdint.h>
#include <strings.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int a[3000010][2];
uint8_t b[2000010];
int an, max;
void add(int p, int l)
{
    int i;
    if ((b[p/8] & (uint8_t)(1 << p%8)) == 0) {
     //   for (i = 0; i < l; i++)
      //      printf(" ");
     //   printf("%d\n", p);
        if (an > 3000010)
            assert(0);
        if (p/8 > 2000010)
            assert(0);
        a[an][0] = p;
        a[an++][1] = l;
        b[p/8] |= 1<<(p%8);
        if (p/8 > max)
            max = p/8;
    }
}
int main() {
    int q, n, t, i, j;
    scanf ("%d", &q);
    
    while (q--) {
        an= 0;
       
        scanf("%d", &n);
        if (n == 0) {
            printf("0\n");
            continue;
        }
        add(n, 1);
       // add(0);
        j = 0;
       // t = 0;
        while (j != an) {
           /* if (a[j] == 0) {
                t++;
                j++;
                continue;
            }
            */
            if (a[j][0] == 1)
                goto aaa;
            add(a[j][0]-1, a[j][1] + 1);
            int oo = sqrt(a[j][0]);
        for (i = 2; i <= oo; i++) {
            
            if (a[j][0]%i == 0) {
                if (i > a[j][0]/i) {
                    add(i, a[j][1]+1);
                } else {
                    add(a[j][0]/i, a[j][1]+1);
                }
            }
        }
           // add(0);
            j++;

        }
aaa:
        printf("%d\n", a[j][1]);
         bzero(b, max + 3);
            max = -1;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
