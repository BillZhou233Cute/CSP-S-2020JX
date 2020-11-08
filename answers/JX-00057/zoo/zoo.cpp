#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
int a[1000006];
int q[1000006];
int p[1000006];
int s;
int main(){
freopen("zoo.in","r",stdin);
freopen("zoo.out","w",stdout);
cin>>n>>m>>c>>k;
for(int i=1;i<=n;i++)
{
cin>>a[i];
}

for(int i=1;i<=m;i++)
{
cin>>q[i]>>p[i];
}

s=1;
for(int i=1;i<=k;i++)
{
s=s*2;
}

cout<<s-n;
return 0;
}
