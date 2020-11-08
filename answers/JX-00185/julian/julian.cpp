#include<bits/stdc++.h>
using namespace std;
long long x[100001],y[100001],z[12],v[12],l[100001],c[100001],i,j;
void js()
{      
	if(j==-1582) x[i]-=355;
       if(j>-1582) {
	 if(j%4==0) x[i]-=366;else x[i]-=365;}
       if(j<-1582){
	  if(j%400==0)
	    x[i]=x[i]-366;
	  else{
	    if(j%4==0&&j%100!=0)
	      x[i]=x[i]-366;
	    else x[i]-=365;}
       }
}
int main()
{
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
z[0]=31,z[1]=29,z[2]=31,z[3]=30,z[4]=31,z[5]=30,z[6]=31,z[7]=31,z[8]=30,z[9]=31,z[10]=30,z[11]=31;
v[0]=31,v[1]=28,v[2]=31,v[3]=30,v[4]=31,v[5]=30,v[6]=31,v[7]=31,v[8]=30,v[9]=31,v[10]=30,v[11]=31;
  int n;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>x[i];
    y[i]=-4713;
}
  for(i=0; i<n;i++)
    for(j=4713;    ;j--)
      {if(x[i]<=365)break;
	else js();
	y[i]++;
      }
  for(i=0;i<n;i++){
    if((y[i]+1)%4==0&&y[i]+1<1582||(y[i]+1)%4==4&&(y[i]+1)%100!=0)
      for(j=0;j<12;j++){x[i]-=z[j];if(x[i]<=0){c[i]=j+1;  l[i]=z[j-1]+x[i];break;}}
    else for(j=0;j<12;j++){x[i]-=v[j];if(x[i]<=0){c[i]=j+1;l[i]=z[j-1]+x[i];break;}}
	}
  for(i=0;i<n;i++){
    if(y[i]>=0){y[i]++;
      cout<<l[i]<<" "<<c[i]<<" "<<abs(y[i])<<endl;}
    if(y[i]<0)
      cout<<l[i]<<" "<<c[i]<<" "<<abs(y[i])<<" BC"<<endl;}
  return 0;
}
