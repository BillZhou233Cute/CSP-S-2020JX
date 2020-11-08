#include<bits/stdc++.h>
using namespace std;
int n,m,s,k;
unsigned long long a[1000005];
int b[1000005],c[1000005];
bool v[65],vv[65],food[100000005];
unsigned long long ans,cnt;

bool check(int x)
{
	int res=0;
	while(x)
	{
		if(x%2 && !v[res])
		{
			return false;
		}
		x/=2;
		res++;
	}
	return true;
}	

void fun(int x)
{
	int res=0;
	while(x)
	{
		if(x%2)
		{
			v[res]=true;
		}
		x/=2;
		res++;
	}
}

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	
	memset(v,true,sizeof(v));
	scanf("%d%d%d%d",&n,&m,&s,&k);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i],&c[i]);
		v[b[i]]=false;
	}
	
	for(int i=1;i<=n;i++)
	{
		fun(a[i]);
	}
	
	for(int i=1;i<=m;i++)
	{
		if(v[b[i]])
		{
			food[c[i]]=true;
		}
	}
	
	memset(vv,true,sizeof(vv));
	for(int i=0;i<=k;i++)
	{
		if(v[i])
		{
			continue;
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j]==i && !food[c[j]])
			{
				vv[i]=false;
				break;
			}
		}
	}
	
	ans=(1<<k)-n;
	cnt=1<<k;
	cnt--;
	
	for(unsigned long long i=1;i<=cnt;i++)
	{
		if(!check(i))
		{
			ans--;
		}
	}
	
	printf("%lld",ans);
	
	return 0;
}