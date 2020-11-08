#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#define N 100010
#define M 1000010
using namespace std;

int n,a[N],m;
int head[N],cnt=0;
vector<pair<int,int> >v[N];
struct Edge{
	int nxt,to;
}ed[M];

int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9') f=(c=='-')?-1:1,c=getchar();
	while(c>='0' && c<='9') x=x*10+c-48,c=getchar();
	return x*f;
}

void add(int u,int v){
	ed[++cnt]=(Edge){head[u],v};
	head[u]=cnt;
	return;
}

int ru[N],s[N],tot=0;
queue<int>q;

void topo(){
	for(int i=1;i<=m;i++)
		if(!ru[i]) q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		s[++tot]=u;
		for(int i=head[u];i;i=ed[i].nxt){
			int v=ed[i].to;
			if(!--ru[v]) q.push(v);
		}
	}
	return;
}

void merge(int x,int y){
	for(int i=0;i<(int)v[y].size();i++)
		v[x].push_back(v[y][i]);
	return;
}

void work(){
	int q=read();
	for(int i=1;i<=q;i++){
		int x=read();
		for(int j=(int)v[x].size();j>=0;j--){
			int A=v[x][j].first,B=v[x][j].second;
			printf("%d %d %d\n",i,A,B);
			if(A==-1){for(int k=1;k<=n;k++) a[k]*=B;}
			else a[A]+=B;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	return;
}

int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	m=read();
	for(int i=1;i<=m;i++){
		int typ=read();
		if(typ==1){int x=read(),y=read();v[i].push_back(make_pair(x,y));}
		else if(typ==2){int x=read();v[i].push_back(make_pair(-1,x));}
		else{
			int p=read();
			for(int j=1;j<=p;j++){
				int x=read();
				add(i,x);++ru[x];
			}
		}
	}
	topo();
	for(int i=tot;i>=1;i--){
		int u=s[i];
		for(int j=head[u];j;j=ed[j].nxt){
			int v=ed[j].to;
			merge(u,v);
		}
	}
	work();
	fclose(stdin);fclose(stdout);
	return 0;
}
