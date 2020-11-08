#include <iostream>
#include <stdio.h>
using namespace std;
int t,n,ans;
int a[1000010];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int j=1;j<=n;j++)
	scanf("%d",&a[j]);
	int h=1;
	while(a[n]-a[h]>=a[n-1])h++;
	printf("%d\n",n-h+1);
	for(int i=2;i<=t;i++)
	{
			int m;
			 scanf("%d",&m);
			 for(int j=1;j<=m;j++)
			 {
				 int b,x;
				 scanf("%d%d",&b,&x);
				 a[b]=x;
			 }
			 int h=1;
		     while(a[n]-a[h]>=a[n-1])h++;
		     printf("%d\n",n-h+1);
	}
	return 0;
}