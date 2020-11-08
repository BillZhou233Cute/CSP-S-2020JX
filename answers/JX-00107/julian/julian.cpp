#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int julian[10001];
int mod=365;
struct gong{
    int Day,Month,Year;
    string BC;
}gong[10001];
inline int read(){
    int w=1,s=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') w=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return s*w;
}
int main(){
    int n=read();
    for(int i=1;i<=n;i++){
        scanf("%d",&julian[i]);
        int r;
        if(n<=1721423+578101) { 
        gong[i].Year=n/mod;//模糊判断
        r=julian[i]/1461;//闰年统计（公元前）
        gong[i].Year+=(n%mod-r)/mod;
        if(n<=1721423) gong[i].BC[0]='B',gong[i].BC[1]='C';
        }
        else {
        gong[i].Year=n/mod;//模糊判断
        r=(julian[i]+14)/1461;//闰年统计（公元前）
        gong[i].Year+=(n%mod-r)/mod;}
        cout<<gong[i].Year;
    }

    return 0;
}
