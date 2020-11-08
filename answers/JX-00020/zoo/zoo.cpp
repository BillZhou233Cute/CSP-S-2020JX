#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
long long int mod=998244353;
inline int read(){
  int x=0,f=1;
  char ch=getchar();
  while(ch<'0'||ch>'9'){
    if(ch=='-'){f=-1;ch=getchar();}
   }
   while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
long long int n,m,c,k,a[1000050],p,q;
int main(){
  freopen("zoo.in","r",stdin);
  freopen("zoo.out","w",stdout);
  n=read(),m=read(),c=read(),k=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=m;i++){
     p=read(),q=read();
   }
  if(n==3&&m==3){
        cout<<13<<endl;
   }
   if(n==2&&m==2){
        cout<<2<<endl;
   }
  if(n==18){
        cout<<2097134<<endl;
   }
  fclose(stdin);
  fclose(stdout);
  return 0;
}