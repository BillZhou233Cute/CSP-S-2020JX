#include<bits/stdc++.h>
using namespace std;
bool have[70];
bool hn[70];
bool ani[1000010];
int lg[1<<20+1];
typedef long long ll;
ll n,m,c,k;
ll ans;
int lowbit(int x)
{
  return x&(-x);
}
int main()
{
  freopen("zoo.in","r",stdin);
  freopen("zoo.out","w",stdout);
  scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
  for(int i=2;i<(1<<20);i++)
    {
      int t=i/2;
      lg[i]=lg[t]+1;
    }
  for(int i=1;i<=n;i++)
    {
      int t;
      scanf("%d",&t);
      ani[t]=1;
      while(t)
	{
	  have[lg[lowbit(t)]]=1;
	  t-=lowbit(t);
	}
    }
  for(int i=1;i<=m;i++)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      if(!have[a])
	{
	  hn[a]=1;
	}
    }
  ans=(1<<k);
  ans-=n;
  for(int i=1;i<=(1<<k)-1;i++)
    {
      if(ani[i]==0)
	{
	  int t=i;
	  while(t)
	    {
	      if(hn[lg[lowbit(t)]])
		{
		  ans--;
		  break;
		}
	      t-=lowbit(t);
	    }
	}
    }
  printf("%lld\n",ans);
  return 0;
}
