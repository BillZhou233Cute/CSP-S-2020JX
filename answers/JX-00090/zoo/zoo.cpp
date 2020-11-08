#include<cstdio>
using namespace std;
long long a[1000005];
int q[1000005],p[1000005];
bool ask[65],mark[65];
bool judge(long long x,int y)
{
  for(int i=1;i<=y;++i) x/=2;
  return x&1;
}
int main()
{
  freopen("zoo.in","r",stdin);
  freopen("zoo.out","w",stdout);
  int n,m,c,k,ans=0;
  scanf("%d%d%d%d",&n,&m,&c,&k);
  for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
  for(int i=1;i<=m;++i){
    scanf("%d%d",&p[i],&q[i]);
    ask[p[i]]=1;
  }

  for(int i=1;i<=n;++i){
    for(int j=0;j<=64;++j){
      if(mark[j]) continue;
      if(judge(a[i],j)){
	for(int x=1;x<=m;++x)
	  if(p[x]==j){
	    mark[j]=1;
	    for(int y=1;y<=m;++y) if(q[x]==q[y]) mark[p[y]]=1;
	  }
      }
    }
  }
  for(int i=0;i<k;++i)
    if(!ask[i]||mark[i]) ans++;
  ans=(1<<ans)-n;
  printf("%d",ans);
  return 0;
}
