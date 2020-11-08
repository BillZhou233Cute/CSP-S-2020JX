#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
long long a[1000010];
int main()
{
  int n,m,c,k,x,y,minn=10001000;
 freopen("zoo.in","r",stdin);
 freopen("zoo.out","w",stdout);
  cin>>n>>m>>c>>k;
  for(int i=1;i<=n;i++)
    {
      cin>>a[i];
    }
  for(int i=1;i<=m;i++)
    {
      cin>>x>>y;
      if(x*y<minn)
	minn=x*y;
    }
  long long tt=pow(2,k);
  cout<<tt-n-minn;	
}
