#include<cstdio>
#include<iostream>
using namespace std;
#define M 100001
#define il inline
#define mod 998244353
#define ri register int 
il int read()
{
  int k=0;bool f=true;char ch=getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')f=false;
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
    k=(k<<1)+(k<<3)+(ch^48),ch=getchar();
  return k;
}
int n,m,q,num[M],t[10001][10002];
int main()
{
  freopen("call.in","r",stdin);
  freopen("call.out","w",stdout);
  n=read();
  for(ri i=1;i<=n;++i)
    num[i]=read();
  m=read();
  for(ri i=1;i<=m;++i)
  {
    t[i][0]=read();
    if(t[i][0]==1)
      t[i][1]=read(),t[i][2]=read();
    if(t[i][0]==2)
      t[i][1]=read();
    if(t[i][0]==3)
    {
      t[i][10001]=read();
      for(ri j=1;j<=t[i][10001];++j)
	t[i][j]=read();
    } 
  }
  q=read();
  while(q--)
  {
    int p=read();
    if(t[p][0]==1)
      num[t[p][1]]+=t[p][2],num[t[p][1]]%=mod;
    if(t[p][0]==2)
      for(ri i=1;i<=n;++i)
	num[i]*=t[i][1],num[i]%=mod;
    if(t[p][0]==3)
      for(ri j=1;j<=t[p][10001];++j)
        if(t[t[p][j]][0]==1)
	  num[t[t[p][j]][0]]+=t[t[p][j]][2],num[t[t[p][j]][0]]%=mod;
	else if(t[t[p][j]][0]==2)
	  for(ri i=1;i<=n;++i)
	    num[i]*=t[t[p][j]][1],num[i]%=mod;
  }
  for(ri i=1;i<=n;++i)
    printf("%d ",num[i]);
  return 0;
}
