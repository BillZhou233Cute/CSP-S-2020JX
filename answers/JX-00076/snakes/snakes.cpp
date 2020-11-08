#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,a[1000010],ans[12],tail=1,b[1000010];
void slove()
{
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int s=a[n],l=1,r=n,en=a[n-1];
	while(l<r)
	{
		int mid=(l+r)/2;
		if(s-b[mid]>=en) l=mid+1;
		else r=mid-1;
	}
	ans[tail]=n-l+1;
	tail++;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t,k;
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	slove();
	for(int i=1;i<=t-1;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			a[x]=y;
		}
		slove();
	}
	for(int i=1;i<=tail-1;i++) cout<<ans[i]<<endl;
	return 0;
}