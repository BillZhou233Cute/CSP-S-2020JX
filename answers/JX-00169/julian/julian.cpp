#include<bits/stdc++.h>
using namespace std;
int q,r[100004],sy=4713,sm=1,sd=1,cny=1;
int dt[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void js(int y,int m,int da,int is_){
  da-=is_;
  da++;
 while(da>dt[m]){
   da-=dt[m];m++;
  }
 cout<<da<<" "<<m<<" "<<y<<" BC"<<endl;
}
void bf(int d){
  if(d<365) js(sy,sm,d,d<=59?0:1);
  if((365<=d)&&(d<731)) js(sy--,sm,d-366,1);
  if((731<=d)&&(d<1096)) js(sy-=2,sm,d-730,1);
  if((1096<=d)&&(d<1461)) js(sy-=3,sm,d-1095,1);
}
int main(){
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  scanf("%d",&q);
  for(int i=1;i<=q;i++) {scanf("%d",&r[i]);bf(r[i]);}
 return 0;
}
