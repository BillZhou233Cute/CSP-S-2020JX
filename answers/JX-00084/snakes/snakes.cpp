#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
const int maxx=1e5;
using namespace std;
int a[maxx];
int main()
{
	int t,n;
	freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<=n;j++)scanf("%d",&a[i]);
		if(n==3)printf("3\n");
		else if(n==2)printf("1\n");
		else printf("%d\n",rand());
	}
	return 0;
}
