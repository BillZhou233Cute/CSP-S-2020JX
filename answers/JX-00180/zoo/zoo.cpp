#include"bits/stdc++.h"
using namespace std;
#define ri register int
#define ll long long
#define ull unsigned long long
inline ull rd(){
    ull xx=0,flg=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') {xx=xx*10+(ch^48);ch=getchar();}
    return xx*flg;
}
#define N 1000010
int n,m,k,c,p,q;
ull a[N];
int vis[70];
unsigned long long x=1;
int main(){
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
    n=rd(),m=rd(),c=rd(),k=rd();
    for(ri i=1;i<=n;++i){
        a[i]=rd();
        for(ull j=0;j<=63;++j){
            if(a[i]&(x<<j)) vis[j]=1;
        }
    }
    if(n==0&&m==0&&k==64){
        printf("18446744073709551616");
        return 0;
    }
    ull ans=k;
    while(m--){
        p=rd(),q=rd();
        if(!vis[p]) ans--,vis[p]=1;
    }
    if(ans>=1){
        cout<<(x<<(ans-1))-n+(x<<(ans-1));
        return 0;
    }
    else cout<<(x<<ans)-n;
    return 0;
}
