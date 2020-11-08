#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
int T;
int a[1000005]
int k;
using namespace std;
void test()
{
if(n==3)
{
	if(a[3]>=a[2]+a[1])puts("1");
	else puts("3");
	}
	else
	{
	int t=n;
	while(a[t]>=a[1]+a[t-1]) t--;
	printf("%d\n",t);
	}

}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin >> T;
	T--
	int n
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	test();
	while(T--)
	{
		int k;
		cin >> k;
		int kk,kkk;
		for(int i=1;i<=k;i++)
		{
		cin >> kk >> kkk;
		a[kk]=kkk;
		}
		test();
	}
	return 0;
}

