#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
struct node {
	int opt,x,y;
}q[100010];
struct line {
	int x;
	long long val;
};
int n,m,Q,f[1000010],b[1000010],cnt[100010];
vector<line> G[100010];
long long sum[100010],s[100010],tot=1,a[1000010],kpl[100010],TS[100010];
long long poww(long long x,long long y) {
	long long res=1;
	while(y) {
		if(y&1) res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
int main()
{
freopen("call.in","r",stdin);
freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	scanf("%d",&m);
	for(int i=1,x;i<=m;i++) {
		scanf("%d",&q[i].opt);
		if(q[i].opt==1) scanf("%d%d",&q[i].x,&q[i].y);
		else if(q[i].opt==2) scanf("%d",&q[i].x);
		else if(q[i].opt==3){
			scanf("%d",&cnt[i]);
			sum[i]=1;
			for(int j=1;j<=cnt[i];j++) {
				scanf("%d",&b[j]);
				if(q[b[j]].opt==2) sum[i]=(sum[i]*q[b[j]].x)%mod;
			}
			long long res=1;
			for(int j=1;j<=cnt[i];j++) {
				if(q[b[j]].opt==2) res=(res*q[b[j]].x)%mod;
				else G[i].push_back((line){q[b[j]].x,1ll*q[b[j]].y*sum[n]%mod*poww(res,mod-2ll)%mod});
			}
		}
	}
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++) {
		scanf("%d",&f[i]);
		if(q[f[i]].opt==2) tot=(tot*q[f[i]].x)%mod;
		else if(q[f[i]].opt==3) tot=(tot*sum[f[i]])%mod;
		TS[i]=tot;
	}
	for(int i=1;i<=n;i++) a[i]=(a[i]*tot)%mod;
	long long res=1;
	for(int i=1;i<=Q;i++) {
		if(q[f[i]].opt==1) a[q[f[i]].x]=(a[q[f[i]].x]+q[f[i]].y*tot*poww(res,mod-2ll)%mod)%mod;
		else if(q[f[i]].opt==3) {
			kpl[f[i]]=(kpl[f[i]]+TS[Q]*poww(TS[i],mod-2ll)%mod)%mod;
		}
	}
	for(int i=1;i<=m;i++) {
		if(q[i].opt!=3) continue;
		for(int j=0,x,y;j<G[i].size();j++) {
			x=G[i][j].x,y=G[i][j].val;
			a[x]=(a[x]+y*kpl[i]%mod)%mod;
		}
	}
	for(int i=1;i<=n;i++) printf("%lld ",a[i]%mod);
	return 0;
}
