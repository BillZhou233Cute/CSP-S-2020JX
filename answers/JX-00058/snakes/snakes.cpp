#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[1000010];
int main()
{
  int n,m,c,k,t,x,y;
 freopen("snakes.in","r",stdin);
 freopen("snakes.out","w",stdout);
  cin>>t>>n;
  for(int i=1;i<=t;i++)
    {
      if(i==1){ 
      	for(int i=1;i<=n;i++)
           cin>>a[i];
	sort(a+1,a+n+1);
	if(a[3]-a[1]<a[2])
	  {
	    cout<<3<<endl;
	  }
	else if(a[3]-a[1]==a[2])
	  cout<<2<<endl;
	else
	  cout<<1<<endl;
      }
	  else{ 
		  cin>>n;
		  for(int i=1;i<=n;i++)
       {
        cin>>x>>y;
       	a[x]=y;
       }	sort(a+1,a+n+1);
	if(a[3]-a[1]<a[2])
	  {
	    cout<<3<<endl;
	  }
	else if(a[3]-a[1]==a[2])
	  cout<<2<<endl;
	else
	  cout<<1<<endl;
      }
	  }
}
