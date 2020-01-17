#include <stdio.h>

int query(int *troll, int n) {
    int i, check;
    printf("Q");
    for (i = 0; i < n; i++)printf(" %d", troll[i]);
    printf("\n");
    fflush(stdout);
    scanf("%d", &check);
    return check;
}

int main() {
    int t,n, j=0, check, last;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
	{
    scanf("%d", &n);
    int troll[100] = {};
    last = query(troll, n);
    while(last!=n) {
        troll[j] = 1;
        check = query(troll, n);
        if (check > last) {
            troll[j] = 1;
        }
        else {
            troll[j] = 0;
        }
        last = check;
        j++;
    }
    printf("A");
    for (j = 0; j < n; j++)printf(" %d", troll[j]);
    printf("\n");
    fflush(stdout);
	}
}
