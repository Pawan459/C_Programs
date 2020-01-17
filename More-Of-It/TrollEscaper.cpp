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
	int	j=0,n, check, last;
    scanf("%d", &n);
    int troll[100];
    for(int i=0;i<n;i++)
    	troll[i]=1;
    last = query(troll, n);
    if(last==0)
    {
    	printf("A");
    	for(int i=0;i<n;i++)
    		printf(" 0");
    	return 0;
	}
    while(last!=n)
    {
    	troll[j]=0;
    	check=query(troll,n);
    	if(check>last)
    		troll[j]=0;
    	else
    		troll[j]=1;
    	last=check;
    	j++;
	}
    printf("A");
    for (int i = 0; i < n; i++)printf(" %d", troll[i]);
    fflush(stdout);
    printf("\n");
}
