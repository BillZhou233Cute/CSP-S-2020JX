#include<bits/stdc++.h>
using namespace std;
#define ll long long
int read()
{
	int ans=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') 
	{
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
const int N=1e6+5;
ll n,m,c,k; 
ll x,a[N],v[N];
ll T,Q,R,C,ans,cc;
int ask(ll x)
{
	int y=0;
	while(x)
	{
		if(x%2) y++;
		x>>=1;
	}
	return y;
}
void work1()
{
	for(int i=1;i<=n;i++)
	a[i]=read(),T|=a[i];
	for(int i=1;i<=m;i++)
	{
		v[i]=read();
		x=read();
		Q|=(1<<v[i]);
	}
	C=T&Q;R=Q^C;
	ans=(1<<(k-ask(R)))-n;
	printf("%lld",ans);
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	work1();
	return 0;
}