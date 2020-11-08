#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 2005;
int snakes[MAXN],v[MAXN],v2[MAXN];
int t,n,ans,k;

bool dfs(int cnt){
	if(cnt == n-1) {ans = 1;return true;}
	int ansn = 0x3f3f3f3f,ansx = -1,nx,xx;
	for(int i=1;i<=n;i++){
		if(ansn > snakes[i] && !v2[i]) ansn = snakes[i],nx = i;
		if(ansx <= snakes[i] && !v2[i]) ansx = snakes[i],xx = i;
	}
	if(ansx > ansn || (ansx == ansn && xx > nx)){
		if(v[nx]) return false;
		v[xx] = v2[nx] = 1;
		snakes[xx] -= snakes[nx];
		if(!dfs(cnt+1)){
			v[xx] = v2[nx] = 0;
			snakes[xx] += snakes[nx];
		}
	}
	if(ans == 1) return true;
	ans = min(ans,ans-cnt);
	return true;
}

int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	scanf("%d",&n);
	if(n == 3){
		for(int i=1;i<=n;i++) scanf("%d",&snakes[i]);
		if(snakes[2] <= snakes[3] - snakes[1]) printf("1\n");
		else printf("3\n");
		for(int Case=2;Case<=t;Case++){
			scanf("%d",&k);
			for(int i=1;i<=k;i++){
				int a,b;
				scanf("%d %d",&a,&b);
				snakes[a] = b;
			}
			if(snakes[2] <= snakes[3] - snakes[1]) printf("1\n");
			else printf("3\n");
		}
		return 0;
	}
	ans = n;
	for(int i=1;i<=n;i++) scanf("%d",&snakes[i]);
	dfs(0);printf("%d\n",ans);
	for(int Case=2;Case<=t;Case++){
		memset(v,0,sizeof(v));
		memset(v2,0,sizeof(v2));
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			snakes[a] = b;
		}
		ans = n;
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}