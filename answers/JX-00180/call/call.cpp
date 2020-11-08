#include"bits/stdc++.h"
using namespace std;
#define ri register int
#define ll long long
inline int rd(){
    int x=0,flg=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') flg=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+(ch^48);ch=getchar();}
    return x*flg;
}
#define N 100010
#define mod 998244353
ll n,m,a[N],f[N],p,d[N],c,t;
vector<int> s[N];
struct node{
    ll op,x,y;
}b[N];
inline void solve_ok3(){
    ll bas=1;
    for(ri i=1;i<=t;++i) f[i]=rd();
    for(ri i=t;i>=1;--i){
        int u=f[i];
        if(b[u].op==1) d[b[u].x]=(d[b[u].x]+b[u].y*bas)%mod;
        else bas=bas*b[u].x%mod;
    }
    for(ri i=1;i<=n;++i){
        a[i]=a[i]*bas%mod;
        a[i]=(a[i]+d[i])%mod;
        printf("%lld ",a[i]);
    }
}
int main(){
    freopen("call.in","r",stdin);
    freopen("call.out","w",stdout);
    n=rd();for(ri i=1;i<=n;++i) a[i]=rd();
    int ok3=1;m=rd();
    for(ri i=1;i<=m;++i){
        b[i].op=rd();
        if(b[i].op==1) b[i].x=rd(),b[i].y=rd();
        else if(b[i].op==2) b[i].x=rd();
        else{
            c=rd();
            for(ri j=1;j<=c;++j) p=rd(),s[i].push_back(p),ok3=0;
        }
    }
    t=rd();
    if(ok3) {solve_ok3();return 0;}
    return 0;
}
