#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define fopen(X) freopen(#X".in", "r", stdin); freopen(#X".out", "w", stdout);
#define _ 1000005
typedef unsigned long long ull;
char ch;
ull a[_], x[64], chk[64], use[64], used[64];
const ull one=1, two=2, zero=0, ten=10, fe=48;
int n, m, c, k, cnt;
ull rd() {
  ull f=one, x=zero; ch=getchar();
  while(!isdigit(ch)) { f=(ch=='-')?-f:f; ch=getchar(); }
  while(isdigit(ch)) { x=x*ten+ch-fe; ch=getchar(); }
  return x;
}
void rd(ull& x) { x=rd(); }
using namespace std;
ull counter() {
  ull t=0, ans=0;
  f(i,1,n) {
    t=0;
    f(j,0,63) { if((a[i]&x[j])!=0) { t=1; break; } }
    ans+=t;
  }
  return ans;
}
int main() {
  fopen(zoo);
  x[0]=one; for(int i=1; i<=63; ++i) x[i]=x[i-1]*two;
  scanf("%d%d%d%d", &n, &m, &c, &k);
  f(i,1,n) {
    rd(a[i]);
    f(j,0,63) if((a[i]&x[j])!=0) chk[j]=1;
  }
  f(i,1,m) {
    int p, q; scanf("%d%d", &p, &q);
    if(used[p]==1) continue;
    if(!chk[p]) { cnt+=1; used[p]=1; }
    else { use[p]=1; used[p]=1; }
  }
//  cout<<cnt<<endl;
  cout<<x[k-cnt]-(ull)(n)<<endl;
  return 0;
}
