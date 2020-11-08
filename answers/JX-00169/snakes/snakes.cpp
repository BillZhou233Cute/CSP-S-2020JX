#include<bits/stdc++.h>
using namespace std;
int n,T,a[1145];
int main(){
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w",stdout);
  cin>>T;
  for(int i=1;i<=T;i++){
    cin>>n;
    for(int j=1;j<=n;j++){
       cin>>a[j];
       if((a[1]>(a[2]+a[3]))||(a[2]>(a[1]+a[3]))||(a[3]>(a[1]+a[2]))){
	 cout<<1<<endl;}
       else{
         int b=rand();
	 if(b<=0){ b=-b;b++;}
	 cout<<b%3+1<<endl;}
  }
  }
  return 0;
}
