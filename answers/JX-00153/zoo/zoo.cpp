#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1e6+1;
const int C=1e8+1;
ll f[N<<2],n,k,m,c,a[N],p[N],q[N];
int head[N],cnt,num[N];
ll sum=1;
bool pd[N],ys[N];
int main(){
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
    scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
    for(int i=1;i<=n;i++)
    scanf("%lld",&a[i]);
    for(int j=1;j<=m;j++)
    scanf("%lld%lld",&p[j],&q[j]),f[q[j]]=p[j],num[p[j]]++; 
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
      if((a[i]>>p[j])&1)pd[q[j]]=1;
    for(int i=1;i<=c;i++)
    if(pd[q[i]]==1)num[f[q[i]]]--;
    for(int i=1;i<=k;i++)
    if(num[p[i]]==0)cnt++;
    sum=1<<cnt;sum-=n;
    cout<<sum;
    return 0;
}
