#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define mo 998244353
int n,a[maxn];
struct work{
int x,y;
int z;
int call[5000];
int type;
}w[maxn];
long long lazy;
void all(int lazy)
{
for(int i=1;i<=n;i++)
a[i]=a[i]*lazy%mo;
}
void work(int x){
int cnt=1;
if(w[x].x)a[w[x].x]+=w[x].y;
else if(w[x].z)all(w[x].z);
}

int main()
{
freopen("call.in","r",stdin);
freopen("call.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
cin>>a[i];
int m;
cin>>m;
for(int i=1;i<=m;i++)
{int t,c;cin>>t;
if(t==1){cin>>w[i].x>>w[i].y;}
else if(t==2){cin>>w[i].z;}
else if(t==3){cin>>c;
for(int j=1;j<=c;j++)
{cin>>w[i].call[j];}
}}
int q;
cin>>q;
for(int i=1;i<=q;i++)
{int x;
cin>>x;
if(w[x].type==3)
{int cnt=1;
while(w[x].call[cnt])
{work(w[x].call[cnt]);
cnt++;
}
}
else work(x);
}

for(int i=1;i<=n;i++)
cout<<a[i]<<" ";
return 0;}
