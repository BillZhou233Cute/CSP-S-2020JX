#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int mod=998244353;
struct func
{
	int c,add,pos,mul,t;
	vector<int> fc;
}f[100005];
int n;
long long add[100005],mul[100005],a[100005];
void fadd(int k)
{
	int p=f[k].pos;
	add[p]+=f[k].add;
}
void times(int k)
{
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i]*mul[i]%mod;
		a[i]+=add[i];
		add[i]=0;
		mul[i]=1;
		mul[i]=f[k].mul;
	}
}
void work(int k)
{
	if(f[k].t==1) fadd(k);
	if(f[k].t==2) times(k);
	if(f[k].t==3) for(int i=0;i<f[k].c;i++) work(f[k].fc[i]);
}
int main()
{
	int m,q,fun,t;
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),mul[i]=1;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&f[i].t);
		if(f[i].t==1) scanf("%d%d",&f[i].pos,&f[i].add);
		if(f[i].t==2) scanf("%d",&f[i].mul);
		if(f[i].t==3)
		{
			scanf("%d",&f[i].c);
			for(int j=1;j<=f[i].c;j++)
			{
				scanf("%d",&fun);
				f[i].fc.push_back(fun);
			}
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&t);
		if(f[t].t==1) fadd(t);
		if(f[t].t==2) times(t);
		if(f[t].t==3) work(t);
	}
	for(int i=1;i<=n;i++) printf("%lld ",(a[i]*mul[i]%mod+add[i])%mod);
	return 0;
}
