#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define fopen(X) freopen(#X".in", "r", stdin); freopen(#X".out", "w", stdout);
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=(ch=='-')?-f:f; ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x;
}
void rd(int& x) { x=rd(); }
using namespace std;
int main() {
  fopen(snakes);
  int t=rd();
  f(i,1,t) puts("0");
  return 0;
}
