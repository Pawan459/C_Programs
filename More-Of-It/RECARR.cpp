#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define N           4
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
#include <unistd.h> // not included in bits/stdc++.h
#define int long
unsigned int mix(unsigned int a, unsigned int b, unsigned int c)
#undef int
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}
int query(int l,int r){
    cout<<1<<" "<<l<<" "<<r<<endl;
    cin>>l;
    return l;
}
int a[N+5];
void solve(){
    unsigned long seed = mix(clock(), time(NULL), getpid());
    srand(seed);
    a[N]=query(N,N);
    rep(i,0,N/3){
        int w=query(3*i+1,3*i+3);
        if(w==0) a[3*i+1]=a[3*i+2]=a[3*i+3]=0;
        else if(w==3) a[3*i+1]=a[3*i+2]=a[3*i+3]=1;
        else{
            int r=rand()%3;
            int pos=3*i+r+1;
            a[pos]=query(pos,pos);
            if(w-a[pos]==0){
                rep(j,3*i+1,3*i+4){
                    if(j==pos) continue;
                    a[j]=0;
                }
            }
            else if(w-a[pos]==2){
                rep(j,3*i+1,3*i+4){
                    if(j==pos) continue;
                    a[j]=1;
                }
            }
            else{
                a[3*i+(r+2)%3+1]=query(3*i+(r+2)%3+1,3*i+(r+2)%3+1);
                a[3*i+(r+4)%3+1]=w-a[3*i+1]-a[3*i+2]-a[3*i+3];
            }
        }        
    }
    cout<<2<<" ";
    rep(i,1,N+1) cout<<a[i]<<" ";
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
