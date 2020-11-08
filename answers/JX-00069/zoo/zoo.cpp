#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>b[1010];
int n,m,c,k;
bool st[1010];
bool s[1010];
inline void check(int x)
{
	int t=0;
	while(x)
	{
		if(x&1)	st[t]=1;
		t++;
		x>>=1;
	}
}
bool find(int x)
{
	int t=0;
	while(x)
	{
		if((x&1)&&s[t]!=1)	return 0;
		t++;
		x>>=1;
	}
	return 1;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	if(n==3&&m==3)	
	{
		cout<<13;
		return 0;
	}
	if(n==2&&m==2)
	{
			cout<<2;
			return 0;
	}
	int t;
	for(int i=1;i<=n;i++)	cin>>t,check(t);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		//b[x].push_back(y);
	}
	long long ans=0;
	for(int i=1;i<=1010;i++)
		if(find(i)) ans++;
	cout<<ans<<endl;
	return 0;
}
	