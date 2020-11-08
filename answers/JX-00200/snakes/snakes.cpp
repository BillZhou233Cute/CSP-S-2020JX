#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#define il inline
#define ll long long
#define R register
#define gc getchar
#define int long long
using namespace std;
//------------------------初始函数--------------------------
il int read(){
    R int x=0;R bool f=0;R char ch=gc();
    while(!isdigit(ch)){f|=ch=='-';ch=gc();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}
    return f?-x:x;
}

il int min(int a,int b) {return a<b?a:b;}

il int max(int a,int b) {return a>b?a:b;}
//------------------------初始函数--------------------------

const int MAXN=1e6+10;
int T,n,m,k;
int a[MAXN];
struct w_snake{
    int id,tl;//id->编号，tl->体力
    il bool operator < (const w_snake & oth) const {
        if(tl!=oth.tl) return tl>oth.tl;
        return id>oth.id;
    }
}b[MAXN];
signed main(){
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    T=read();n=read();m=n;
    for(R int i=1;i<=n;++i){
        a[i]=read();
        b[i].id=i;b[i].tl=a[i];
    }
    sort(b+1,b+n+1);
    while(b[1].tl-b[m].tl>b[2].tl||(b[1].tl-b[m].tl==b[2].tl&&b[1].id>b[2].id)){
        b[1].tl-=b[m].tl;--m;
        if(m==1) break;
    }
    printf("%lld\n",m);
    while(--T){
        k=read();m=n;
        for(R int i=1;i<=k;++i){
            int pos=read(),val=read();
            a[pos]=val;
        }
        for(R int i=1;i<=n;++i) b[i].id=i,b[i].tl=a[i];
        sort(b+1,b+n+1);
        //for(R int i=1;i<=n;++i) printf("%lld %lld\n",b[i].id,b[i].tl);
        while(b[1].tl-b[m].tl>b[2].tl||(b[1].tl-b[m].tl==b[2].tl&&b[1].id>b[2].id)){
            b[1].tl-=b[m].tl;--m;
            if(m==1) break;
        }
        printf("%lld\n",m);
    }
    return 0;
}





















