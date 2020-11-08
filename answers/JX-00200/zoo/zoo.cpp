#include <iostream>
#include <cstdio>
#include <cctype>
#define il inline
#define ll long long
#define R register
#define gc getchar
#define int unsigned long long
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
int n,m,k,c;
int a[MAXN],p[MAXN],q[MAXN];
int sl[MAXN];       //

//-------------------快速幂-----------------------------------
il int ksm(int a,int b){
    R int ans=1;
    while(b){
        if(b&1) ans*=a;
        a*=a;b>>=1;
    }
    return ans;
}

//-------------------快速幂-----------------------------------

signed main(){
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
    n=read();m=read();c=read();k=read();
    for(R int i=1;i<=n;++i){
        a[i]=read();int j=0;
        while(a[i]){
            if(a[i]&1) sl[j]=1;
            a[i]>>=1;++j;
        }
    }
    for(R int i=1;i<=m;++i){
        p[i]=read(),q[i]=read();
        if(!sl[p[i]]) --k,sl[p[i]]=1;
    }
    cout<<(ksm(2,k)-n);
    return 0;
}





















