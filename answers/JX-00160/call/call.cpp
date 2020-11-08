#include<bits/stdc++.h>
#define IL inline
#define LL long long
#define pb push_back
using namespace std;
const int N=1e5+3,p=998244353;
int n,m,q,num,cnt,ls[N*400],rs[N*400],add[N*400],mul[N*400];
int deg[N],sta[N],fir[N],a[N];
vector<int>E[N];
struct hh{
	int to,nxt;
	}e[N<<1];
IL int in(){
	char c;int f=1;
	while((c=getchar())<'0'||c>'9')
		if(c=='-') f=-1;
	int x=c-'0';
	while((c=getchar())>='0'&&c<='9')
		x=x*10+c-'0';
	return x*f;
	}
IL int mod(int x){return x>=p?x-p:x;}
IL void link(int x,int y){e[++num]=(hh){y,fir[x]},fir[x]=num;}
IL int ksm(int a,int b){
	int c=1;
	while(b){
		if(b&1)  c=1ll*c*a%p;
		a=1ll*a*a%p,b>>=1;
		}
	return c;
	}
struct segment{
	int rt;
	void new_node(int &o){mul[o=++cnt]=1;}
	IL void pudn(int k){
		if(!ls[k]) new_node(ls[k]);
		if(!rs[k]) new_node(rs[k]);
		mul[ls[k]]=1ll*mul[ls[k]]*mul[k]%p;
		mul[rs[k]]=1ll*mul[rs[k]]*mul[k]%p;
		if(add[ls[k]]) add[ls[k]]=1ll*add[ls[k]]*mul[k]%p;
		if(add[rs[k]]) add[rs[k]]=1ll*add[rs[k]]*mul[k]%p;
		mul[k]=1;
		}
	void upd1(int &o,int l,int r,int u,int v){
		if(!o) new_node(o);
		if(l==r){add[o]=mod(add[o]+v);return;}
		int mid=l+r>>1;
		if(u<=mid) upd1(ls[o],l,mid,u,v);
		else upd1(rs[o],mid+1,r,u,v);
		}
	void upd2(int &o,int v){
		if(!o) new_node(o);
		mul[o]=1ll*mul[o]*v%p;
		if(add[o]) add[o]=1ll*add[o]*v%p;
		}
	void merge(int &o,int p1,int p2,int l,int r,int mu){
		if(!p1||!p2){o=p1+p2;return;}
		new_node(o);
		mul[o]=1ll*mul[p1]*mul[p2]%p;
		//add[o]=mod(add[p2]+1ll*mul[p2]*add[p1]%p);
		//cout<<l<<' '<<r<<' '<<mul[p1]<<' '<<mul[p2]<<'  '<<add[p1]<<' '<<add[p2]<<endl;
		if(l==r){add[o]=mod(1ll*add[p2]*ksm(mu,p-2)%p+1ll*add[p1]*mul[p2]%p);return;}
		int mid=l+r>>1;
		merge(ls[o],ls[p1],ls[p2],l,mid,1ll*mu*mul[p1]),
		merge(rs[o],rs[p1],rs[p2],mid+1,r,1ll*mu*mul[p1]);
		}
	}T[N],t0,t1;
void topo(){
	for(int i=1;i<=n;++i) if(!deg[i]) sta[++sta[0]]=i;
	while(sta[0]){
		int  u=sta[sta[0]--];
		for(int i=fir[u],v;v=e[i].to;i=e[i].nxt)
			if(!--deg[v]) sta[++sta[0]]=v;
		for(int i=0;i<E[u].size();++i) T[u].merge(T[u].rt,T[u].rt,T[E[u][i]].rt,1,n,1);
		}
	}
void print(int o,int l,int r){
	//cout<<o<<' '<<l<<' '<<r<<' '<<mul[o]<<' '<<add[o]<<endl;
	if(l==r){printf("%d ",mod(add[o]+1ll*a[l]*mul[o]%p));return;}
	int mid=l+r>>1;t0.pudn(o);
	print(ls[o],l,mid),print(rs[o],mid+1,r);
	}
int main(){
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int op,x,y,z,p,v;
	n=in();
	for(int i=1;i<=n;++i) a[i]=in();
	m=in();
	for(int i=1;i<=m;++i){
		op=in();
		if(op==1){p=in(),v=in(),T[i].upd1(T[i].rt,1,n,p,v);}
		else if(op==2){v=in(),T[i].upd2(T[i].rt,v);}
		else{
			int k=in();deg[i]=k;
			for(int j=1;j<=k;++j)
				x=in(),link(x,i),E[i].pb(x);
			}
		}
	q=in();
	for(int i=1;i<=q;++i) x=in(),t0.merge(t0.rt,t0.rt,T[x].rt,1,n,1);
	print(t0.rt,1,n);
	return 0;
	}