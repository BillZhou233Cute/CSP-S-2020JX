#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e6+5,M=64+5;
struct node {
	int p,q;
}fed[N];
int n,m,c,k,a[N],ls[N],ans;
bool vis[M],tag[N],isq[M];

inline int read () {
	int res=0,fl=1;
	char ch;
	while ((ch=getchar())&&(ch<'0'||ch>'9'))	if (ch=='-') fl=-1;
	res=ch^48;
	while ((ch=getchar())&&ch>='0'&&ch<='9')	res=(res<<1)+(res<<3)+(ch^48);
	return res*fl;
}

signed main () {
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read();m=read();c=read();k=read();
//	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=n;i++) {
		a[i]=read();
		for (int j=0;j<=64;j++)
			if (a[i]&(1ll<<j))	vis[j]=1;
	}
	for (int i=1;i<=m;i++) {
		fed[i].p=read();fed[i].q=read();
		ls[i]=fed[i].q;isq[fed[i].p]=1;
	}
	sort(ls+1,ls+m+1);
	int tot=unique(ls,ls+m+1)-ls-1;
	for (int i=1;i<=m;i++) {
		fed[i].q=lower_bound(ls+1,ls+tot+1,fed[i].q)-ls;
		if (vis[fed[i].p])	tag[fed[i].q]=1;
	}
	for (int i=1;i<=m;i++) if (tag[fed[i].q]) vis[fed[i].p]=1;
	for (int i=0;i<=k-1;i++) if (vis[i]||!isq[i])	ans++;
	ans=(1ll<<ans);
	printf("%lld\n",ans-n);
	return 0;
}
