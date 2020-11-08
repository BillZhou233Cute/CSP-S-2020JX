#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int f1[100010],f2[100010];
int f1num[100010];
struct node
{
  int f[100010],num;
}f3[100010];
int main()
{
  freopen("call.in","r",stdin);
  freopen("call.out","w",stdout);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    {
      cin>>a[i];
    }
  int m;
  cin>>m;
  for(int i=1;i<=m;i++)
    {
      int ty;
      cin>>ty;
      if(ty==1)
	{
	  cin>>f1num[i]>>f1[i];
	}
      if(ty==2)
	{
	  cin>>f2[i];
	}
      if(ty==3)
	{
	  cin>>f3[i].num;
	  for(int j=1;j<=num;j++)
	    {
	      cin>>f3[i].f[j];
	    }
	}
    }
  int q;
  cin>>q;
  for(int i=1;i<=q;i++)
    {
      int t;
      cin>>t;
      if(f1[t])
	{
	  a[f1num[t]]+=f1[t];
	  continue;
	}
      if(f2[t])
	{
	  for(int i=1;i<=n;i++)
	    {
	      a[i]=a[i]*f2[t];
	    }
	}
      if(f3[t].num)
	{
	  for(int j=1;j<=f3[t].num;j++)
	    {
	      if(f1[f3[t].f[i]])
	{
	  a[f1num[t]]+=f1[f3[t].f[i]];
	  continue;
	}
      if(f2[f3[t].f[i]])
	{
	  for(int i=1;i<=n;i++)
	    {
	      a[i]=a[i]*f2[f3[t].f[i]];
	    }
	}
	    }
	}
    }
  for(int i=1;i<=n;i++)
    {
      cout<<a[i]<<endl;
    }
  return 0;
}
