#include<bits/stdc++.h>
using namespace std;
int n,m,k,h,r;
bool com1(int x,int y)
{
return x>y;
}
int a[1000006];
int b[1000006];
int yu,xu;
int main(){
freopen("snakes.in","r",stdin);
freopen("snakes.out","w",stdout);
cin>>n;
cin>>m;
for(int i=1;i<=m;i++)
{
cin>>a[i];
b[i]=a[i];
}
k=m;
h=0;
sort(a+1,a+k+1,com1);
while(a[1]/2>=a[k])
{
h++;
a[1]=a[1]-a[k];
k--;
sort(a+1,a+k+1,com1);
}
cout<<m-h<<endl;
for(int i=1;i<=m;i++)
{
a[i]=b[i];
}



for(int i=2;i<=n;i++)
{
cin>>r;
for(int i=1;i<=r;i++)
{
cin>>xu>>yu;
a[xu]=yu;
}
k=m;
h=0;
sort(a+1,a+k+1,com1);
while((a[1]-a[k]>=a[k-1]))
{
h++;
a[1]=a[1]-a[k];
k--;
if(k==2)
{
cout<<1;
return 0;
}
}

cout<<m-h<<endl;

for(int i=1;i<=m;i++)
{
a[i]=b[i];
}
}

return 0;
}
