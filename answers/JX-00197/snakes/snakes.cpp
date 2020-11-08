#include<iostream>
#include<cstdio>
using namespace std;
const int N=3e6+5;
int T,n,a[N],b[N],eat[N],ans;

inline int read () {
	int res,fl=1;
	char ch;
	while ((ch=getchar())&&(ch<'0'||ch>'9'))	if (ch=='-')	fl=-1;
	res=ch^48;
	while ((ch=getchar())&&ch>='0'&&ch<='9')	res=(res<<1)+(res<<3)+(ch^48);
	return res*fl;
}

inline void dfs (int tot,int mx,int mn) {
	if (tot==1) {
		ans=1;
		return;
	}
	if (b[mx]-b[mn]<b[mx-1]) {
		ans=tot;
		return;
	} else {
		dfs(tot-1,mx,mn+1);
	}
}

int main () {
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=read();
	for (int rd=1;rd<=T;rd++) {
		if (rd==1) {
			n=read();
			for (int i=1;i<=n;i++)	a[i]=read();
		} else {
			int k=read();
			while (k--) {
				int id=read(),w=read();
				a[id]=w;
			}
		}
		for (int i=1;i<=n;i++)	b[i]=a[i];
//		for (int i=1;i<=n;i++)	cout<<a[i]<<" ";l
		dfs(n,n,1);
		printf("%d\n",ans);
	}
	return 0;
}
