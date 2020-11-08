#include<cstdio>
#include<iostream>
#include<map>
#include<bitset>
using namespace std;
//short int mp[100000008];
map<int,short int> mp;
int q[1000005];
long long sa,a;
bool vis[1000000];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,p;
	long long k;
	scanf("%d %d %d %lld",&n,&m,&c,&k);
	for(int i=1;i<=n;i++) cin>>a,sa|=a;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&q[i]);
		mp[q[i]]=p;
	}
	for(int i=1;i<=m;i++)
		if(!(sa&(1<<mp[q[i]]))&&!vis[mp[q[i]]])
		{
			k--;
			vis[mp[q[i]]]=1;
		}
	printf("%lld",(1ll<<k)-n);
	return 0;
}
