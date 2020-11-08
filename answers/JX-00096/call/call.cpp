#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define fopen(X) freopen(#X".in", "r", stdin); freopen(#X".out", "w", stdout);
#define int long long
#define _ 100005
int mod=998244353LL;
void rd(int& x) { scanf("%lld", &x); }
using namespace std;
struct _node_ {
  int t, p, v, m; vector<int> son, mul;
} node[_];
void solve(_node_& x) {
  if(x.t==3) {
    f(i,0,x.son.size()) x.mul.push_back(0);
    x.mul[x.son.size()]=1;
    for(int i=x.son.size()-1; i>=0; --i) {
      x.mul[i]=x.mul[i+1]*node[x.son[i]].m;
    }
    x.m=x.mul[0];
  } else if(x.t==1) {
    x.m=1;
  } else if(x.t==2) {
    x.m=x.v;
  }
  //printf("%lld\n", x.m);
}
void dfs(int x) {
//printf("dfs : at %lld\n", n);
  for(int i=0; i<node[x].son.size(); ++i) {
  //printf("%lld\n", node[n].son[i]);
    if(!node[node[x].son[i]].m) dfs(node[x].son[i]);
  }
  solve(node[x]);
}
int n, m, q, a[_], f[_], wkd[_], tag[_];
void addtag(int x, int t) {
  tag[x] = (tag[x]+t)%mod;
}
void work(int x) {
  wkd[x]=1;
  for(int i=0; i<node[x].son.size(); ++i) {
    addtag(node[x].son[i], tag[x]*node[x].mul[i+1]%mod);
    work(node[x].son[i]);
  }
}
signed main() {
  fopen(call);
  rd(n); f(i,1,n) rd(a[i]);
  //puts("qwq");
  rd(m);
  //puts("qwq");
  f(i,1,m) {
    int o; scanf("%lld", &o); node[i].t=o;
    if(o==1) { rd(node[i].p); rd(node[i].v); }
    else if(o==2) { rd(node[i].v); }
    else {
      int c, t; rd(c); f(j,1,c) node[i].son.push_back(0); f(j,1,c) { rd(t); node[i].son[j-1]=t; }
    }
  }
  //puts("qwq");
  f(i,1,m) if(!node[i].m) dfs(i);
  rd(q);
  f(i,1,q) rd(f[i]); int now=1;
  for(int i=q; i>=1; --i) {
    if(i<q) now=now*node[f[i+1]].m%mod;
    addtag(f[i], now);
  }
  now=now*node[f[1]].m%mod;
  f(i,1,m) if(!wkd[i]) work(i);
  f(i,1,n) a[i]=a[i]*now%mod;
  f(i,1,m) if(node[i].t==1) a[node[i].p]=(a[node[i].p]+tag[i]*node[i].v%mod)%mod;
  f(i,1,m) { node[i].son.clear(); node[i].mul.clear(); }
  f(i,1,n) printf("%lld ", a[i]); puts("");
  return 0;
}
