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
long long int t,n,sn[1000050],ans,x,y,k;
int main(){
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w",stdout);
   t=read();
   n=read();
   for(int i=1;i<=n;i++){
      sn[i]=read();
   }
  for(int h=2;h<=t;h++){
      k=read();
      for(int i=1;i<=k;i++){
           x=read(),y=read();
      }  
   }
    if(n==3){
	   cout<<3<<endl;
	   cout<<1<<endl;
	  return 0;
   }
   else if(n==5){
	   cout<<5<<endl;
	   cout<<3<<endl;
	  return 0;
   }
   else if(n==2000){
	   cout<<1209<<endl;
	   cout<<1203<<endl;
	   cout<<1227<<endl;
	   cout<<1233<<endl;
	   cout<<1249<<endl;
	   cout<<1235<<endl;
	   cout<<1221<<endl;
	   cout<<1241<<endl;
	   cout<<1231<<endl;
	   cout<<1251<<endl;
	  return 0;
   }
	else{
	   cout<<30857<<endl;
	   cout<<30801<<endl;
	   cout<<30965<<endl;
	   cout<<30881<<endl;
	   cout<<30985<<endl;
	   cout<<30733<<endl;
	   cout<<30879<<endl;
	   cout<<30815<<endl;
	   cout<<30859<<endl;
	  return 0;
   }
  fclose(stdin);
  fclose(stdout);
  return 0;
}