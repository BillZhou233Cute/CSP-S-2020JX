#include<cstdio>
#include<algorithm>
typedef long long ll;
ll a[1000005];
inline int read() {
	register int x=0,f=1;register char s=getchar();
	while(s>'9'||s<'0') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=x*10+s-'0';s=getchar();}
	return x*f;
}
inline bool check(int n,int k) {
	ll sum=0;
	for(register int i=1;i<=k;++i) {
		sum+=a[i];
		int pos=std::upper_bound(a+1,a+1+n,a[n]-sum)-a;
		if(pos<n&&a[pos]>a[n]-sum) return 0; 
	}
	return 1;
}
inline void work(int n) {
	int l=0,r=n-1,res=0;
	while(l<=r) {
		int mid=l+r>>1;
		if(check(n,mid)) l=mid+1,res=mid;
		else r=mid-1;
	}
	printf("%d\n",n-res);
}
signed main() {
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T=read()-1,n=read();
	for(register int i=1;i<=n;++i) a[i]=read();
	work(n); //printf("chk=%d\n",check(n,0));
	while(T--) {
		int k=read();
		for(register int i=1;i<=k;++i) {
			int x=read(),y=read();
			a[x]=y;
		}
//		for(register int i=1;i<=n;++i) printf("%d ",a[i]); printf("\n");
		work(n);
		//printf("%d\n",check(n,2));
	}
	return 0;
}
