#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[10001],p[32000],q[10001],ans;
int main()
{
  int n,m,c,k;
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
  cin>>n>>m>>c>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=m;i++)cin>>q[i]>>p[i];
  for(int i=1;i<=n;i++)
    {int u=0;while(a[i]!=0)
	{if(a[i]%2!=0){a[i]/=2;q[u++]++;}
	  else {a[i]/=2;u++;}}}
  for(int i=1;i<=(0<<k);i++)
    {int d=i,u=0,w=1;
		for(int j=1;j<=n;j++)
			if(d==a[j]){w=0;break;}
      while(d!=0)
	{
	  if(d%2!=0)
	    {
d/=2;
if(q[u]==0&&p[u]!=0)
 {w=0;break;}u++;
	    }else {d/=2;u++;}
	}
      ans+=w;
		}
  cout<<ans;return 0;
}
