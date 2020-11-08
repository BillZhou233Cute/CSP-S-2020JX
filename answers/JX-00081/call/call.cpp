#include<bits/stdc++.h>
using namespace std;
freopen("call.in","r",stdin);
freopen("call.out","w",stdout);
inline int read()
{char ch;
  while((ch=getchar())<'0'||ch>'9');
  int res=ch-48;
  while((ch=getchar())>='0'&&ch<='9')
    res=res*10+ch-48;
  return res;
}
  long long n,m,t[100005],add[100005][2],a[100005],cheng[100005];

int main()
{
  n=read();
  for(int i=1;i<=n;i++)
    {
      a[i]=read();
    }
  m=read();
  for(int i=1;i<=m;i++)
    {
      t[i]=read();
      if(t[i]==1)
	{
	  add[i][0]=read(),add[i][1]=read();}
      else{
	cheng[i]=read();}
    }
  int q=read();
  for(int i=1;i<=q;i++)
    {
      int f;
      f=read();
      if(t[f]==1)
	{a[add[f][0]]+=add[f][1];}
      else{for(int k=1;k<=n;k++)
	  {
	    a[k]*=cheng[f];}
      }
    }
  for(int i=1;i<=n;i++)
    cout<<a[i]%998244353<<" ";
  return 0;
}
