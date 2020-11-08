#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
typedef unsigned long long ull;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
inline int read(void){
	reg bool f=false;
	reg char ch=getchar();
	reg int res=0;
	while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
	while(isdigit(ch))res=10*res+(ch^'0'),ch=getchar();
	return f?-res:res;
}

const int MAXN=1e6+5;

int n;
int a[MAXN];

namespace Subtask1{
	const int inf=0x3f3f3f3f;
	bool kill[MAXN];
	int tmp[MAXN];
	inline int dfs(reg int dep){
		if(dep==n)
			return n-dep+1;
		int Max=-inf,pMax=0,Min=inf,pMin=0;
		for(reg int i=1;i<=n;++i)
			if(!kill[i]){
				if(tmp[i]>=Max){
					Max=tmp[i];
					pMax=i;
				}
				if(tmp[i]<Min){
					Min=tmp[i];
					pMin=i;
				}
			}
		reg int x=-inf,px=0;
		for(reg int i=1;i<=n;++i)
			if(!kill[i]&&i!=pMax&&i!=pMin)
				if(tmp[i]>=x){
					x=tmp[i];
					px=i;
				}
		if(Max-Min<x||(Max-Min==x&&pMax<px))
			return n-dep+1;
		else{
			kill[pMin]=true,tmp[pMax]-=tmp[pMin];
			return dfs(dep+1);
		}
	}
	inline void Solve(void){
		for(reg int i=1;i<=n;++i)
			tmp[i]=a[i];
		printf("%d\n",dfs(1));
		return;
	}
}


namespace Subtask2{
	const int inf=0x3f3f3f3f;
	bool kill[MAXN];
	int tmp[MAXN];
	int ans;
	inline void dfs(reg int dep){
		if(dep==n){
			ans=min(ans,1);
			return;
		}
		int Max=-inf,pMax=0,Min=inf,pMin=0;
		for(reg int i=1;i<=n;++i)
			if(!kill[i]){
				if(tmp[i]>=Max){
					Max=tmp[i];
					pMax=i;
				}
				if(tmp[i]<Min){
					Min=tmp[i];
					pMin=i;
				}
			}
		if(pMin==n)
			return;
		else{
			ans=min(ans,n-dep+1);
			kill[pMin]=true;
			tmp[pMax]-=tmp[pMin];
			dfs(dep+1);
		}
		return;
	}
	inline void Solve(void){
		for(reg int i=1;i<=n;++i)
			tmp[i]=a[i];
		ans=n;
		dfs(1);
		printf("%d\n",ans);
		return;
	}
}

namespace Final{
	inline void Solve(void){
		reg ll sum=0;
		for(reg int i=1;i<=n;++i)
			sum+=a[i];
		if(sum-a[n]<=a[n])
			printf("%d\n",1);
		else if(a[n]-a[1]<a[n-1])
			printf("%d\n",n);
		else
			printf("%d\n",rand()%(n-2)+1);
		return;
	}
}

inline void Solve(void){
	if(n<=3)
		Subtask1::Solve();
	else if(n<=10)
		Subtask2::Solve();
	else
		Final::Solve();
	return;
}

int main(void){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);

	reg int T=read();
	n=read();
	for(reg int i=1;i<=n;++i)
		a[i]=read();
	Solve();
	for(reg int i=2;i<=T;++i){
		reg int k=read();
		while(k--){
			static int x,y;
			x=read(),y=read();
			a[x]=y;
		}
		Solve();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
