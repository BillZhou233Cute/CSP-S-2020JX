#include<cstdio>
#include<cstring>
#include<vector>
#define N 1000005
using namespace std;
inline int lowbit(int x){return x&(-x);}
inline int log(int x){
	int ans=0;
	while(x>1) ans++,x>>=1;
	return ans;
}
bool have[N];
int n,m,c,k,a[N],q,p,ans;
vector <int> G[N];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w".stdout);
	scanf("%d%d%d%d",&n,&m,&q,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&p,&q);
		G[p].push_back(q);
	}
	for(int i=1;i<=n;i++){
		int now=a[i];
		while(now){
			int last=log(lowbit(now));
			for(int j=0;j<G[last].size();j++)
				have[G[last][j]]=true;
			now-=lowbit(now);
		}
	}
	for(int i=0;i<(1<<k);i++){
		int now=i;
		while(now){
			int last=log(lowbit(now));
			for(int j=0;j<G[last].size();j++)
				if(!have[G[last][j]]){ans--;break;}
			now-=lowbit(now);
		}
		ans++;
	}
	printf("%d\n",ans-n);
	return 0;
}
