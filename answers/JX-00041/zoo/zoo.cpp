#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<ctime>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int MAXN=1e6+5;

unsigned long long n,m,c,k,p[MAXN],q[MAXN],a[MAXN],u,ans;
int main(){
  freopen("zoo.in","r",stdin);
  freopen("zoo.out","w",stdout);
  scanf("%d%d%d%d",&n,&m,&c,&k);
  for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
  for(int i=1;i<=m;i++) scanf("%lld%lld",&p[i],&q[i]);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      if(a[i]&(1<<p[j]))
        u=u|(1<<(q[j]));
    }
  for(unsigned long long i=0;i<(1<<k);i++){
    bool flag=0;
    for(int j=1;j<=m;j++){
      if(i&(1<<p[j]))
        if(!(u&(1<<(q[j]))))
          flag=1;
    }
    if(!flag) ans++;
  }
  printf("%lld\n",ans-n); 
  return 0;
}
