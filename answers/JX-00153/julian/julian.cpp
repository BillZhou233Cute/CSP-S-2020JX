#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
const int N=1e5+7;
const int MAXN=1e5+1;
const int bd=1721423;
ll q,y[MAXN],maxx,m[MAXN],d[MAXN],r[N];
ll run[13]={0,31,60,91,121,152,182,213,244,274,305,335,366};
ll ping[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
bool pd[N];
inline ll find(ll num){
    for(int j=1;j<=12;j++)
    if(num<=run[j])return j;
}
inline ll find2(ll num){
    for(int j=1;j<=12;j++)
    if(num<=ping[j])return j;
}
inline void work1(int i){
     ll w=r[i]/365;
     ll sum;
     if(w>=1)
     sum=(w-1)/4+1;
     else sum=0;
     while(w*365+sum>r[i])w--;
     y[i]=abs(4713-w);
     int vis=w*365+sum;
     sum=r[i]-vis;
     if((w-1)%4==0||w==0)
     m[i]=find(sum);
     else m[i]=find2(sum);
     if((w-1)%4==0||w==0)
     d[i]=sum-run[m[i]-1]+1;
     else d[i]=sum-ping[m[i]-1]+1;
}
inline void work2(int i){
     r[i]-=bd;
     ll w=r[i]/365;
     ll sum;
     if(w>=1)
     sum=(w-1)/4+1;
     else sum=0;
     ll vis=w*365+sum;
     if(vis<=r[i])y[i]=w+1;
     else y[i]=--w+1;
     vis=w*365+sum;
     sum=r[i]-vis;
     if((w-1)%4==0||w==0)
     m[i]=find(sum);
     else m[i]=find2(sum);
     if((w-1)%4==0||w==0)
     d[i]=sum-run[m[i]-1]+1;
     else d[i]=sum-ping[m[i]-1]+1;
}
int main(){
    freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    scanf("%lld",&q);
    for(int i=1;i<=q;i++){
        scanf("%lld",&r[i]);
        maxx=max(r[i],maxx);
    }
    for(int i=1;i<=q;i++){
         if(r[i]<=bd)pd[i]=1,work1(i);
         else work2(i);
    }
    for(int i=1;i<=q;i++)
    if(pd[i])
    printf("%lld %lld %lld BC\n",d[i],m[i],y[i]);
    else printf("%lld %lld %lld\n",d[i],m[i],y[i]);
    return 0;
}
