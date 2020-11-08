#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=1e6+10;
inline void rd(int &x){
	x=0;bool flag=0;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){flag=1;ch=getchar();};
	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
	if(flag)x=-x;
}
inline void rd(ll &x){
	x=0;bool flag=0;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){flag=1;ch=getchar();};
	while(ch>='0'&&ch<='9')x=x*10ll+(ch-'0'),ch=getchar();
	if(flag)x=-x;
}
inline void rd(ull &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10ull+(ch-'0'),ch=getchar();
}
int n,m,c,k;
ull sum,x;
int a[N],b[N];
int in[N];
vector<int>V[N];
vector<int>E[N];
int q[N],cnt;
bool vis[N];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	rd(n);rd(m);rd(c);rd(k);sum=0ull;
	for(int i=1;i<=n;++i){rd(x);sum|=x;};
	for(int i=1;i<=m;++i){
		rd(a[i]);rd(b[i]);
		++in[a[i]];
		q[++cnt]=b[i];
	}sort(q+1,q+1+cnt);
	cnt=unique(q+1,q+1+cnt)-q-1;
	for(int i=1;i<=m;++i){
		b[i]=lower_bound(q+1,q+1+cnt,b[i])-q;
		V[a[i]].push_back(b[i]);
		E[b[i]].push_back(a[i]);
	}
	ull ans=1ull;
	for(ull i=0;i<k;++i){
		if(sum&(1ull<<i)){
			int siz=V[i].size();
			for(int j=0;j<siz;++j){
				int x=V[i][j];
				if(vis[x])continue;
				vis[x]=1;int si=E[x].size();
				for(int z=0;z<si;++z){
					int y=E[x][z];
					--in[y];
				}
			}
		}
	}
	for(ull i=0;i<k;++i){if(!in[i]){ans<<=1ull;}};
	cout<<ans-n<<endl;
	return 0;
}

