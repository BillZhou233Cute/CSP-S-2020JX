#include<bits/stdc++.h>
#define R register int
#define IN inline
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=1e5+5;
ll a[N];
struct node
{
	int type;
	ll p,v;
}opts[N];
vector <int> son[N];
IN int read()
{
	char ch;int f=1;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') f=-1;
	int x=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
int n,m,q;
IN void caozuo(int num)
{
	if(opts[num].type==1)
	{
		ll pos=opts[num].p;
		a[pos]=(a[pos]+opts[num].v)%mod;
		return ;
	}
	if(opts[num].type==2)
	{
		for(R i=1;i<=n;i++)
		 a[i]=(a[i]*opts[num].v%mod)%mod;
		return ;
	}
	if(opts[num].type==0)
	 for(R i=0;i<son[num].size();i++)
		caozuo(son[num][i]);
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(R i=1;i<=n;i++) a[i]=(ll) read();
	m=read();
	for(R i=1;i<=m;i++)
	{
		int type=read();
		if(type==1) 
		{
			ll p=(ll) read(),v=(ll) read();
			opts[i]=(node){type,p,v};
		}
		else if(type==2)
		{
			ll v=read();
			opts[i].type=2;
			opts[i].v=v;
		}
		else
		{
			opts[i].type=0;
			int cc=read();
			for(R j=1;j<=cc;j++) son[i].push_back(read());
		}
	}
	int len=read();
	for(R i=1;i<=len;i++) caozuo(read());
	for(R i=1;i<=n;i++) printf("%lld ",a[i]);
	return 0;
}
