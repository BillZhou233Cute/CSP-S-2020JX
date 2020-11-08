#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
typedef unsigned long long ull;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
inline int read(void){
	reg bool f=false;
	reg char ch=getchar();
	reg int res=0;
	while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
	while(isdigit(ch))res=10*res+(ch^'0'),ch=getchar();
	return f?-res:res;
}

const int MAXN=1e5+5;
const int MAXM=1e5+5;
const int MAXQ=1e5+5;
const int MAXC=1e6+5;
const int p=998244353;
const int MAXV=MAXM;
const int MAXE=MAXC;

struct Operation{
	int type,p,v;
};

int n,m,q;
int a[MAXN];
Operation op[MAXM];
vector<int> G[MAXV];
int f[MAXQ];
int inDeg[MAXV];

inline void Add_Edge(reg int u,int v){
	G[u].push_back(v);
	/*
	Next[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
	*/
	return;
}

namespace Subtask1{
	const int MAXN=1e3+5;
	inline int add(reg int a,reg int b){
		reg int sum=a+b;
		return sum>=p?sum-p:sum;
	}
	inline int mul(reg int a,reg int b){
		return 1ll*a*b%p;
	}
	namespace SegmentTree{
		#define lson ( (k) << 1 )
		#define rson ( (k) << 1 | 1 )
		#define mid ( ( (l) + (r) ) >> 1 )
		struct Node{
			int val;
			int tag;
			#define val(x) unit[(x)].val
			#define tag(x) unit[(x)].tag
		};
		Node unit[MAXN<<2];
		inline void build(reg int k,reg int l,reg int r,reg int a[]){
			tag(k)=1;
			if(l==r){
				val(k)=a[l];
				return;
			}
			build(lson,l,mid,a),build(rson,mid+1,r,a);
			return;
		}
		inline void Mul(reg int k,reg int val){
			val(k)=mul(val(k),val);
			tag(k)=mul(tag(k),val);
			return;
		}
		inline void pushdown(reg int k){
			if(tag(k)!=1){
				Mul(lson,tag(k));
				Mul(rson,tag(k));
				tag(k)=1;
			}
			return;
		}
		inline void Add(reg int k,reg int l,reg int r,reg int pos,reg int Val){
			if(l==r){
				val(k)=add(val(k),Val);
				return;
			}
			pushdown(k);
			if(pos<=mid)
				Add(lson,l,mid,pos,Val);
			else
				Add(rson,mid+1,r,pos,Val);
			return;
		}
		inline void print(reg int k,reg int l,reg int r){
			if(l==r){
				printf("%d%c",val(k),l==n?'\n':' ');
				return;
			}
			pushdown(k);
			print(lson,l,mid),print(rson,mid+1,r);
			return;
		}
		#undef lson
		#undef rson
		#undef mid
	}
	inline void Call(reg int id){
		reg int t=op[id].type;
		switch(t){
			case 1:{
				reg int p=op[id].p;
				SegmentTree::Add(1,1,n,p,op[id].v);
				break;
			}
			case 2:{
				SegmentTree::Mul(1,op[id].v);
				break;
			}
			case 3:{
				for(reg int i=0,siz=G[id].size();i<siz;++i)
					Call(G[id][i]);
				break;
			}
		}
		return;
	}
	inline void Solve(void){
		SegmentTree::build(1,1,n,a);
		for(reg int i=1;i<=q;++i)
			Call(f[i]);
		SegmentTree::print(1,1,n);
		/*for(reg int i=1;i<=n;++i)
			printf("%d%c",a[i],i==n?'\n':' ');*/
		return;
	}
}

