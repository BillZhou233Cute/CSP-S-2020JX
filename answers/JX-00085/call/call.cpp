#include<bits/stdc++.h>
using namespace std;
int n,a[100001],m,s,y;
inline long long read(){
  long long x=0,f=1;
  char ch=getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-') f=-1;
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=x*10+ch-'0';
    ch=getchar();
  }
  return x*f;
}
struct ijk{
  int t,x,p,m[1001];
}b[100001];
void dfs1(int y){
  a[b[y].x]+=b[y].p;
}
void dfs2(int y){
  for(int i=1;i<=n;i++)
    a[i]*=b[y].x;
}
void dfs3(int y){
  for(int i=1;i<=b[y].x;i++)
  {
    if(b[y].t==1)dfs1(y);
    if(b[y].t==2)
      dfs2(y);
    if(b[y].t==3)
      dfs3(y);
  }
}
int main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  m=read();
  for(int i=1;i<=m;i++){
    b[i].t=read();
    if(b[i].t==1){
      b[i].x=read();
      b[i].p=read();
    }
    if(b[i].t==2)
      b[i].x=read();
    if(b[i].t==3){
      b[i].x=read();
      for(int j=1;i<=b[i].x;i++)
	b[i].m[j]=read();
    }
  }
  s=read();
  for(int i=1;i<=s;i++){
    y=read();
    if(b[y].t==1)dfs1(y);
    if(b[y].t==2)
      dfs2(y);
    if(b[y].t==3)
      dfs3(y);
  }
  for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    return 0;
}
