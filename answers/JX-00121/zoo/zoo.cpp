#include<bits/stdc++.h>
using namespace std;
#define R register
#define ll long long
inline ll read()
{
	ll x=0;bool f=0;char s=getchar();
	while(s>'9'||s<'0') {if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<1)+(x<<3)+(ll)s-'0';s=getchar();}
	return f?-x:x;
} 
const int N=2e6;
int n,m,c,k,cnt;
ll C[101][101];
ll cl(int l)
{
	C[1][0]=C[1][1]=1;
	for(R int i=2;i<=l;i++)
		for(R int j=1;j<=i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	ll sum=0;
	for(int i=1;i<=l;i++)
		sum+=C[l][i];
	return sum;
}
ll p[N];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	ll q=0;p[0]=1;
	for(R int i=1;i<=k;i++) p[i]=p[i-1]*2;
	for(R int i=1;i<=n;i++) 
	{
		ll a=read();
		q|=a;
	}
	for(R int i=1;i<=m;i++)
	{
		ll x=read(),y=read();
		if(q&(1<<x)||x>k+1) continue;
		cnt++;
	}
	printf("%lld",cl(k-cnt+1)-n);
	return 0;
}