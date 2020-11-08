#include<cstdio>
#include<vector>
#define int ll
#define ls p<<1
#define rs p<<1|1
typedef long long ll;
int n;
std::vector<int> vec[100005];
int tag[4000005],sum[4000005];
int a[100005],op[100005],v[100005],p[100005];
inline int read() {
	register int x=0,f=1;register char s=getchar();
	while(s>'9'||s<'0') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=x*10+s-'0';s=getchar();}
	return x*f;
}
inline void pushup(int p) {sum[p]=sum[ls]+sum[rs];}
inline void build(int p,int l,int r) {
	sum[p]=0; tag[p]=1;
	if(l==r) return;
	int mid=l+r>>1;
	build(ls,l,mid); build(rs,mid+1,r);
}
inline void spread(int p) {
	if(tag[p]!=1) {
		sum[ls]*=tag[p];
		sum[rs]*=tag[p];
		tag[ls]*=tag[p];
		tag[rs]*=tag[p];
		tag[p]=1;
	}
}
inline void change(int p,int l,int r,int x,int val) {
	if(l==r) {sum[p]+=val;return;}
	int mid=l+r>>1;
	spread(p);
	if(x<=mid) change(ls,l,mid,x,val);
	else change(rs,mid+1,r,x,val);
	pushup(p);
}
inline void dfs(int x) {
	if(op[x]!=3) {
		if(op[x]==1) change(1,1,n,p[x],v[x]);
		else tag[1]*=v[x],sum[1]*=v[x];	
		return;		
	}
	for(register int i=0;i<vec[x].size();++i) {
		int y=vec[x][i];
		dfs(y);
	}
}
inline int ask(int p,int l,int r,int x) {
	if(l==r) return sum[p];
	spread(p);
	int mid=l+r>>1;
	if(x<=mid) return ask(ls,l,mid,x);
	return ask(rs,mid+1,r,x);
}
signed main() {
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	build(1,1,n);
	for(register int i=1;i<=n;++i) {
		a[i]=read();
		change(1,1,n,i,a[i]);
	}
	int m=read();
	for(register int i=1;i<=m;++i) {
		op[i]=read();
		if(op[i]==1) {
			p[i]=read();v[i]=read();
		}
		else if(op[i]==2) {
			v[i]=read();
		}
		else {
			int k=read();	
			for(register int j=1;j<=k;++j) vec[i].push_back(read());
		}		
	}
	int Q=read();
	while(Q--) {
		int x=read();
		dfs(x);
	}
	for(register int i=1;i<=n;++i) printf("%lld ",ask(1,1,n,i));
	return 0;
}
