#include<bits/stdc++.h>
#define MAXN 100010
#define MOD 998244353
using namespace std;
inline long long read(){
	char c=getchar();long long f=1,x=0;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f*x;
}
long long n,m,c,k,d[MAXN],vis[MAXN],Q,f1,sum=1;
struct node{
	int u,x;
}no[MAXN];
vector<int>edge[MAXN];
void dfs(int u){
	if(vis[u]){
			if(no[u].u==0)
				for(int i=1;i<=n;i++)d[i]=d[i]*no[u].x%MOD;
			else d[no[u].u]=d[no[u].u]+no[u].x%MOD;
		}
		for(int i=0;i<edge[u].size();i++)
			dfs(edge[u][i]);
			}
void dfs1(int u){
	if(vis[u])
		sum=sum*no[u].x%MOD;
	for(int i=0;i<edge[u].size();i++)
		dfs1(edge[u][i]);
}
void work1(){
	while(Q--){dfs1(read());}
	for(int i=1;i<=n;i++)printf("%lld",d[i]*sum%MOD);
	}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)d[i]=read();
	m=read();
	for(int i=1;i<=m;i++){
		int q=read();
		if(q==1){vis[i]=1;no[i].u=read();no[i].x=read();f1=1;}
		else if(q==2){vis[i]=1;no[i].x=read();}
		else{
			int c=read();
			for(int j=1;j<=c;j++)
				edge[i].push_back(read());
		}
	}
	Q=read();
	if(f1==0)work1();
	else {
		while(Q--){dfs(read());}
	for(int i=1;i<=n;i++)printf("%lld ",d[i]);
	}
	return 0;
}
