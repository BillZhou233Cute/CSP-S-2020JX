#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define fopen(X) freopen(#X".in", "r", stdin); freopen(#X".out", "w", stdout);
#define ll long long
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=(ch=='-')?-f:f; ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x;
}
void rd(int& x) { x=rd(); }
ll date0=1721424, datem=2299160, D=2305449, one=365, four=1461, one00=36524, four00=146097, t0; int t;
int mon=1, day=1, tmp=0;
void add_run() {
  ++day;
  if(mon==2&&day==30) { ++mon, day=1; }
  else if((mon==4||mon==6||mon==9||mon==11)&&day==31) { ++mon, day=1; }
  else if(day==32) { ++mon, day=1; }
  if(mon>12) { ++tmp; mon-=12; day=1; }
}
void add_nrun() {
  ++day;
  if(mon==2&&day==29) { ++mon, day=1; }
  else if((mon==4||mon==6||mon==9||mon==11)&&day==31) { ++mon, day=1; }
  else if(day==32) { ++mon, day=1; }
  if(mon>12) { ++tmp; mon-=12; day=1; }
}
int chkrun(int x) {
  return (x%400==0) || ((x%4==0)&&(x%100!=0));
}
int cal(int x) {
  if(x>=3*one00) return 1;
}
void solve() {
  scanf("%lld", &t0);
  if(t0<366) {
    mon=day=1; tmp=0;
    f(i,1,t0) add_run();
    printf("%d %d %d BC\n", day, mon, 4713);
  } else if(t0<date0) {
    mon=day=1; tmp=0; t0-=366;
    ll x=t0/four; t0%=four;
    f(i,1,t0) if(tmp==3) add_run(); else add_nrun();
    printf("%d %d %lld BC\n", day, mon, 4712-x*4LL-tmp);
  } else if(t0==date0) {
    printf("%d %d %d\n", 1, 1, 1);
  } else if(t0<datem){
    mon=day=1; tmp=0; t0-=date0; ll x=t0/four; t0%=four;
    f(i,1,t0) if(tmp==3) add_run(); else add_nrun();
    printf("%d %d %lld\n", day, mon, 1LL+x*4LL+tmp);
  } else if(t0==datem) {
    printf("%d %d %d\n", 4, 10, 1582);
  } else if(t0<D){
    mon=10; day=15; tmp=0; t0-=(datem+1); ll x=t0/four; t0%=four;
    f(i,1,t0) if(tmp==3) add_run(); else add_nrun();
    printf("%d %d %lld\n", day, mon, 1582LL+x*4LL+tmp);
  } else {
    mon=1; day=1; tmp=0; t0-=D;
    // 1600.1.1
    ll x=t0/four00; t0=t0%four00;
    ll y=t0/one00; t0=t0%one00;
    ll z=t0/four; t0%=four;
    f(i,1,t0) if(tmp==0) add_run(); else add_nrun();
    printf("%d %d %lld\n", day, mon, 1600LL+x*400LL+y*100LL+z*4LL+tmp);
  }
}
int main() {
//  fopen(test);
//  printf("%d\n", rd());
//  std::cout<<chkrun(1586)<<" "<<chkrun(1587)<<std::endl;
  fopen(julian);
  rd(t); f(i,1,t) solve();
  return 0;
}
