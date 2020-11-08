#include<cstdio>
#include<iostream>
using namespace std;
#define M 
#define il inline
#define ri register int 
il int read()
{
	int k=0;bool f=true;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=false;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		k=(k<<1)+(k<<3)+(ch^48),ch=getchar();
	return f?k:-k;
}
int t,n;
int main()
{
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w",stdout);
  t=read();
  while(t--)
  {
    n=read();
    
  }
  return 0;
}
