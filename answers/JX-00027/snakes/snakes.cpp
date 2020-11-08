#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int t,n,k,p,a[1234];
int cei(int k)
{
  if(k%2==0) return k/2;
  else return k/2+1;
}
bool cmp(int a,int b)
{
  if(a>b) return 1;
  else return 0;
}
int main()
{
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w",stdout);
  cin>>t;
  for(int i=1;i<=t;i++)
    {
      if(i==1)
	{
	  cin>>n;
	  for(int j=1;j<=n;j++)
	    cin>>a[j];
	  sort(a+1,a+1+n,cmp);
	  if(a[1]-a[2]>a[3]) cout<<1<<endl;
	  else if(a[1]-a[2]==a[3]) cout<<2<<endl;
	  else if(a[1]-a[2]<a[3]) cout<<3<<endl;
	}
      else 
	{
	  cin>>k;
	  for(int w=1;w<=2*k;w++)
	    {
	      cin>>p;
	      if(w%2==0) a[cei(w)]=p;
	    }
	      sort(a+1,a+1+n,cmp);
	      if(a[1]-a[2]>a[3]) cout<<1<<endl;
	      else if(a[1]-a[2]==a[3]) cout<<2<<endl;
	      else if(a[1]-a[2]<a[3]) cout<<3<<endl;
	}
    }
  return 0;
}
