#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<ctime>
#include<algorithm>
#include<cstdlib>
using namespace std;
const long long N=-4713,J=1461,G=146097,mid1=(-N)/4*J+366,mid2=J*1575+365+277;
long long Q,r;
bool flag;
int mon[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long worky(long long d){
  long long ans;
  if(d<=mid1){
	 ans=N;
    if(d%J<366) flag=1;
    ans+=4*(d/J);
    d%=J;
    r=d;
    if(d>366)
      ans+=ceil((d-366)/365)+1,r-=(d-366)/365*365+366;
    return ans;
  } 
  else if(d>mid1&&d<=mid2){
	   ans=1;
      d-=mid1;
	  if(d%J>1095) flag=1;
	  ans+=4*(d/J);
	  d%=J;
	  if(d>1095)
            ans+=3,d-=1095;
	  else 
	    ans+=d/365,d-=365*(d/365);
	   r=d;
	return ans;
  }
  else {
    d-=mid2-(365-277);
    if(mid2<=365-277)
      return 1582;
    ans=1583;
    ans+=400*(d/G);
    d%=G;
    return rand();
  }
  
}
int workm(int d){
  for(int i=1;i<=12;i++){
    if(i==2){
      if(flag) d--;
      if(d<=29&&flag){return 2;}
      if(d<=28&&(!flag))
       return 2;
    }
    else{
      if(d<=mon[i]) {
        r=d;
        return i;
      }  
    } 
    d-=mon[i];
  }
}
int main(){
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  srand(time(0));
  scanf("%lld",&Q);
  while(Q--){
    scanf("%lld",&r);
    flag=0;
    int y=0,m=0,d=0;
    y=worky(r);
    r++;
    m=workm(r);
    d=r;
    if(y>0)
      printf("%d %d %d",d,m,y);
    else
      printf("%d %d %d BC",d,m,-y);
  }
  return 0;
}
