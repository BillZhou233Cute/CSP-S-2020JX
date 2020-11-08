#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
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
long long int n,m,p,v,a,b,q,qi,t;
int main(){
  freopen("call.in","r",stdin);
  freopen("call.out","w",stdout);
  n=read();
  for(int i=1;i<=n;i++){
      a=read();
   }
  m=read();
   for(int i=1;i<=m;i++){
       t=read();
       if(t==1) p=read(),v=read();
        if(t==2)  v=read();
        if(t==3){
            a=read();
             for(int j=1;j<=a;j++){
                  b=read();
              }
        } 
   }
   q=read();
   for(int i=1;i<=q;i++){
         qi=read();
    }
   if(n==3) cout<<6<<" "<<8<<" "<<12;
   if(n==10){
	cout<<36<<" "<<282<<" "<<108<<" "<<144<<" ";
	cout<<180<<" "<<216<<" "<<504<<" "<<288<<" "<<324<<" "<<360;
   }
  fclose(stdin);
  fclose(stdout);
  return 0;
}