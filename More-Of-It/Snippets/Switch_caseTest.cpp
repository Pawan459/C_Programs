#include<stdio.h>

int main(){
	int x = 3;
	switch(x){
		case 1:{x += x;
		printf("first case: %d\n",x);
		}
		case 4:{x += x;
		printf("Second case: %d\n",x);}
		case 5:{x += x;
		printf("Third Case: %d\n",x);}
		
	}
	printf("%d",x);
}
