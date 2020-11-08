#include<bits/stdc++.h>
using namespace std;
int q;
int s;
int h;
int g=1;
int y=-4713;
int rl(int x)
{
g=1;
y=-4713;
int m[15];
m[1]=31;
m[2]=28;
m[3]=31;
m[4]=30;
m[5]=31;
m[6]=30;
m[7]=31;
m[8]=31;
m[9]=30;
m[10]=31;
m[11]=30;
m[12]=31;
int k=366;
int o=0;
x=x+1;
while(x>=k)
{
x=x-k;
o=o+k;
y=y+1;
if(y==0)
y=1;

if(y>0&&y<1582&&y%4==0)
k=366;
else
if(y<0&&(0-y-1)%4==0)
k=366;
else                   
if((y>=1583)&&(y%400==0||(y%4==0&&y%100!=0)))
k=366;
else
if(y==1582)
k=355;
else 
k=365;
}

if(k==355)
m[2]=28;
if(k==366)
m[2]=29;
if(y==1582)
m[10]=21;
else
m[10]=31;
while(x>m[g])
{
x=x-m[g];
g++;
}	
return x;
}

int main(){
freopen("julian.in","r",stdin);
freopen("julian.out","w",stdout);
cin>>q;
for(int i=1;i<=q;i++)
{
cin>>s;
h=rl(s);
if(y<0)
cout<<h<<" "<<g<<" "<<-y<<" "<<"BC"<<endl;
else	
cout<<h<<" "<<g<<" "<<y<<endl;
}


return 0;
}
