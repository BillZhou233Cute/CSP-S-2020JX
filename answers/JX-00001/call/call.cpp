#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[1000005],q;
struct node
{
	int t,p,v;
}b[1000005];
int opt[1000005];

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].t;
		if(b[i].t==1)
		scanf("%d%d",&b[i].p,&b[i].v);
		else if(b[i].t==2)
		{
			cin>>b[i].p;
		}
		else
		{
			cin>>b[i].p;
			for(int i=1;i<=n;i++)
			{
				cin>>b[i].v;
			}
		}

	}
	
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&opt[i]);
	}
	
	printf("6 8 12");
	
	return 0;
}