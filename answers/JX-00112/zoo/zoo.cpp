#include<cstdio>
#include<iostream>
using namespace std;
#define M 1000001
#define il inline
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
  return f?k:-k;
}
bool op[65],op2[65],op3[M],op4[100000000001];
int n,m,c,k,ans;
int a,p,q,pq[5000][5000];
il void add(int pos)
{
  int now=-1;
  while(pos)
  {
    ++now;
    if(pos&1)op[now]=true;
    pos>>=1;
  }
}
il bool add2(int pos)
{
  int now=-1;
  while(pos)
  {
    ++now;
    if(op3[now]&&(pos&1))
      for(ri i=1;i<=pq[now][0];++i)
	if(!op2[pq[now][i]])return false;
    pos>>=1;
  }
  return true;
}
int main()
{
  freopen("zoo.in","r",stdin);
  freopen("zoo.out","w",stdout);
  n=read(),m=read(),c=read(),k=read();
  for(ri i=1;i<=n;++i)
  {
    a=read();
    add(a);
    op4[a]=true;
  }
  for(ri i=1;i<=m;++i)
  {
    p=read(),q=read();
    pq[p][++pq[p][0]]=q;
    if(op[p])op2[q]=true;
    op3[p]=true;
  }
  for(ri i=1;i<=1<<k;++i)
    if(!op4[i])ans+=add2(i);
  printf("%d",ans);
  return 0;
}
