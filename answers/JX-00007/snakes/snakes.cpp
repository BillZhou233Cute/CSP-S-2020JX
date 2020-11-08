#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int a[N];
struct qb{
  int s,h;
}b[N];
inline int read(){
  int f=1,ans=0;
  char c=getchar();
  while(c<'0'||c>'9'){
    if(c=='-')f=-1;
    c=getchar();}
  while(c>='0'&&c<='9')
    ans=ans*10+c-'0',c=getchar();
  return f*ans;
}
inline bool tmp(qb w,qb e){
  return w.s>e.s||(w.s==e.s&&w.h>e.h);
}
int main(){
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w",stdout);
  int T=read()-1,n=read(),ans,x,y,k,maxx;
  for(int i=1;i<=n;i++)
    b[i].s=a[i]=read(),b[i].h=i;
  ans=n;
  while(1){
    maxx=ans;
  sort(b+1,b+ans+1,tmp);
  for(int i=maxx;i>2;i--)
 if(b[1].s-b[i].s>b[i-1].s||(b[1].s-b[i].s==b[i-1].s&&b[1].h>b[i-1].h))
   b[1].s-=b[i].s,ans--;
  if(ans==2&&(b[1].s>b[2].s||(b[1].s==b[2].s&&b[1].h>b[2].h))){
    b[1].s-=b[2].s,ans--;
    break;}
 if(ans==maxx)break;
  }
  cout<<ans<<endl;
  while(T--){
    k=read();
    while(k--)
      x=read(),y=read(),a[x]=y;
 for(int i=1;i<=n;i++)
   b[i].s=a[i],b[i].h=i;
 ans=n;
  while(1){
    maxx=ans;
  sort(b+1,b+ans+1,tmp);
  for(int i=maxx;i>2;i--)
 if(b[1].s-b[i].s>b[i-1].s||(b[1].s-b[i].s==b[i-1].s&&b[1].h>b[1-i].h))
      b[1].s-=b[i].s,ans--;
 if(ans==2&&(b[1].s>b[2].s||(b[1].s==b[2].s&&b[1].h>b[2].h))){
    b[1].s-=b[2].s,ans--;
    break;}
 if(ans==maxx)break;
  }
   cout<<ans<<endl;
   }
  return 0;//g++ snakes.cpp -o snakes
}