namespace Subtask2{
	const int MAXN=1e5+5;
	inline int add(reg int a,reg int b){
		reg int sum=a+b;
		return sum>=p?sum-p:sum;
	}
	inline int mul(reg int a,reg int b){
		return 1ll*a*b%p;
	}
	namespace SegmentTree{
		#define lson ( (k) << 1 )
		#define rson ( (k) << 1 | 1 )
		#define mid ( ( (l) + (r) ) >> 1 )
		struct Node{
			int val;
			int tag;
			#define val(x) unit[(x)].val
			#define tag(x) unit[(x)].tag
		};
		Node unit[MAXN<<2];
		inline void build(reg int k,reg int l,reg int r,reg int a[]){
			tag(k)=1;
			if(l==r){
				val(k)=a[l];
				return;
			}
			build(lson,l,mid,a),build(rson,mid+1,r,a);
			return;
		}
		inline void Mul(reg int k,reg int val){
			val(k)=mul(val(k),val),tag(k)=mul(tag(k),val);
			return;
		}
		inline void pushdown(reg int k){
			if(tag(k)!=1){
				Mul(lson,tag(k)),Mul(rson,tag(k));
				tag(k)=1;
			}
			return;
		}
		inline void Add(reg int k,reg int l,reg int r,reg int pos,reg int Val){
			if(l==r){
				val(k)=add(val(k),Val);
				return;
			}
			pushdown(k);
			if(pos<=mid)
				Add(lson,l,mid,pos,Val);
			else
				Add(rson,mid+1,r,pos,Val);
			return;
		}
		inline void print(reg int k,reg int l,reg int r){
			if(l==r){
				printf("%d%c",val(k),l==n?'\n':' ');
				return;
			}
			pushdown(k);
			print(lson,l,mid),print(rson,mid+1,r);
			return;
		}
		#undef lson
		#undef rson
		#undef mid
	}
	inline void Call(reg int id){
		reg int t=op[id].type;
		switch(t){
			case 1:{
				reg int p=op[id].p;
				SegmentTree::Add(1,1,n,p,op[id].v);
				break;
			}
			case 2:{
				SegmentTree::Mul(1,op[id].v);
				break;
			}
			case 3:{
				for(reg int i=0,siz=G[id].size();i<siz;++i)
					Call(G[id][i]);
				break;
			}
		}
		return;
	}
	inline void Solve(void){
		SegmentTree::build(1,1,n,a);
		for(reg int i=1;i<=q;++i)
			Call(f[i]);
		SegmentTree::print(1,1,n);
		return;
	}
}

namespace Subtask3mul{
	const int MAXN=1e5+5;
	inline int mul(reg int a,reg int b){
		return 1ll*a*b%p;
	}
	int tagMul[MAXV];
	inline void dfs(reg int u){
		if(op[u].type==2)
			tagMul[u]=op[u].v;
		else{
			tagMul[u]=1;
			for(reg int i=0,siz=G[u].size();i<siz;++i){
				reg int v=G[u][i];
				dfs(v);
				tagMul[u]=mul(tagMul[u],tagMul[v]);
			}
		}
		return;
	}
	inline void Solve(void){
		for(reg int i=1;i<=m;++i)
			if(!inDeg[i])
				dfs(i);
		reg int tag=1;
		for(reg int i=1;i<=q;++i)
			tag=mul(tag,tagMul[f[i]]);
		for(reg int i=1;i<=n;++i)
			printf("%d%c",mul(tag,a[i]),i==n?'\n':' ');
		return;
	}
}

namespace Subtask3add{
	const int MAXN=1e5+5;
	inline int add(reg int a,reg int b){
		reg int sum=a+b;
		return sum>=p?sum-p:sum;
	}
	inline int mul(reg int a,reg int b){
		return 1ll*a*b%p;
	}
	int cnt[MAXN];
	queue<int> Q;
	inline void Solve(void){
		for(reg int i=1;i<=q;++i)
			++cnt[f[i]];
		for(int i=1;i<=m;++i)
			if(!inDeg[i]&&cnt[i]&&op[i].type==3)
				Q.push(i);
		while(!Q.empty()){
			reg int u=Q.front();
			Q.pop();
			for(reg int i=0,siz=G[u].size();i<siz;++i){
				int v=G[u][i];
				--inDeg[v];
				cnt[v]=add(cnt[v],cnt[u]);
				if(!inDeg[v]&&op[v].type==3){
					Q.push(v);
				}
			}
			cnt[u]=0;
		}
		for(reg int i=1;i<=m;++i)
			if(cnt[i]&&op[i].type==1){
				reg int p=op[i].p,v=op[i].v;
				a[p]=add(a[p],mul(cnt[i],v));
			}
		for(reg int i=1;i<=n;++i)
			printf("%d%c",a[i],i==n?'\n':' ');
		return;
	}
}

