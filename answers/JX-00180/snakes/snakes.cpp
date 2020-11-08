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
#define N 1000010
int t,n,a[N],k,x,y;
int main(){
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    t=rd();
    n=rd();for(ri i=1;i<=n;++i) a[i]=rd();
    if(n==3){
        if(a[3]>=a[2]+a[1]) printf("1\n"); else printf("3\n");
    }
    t--;
    while(t--){
        k=rd();
        for(ri i=1;i<=k;++i) x=rd(),y=rd(),a[x]=y;
        if(n==3){if(a[3]>=a[2]+a[1]) printf("1\n");else printf("3\n");}
    }
    return 0;
}
