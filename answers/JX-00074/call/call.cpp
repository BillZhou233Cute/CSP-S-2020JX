#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ls (p<<1)
const int N=1e5+5,mod=998244353;
LL Q,n,a[N],m,pos[N],val[N],opt[N],cnt[N];
vector<int> g[N];

inline LL read()
{
	register LL x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) f^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return f ? x:-x;
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	m=read();
	for(int i=1;i<=n;++i)
	{
		opt[i]=read();
		if(opt[i]==1) pos[i]=read(),val[i]=read();
		else if(opt[i]==2) val[i]=read();
		else
		{
			cnt[i]=read();
			for(int j=1;j<=cnt[i];++j) g[i].push_back(read());
		}
	}
	
	Q=read();
	for(int m=1,i;m<=Q;++m)
	{
		i=read();
		if(opt[i]==1) a[pos[i]]=(a[pos[i]]+val[i])%mod;
		else if(opt[i]==2)
		{
			for(int j=1;j<=n;++j) a[j]=(a[j]*val[i])%mod;
		}
		else
		{
			for(int j=0;j<cnt[i];++j)
			{
				int k=g[i][j];
				if(opt[k]==1) a[pos[k]]=(a[pos[k]]+val[k])%mod;
				else if(opt[k]==2)
				{
					for(int l=1;l<=n;++l) a[l]=(a[l]*val[k])%mod;
				}
				
			}
		}
	}
	
	for(int i=1;i<=n;++i) printf("%lld ",a[i]);
	
	return 0;
}
