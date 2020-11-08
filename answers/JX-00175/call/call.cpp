#include<bits/stdc++.h>
using namespace std;
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
const int N=1e5+5;
const int mod=998244353;

int n,cnt,cnt1;
int m,Q;
long long a[N];
struct fun
{
	int val,pos,sum;
}e[N];
int p[1005][100];
void work1(int i)
{
	a[e[i].pos]=(a[e[i].pos]+e[i].sum)%mod;
}
void work2(int i)
{
	for(int j=1;j<=n;j++)
		a[j]=(a[j]*e[i].pos)%mod;
}
void work3(int i)
{
	for(int j=1;j<=p[e[i].pos][0];j++)
	{
		int cc=p[e[i].pos][j];
		if(e[cc].val==1) work1(cc); 
		if(e[cc].val==2) work2(cc);
		if(e[cc].val==3) work3(cc);
	}
}
void solve1()
{
	m=read();
	for(int i=1;i<=m;i++)
	{
		e[++cnt].val=read();
		int cc=e[cnt].val;
		if(cc==1) 
		{
			e[cnt].pos=read();
			e[cnt].sum=read();
		}
		if(cc==2) 
			e[cnt].pos=read();
		if(cc==3){
			e[cnt].pos=++cnt1;
		    p[cnt1][0]=read();
			for(int i=1;i<=p[cnt1][0];i++)
				p[cnt1][i]=read();
			}
	}
	Q=read();
	for(int i=1;i<=Q;i++)
	{
		int cc=read();
		if(e[cc].val==1) work1(cc); 
		if(e[cc].val==2) work2(cc);
		if(e[cc].val==3) work3(cc);
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",a[i]);
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	solve1();
	return 0;
}