namespace Subtask4{
	inline int add(reg int a,reg int b){
		reg int sum=a+b;
		return sum>=p?sum-p:sum;
	}
	inline int mul(reg int a,reg int b){
		return 1ll*a*b%p;
	}
	inline int fpow(reg int x,reg int exp){
		reg int res=1;
		while(exp){
			if(exp&1)
				res=mul(res,x);
			x=mul(x,x);
			exp>>=1;
		}
		return res;
	}
	int O[MAXM];
	int tot;
	int lef[MAXM],rig[MAXM];
	inline void dfs(reg int u){
		lef[u]=tot+1;
		if(op[u].type!=3)
			O[++tot]=u;
		else
			for(reg int i=0,siz=G[u].size();i<siz;++i){
				reg int v=G[u][i];
				dfs(v);
			}
		rig[u]=tot;
		return;
	}
	int tagAdd[MAXN],tagMul=1;
	inline void Solve(void){
		int rt=0;
		for(reg int i=1;i<=m;++i)
			if(!inDeg[i])
				rt=i;
		dfs(rt);
		for(reg int i=1;i<=q;++i){
			reg int id=f[i];
			if(op[id].type!=3){
				if(op[id].type==1){
					reg int p=op[id].p,v=op[id].v;
					tagAdd[p]=add(tagAdd[p],mul(v,fpow(tagMul,p-2)));
				}
				else
					tagMul=mul(tagMul,op[id].v);
			}
			else{
				reg int l=lef[id],r=rig[id];
				for(reg int j=l;j<=r;++j){
					reg int x=O[j];
					if(op[x].type==1){
						reg int pos=op[x].p,v=op[x].v;
						tagAdd[pos]=add(tagAdd[pos],mul(v,fpow(tagMul,p-2)));
					}
					if(op[x].type==2){
						tagMul=mul(tagMul,op[x].v);
					}
				}
			}
		}
		for(reg int i=1;i<=n;++i)
			printf("%d%c",mul(tagMul,add(tagAdd[i],a[i])),i==n?'\n':' ');
		return;
	}
}

namespace Final{
	inline void Solve(void){
		for(reg int i=1;i<=n;++i)
			printf("%d%c",a[i],i==n?'\n':' ');
		return;
	}
}

int main(void){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);

	n=read();
	for(reg int i=1;i<=n;++i)
		a[i]=read();
	m=read();
	int sumc=0;
	bool nt1=true,nt2=true;
	for(reg int i=1;i<=m;++i){
		static int t,p,v,c;
		t=read();
		if(t==1){
			p=read(),v=read();
			op[i].type=1,op[i].p=p,op[i].v=v;
			nt1=false;
		}
		else if(t==2){
			v=read();
			op[i].type=2,op[i].v=v;
			nt2=false;
		}
		else{
			c=read();
			op[i].type=3;
			sumc+=c;
			while(c--){
				static int g;
				g=read();
				Add_Edge(i,g);
				++inDeg[g];
			}
		}
	}
	q=read();
	for(reg int i=1;i<=q;++i)
		f[i]=read();
	if(m<=1000)
		Subtask1::Solve(); //bf
	else if(sumc==0)
		Subtask2::Solve(); //sg
	else if(nt1||nt2){
		if(nt1)
			Subtask3mul::Solve(); //dfs
		else
			Subtask3add::Solve(); //bfs
	}
	else if(sumc==m-1) //tree
		Subtask4::Solve();
	else //can't
		exit(0),Final::Solve();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
