#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct stack 
{
    int data[100000];
    int top;
};
struct stack st,s1;

void enq()
{
    int item;
    scanf("%d",&item);
    st.data[++st.top]=item;
}
void deq()
{
    int del;
    while(st.top>=0)
    {
        del = st.data[st.top];
        st.top--;
        s1.top++;
        s1.data[s1.top]=del;
    }
    s1.top--;
    while(s1.top>=0)
    {
        del = s1.data[s1.top];
        s1.top--;
        st.top++;
        st.data[st.top]=del;
     }
}
int main() {

st.top=-1;
s1.top=-1; 
int t,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&c);
        switch(c)
        {
            case 1: enq();
                    break;
            case 2: deq();
                    break;
            case 3: printf("%d\n",st.data[0]);
                    break;
        }
    }
    return 0;
}
