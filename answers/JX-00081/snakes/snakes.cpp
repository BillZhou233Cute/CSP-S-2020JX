#include<bits/stdc++.h>
using namespace std;
freopen("snakes.in","r",stdin);
freopen("snakes.out","w",stdout);
int n,t,k;
int a[1000005],b[1000005];
void work(int ci)
{for(int i=1;i<=ci;i++)
    {
      cin>>k;
      int x,y;
      for(int j=1;j<=k;j++)
	{
	  cin>>x>>y;
	  a[x]=y,b[x]=a[x];}
      sort(b+1,b+1+n);
      if(b[3]-b[1]>b[2])
	{cout<<1<<endl;}
      else if(b[3]-b[1]==b[2]&&(a[3]>a[2]||a[3]>a[1]||a[2]>a[1])) cout<<1<<endl;
      else cout<<3<<endl;}}

int main()
{
  cin>>t;
  cin>>n;
  if(n==3)
    {
      for(int i=1;i<=n;i++){cin>>a[i];b[i]=a[i];};
      sort(b+1,b+1+n);
      if(b[3]-b[1]>=b[2])
	{
	  cout<<1<<endl; }
      else cout<<3<<endl;
      work(t-1);}
  return 0;}
