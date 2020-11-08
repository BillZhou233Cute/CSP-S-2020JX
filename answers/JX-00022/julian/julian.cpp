#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int md1[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int md2[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int yd[4]={366,365,365,365};
int r;
int mj(int run)
{int m=1;
if(run==1)
while(r>md1[m])
{
r-=md1[m];
m++;
}
else while(r>md2[m])
{
r-=md2[m];
m++;
}
return m;
}
int main()
{
freopen("julian.in","r",stdin);
freopen("julian.out","w",stdout);
int q;
cin>>q;
for(int i=1;i<=q;i++)
{int y=0,m,d;
cin>>r;
if(r<=1721058)
{while((r>365&&y%4!=0)||(r>366&&y%4==0))
{r-=yd[y%4];y++;}
if(y%4==0)m=mj(1);
else m=mj(0);
cout<<r<<m<<4713-y<<"BC"<<endl;}
else if(r>1721058&&r<=577733)
{r-=1721058;y=1;
while((r>365&&y%4!=0)||(r>366&&y%4==0))
{r-=yd[y%4];y++;}
if(y%4==0)m=mj(1);
else m=mj(0);
cout<<r<<" "<<m<<" "<<y<<endl;}
else{
r-=1721068;y=1582;
while((r>365&&y%4!=0)||(r>366&&y%4==0))
{if(y%100!=0)
{r-=yd[y%4];y++;}
else {r-=365;y++;}}
if(y%4==0&&y%100!=0)m=mj(1);
else m=mj(0);
cout<<r<<" "<<m<<" "<<y<<endl;
}}
return 0;}
