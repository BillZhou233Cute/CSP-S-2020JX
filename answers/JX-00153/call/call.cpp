#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+7;
const int mod=998244353;
int n,m,a[N],v[N],cnt,s[N],x[N],c[N][1001];
int  pd[N];
inline void jf(){
cin>>x[++cnt]>>s[cnt];pd[cnt]=1;
}
inline void xf(){
scanf("%d",&v[++cnt]);
pd[cnt]=2;
}
inline void work(){
scanf("%d",&c[++cnt][0]);
for(int i=1;i<=c[cnt][0];i++)
scanf("%d",&c[cnt][i]);pd[cnt]=3;
}
inline void doo(int w){
if(pd[w]==1){
a[x[w]]+=s[w];
a[x[w]]%=mod;
}
else if(pd[w]==2){
for(int i=1;i<=n;i++)
a[i]*=v[w],a[i]%=mod;
}
else {
for(int i=1;i<=c[w][0];i++)
doo(c[w][i]);
}
}
int main(){
freopen("call.in","r",stdin);
freopen("call.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
scanf("%d",&a[i]);
cin>>m;
for(int i=1;i<=m;i++){
int t;
scanf("%d",&t);
if(t==1)jf();
else if(t==2)xf();
else work();
}
int q;
cin>>q;
for(int i=1;i<=q;i++){
int w;cin>>w;
doo(w);
}
for(int i=1;i<=n;i++)
cout<<a[i]<<" ";
return 0;
}
