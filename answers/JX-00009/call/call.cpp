#include <fstream>
#include <iostream>
#include <map>
#include <list>
#define MOD(a) (a % 998244353)
#define MODF(a) (a %= 998244353)
using namespace std;
unsigned n;
unsigned N[100001];
typedef struct FUN{
  map<unsigned, unsigned long long> ta;
  list<unsigned> tc;
  unsigned long long tx;
  unsigned type, tr;
}FUN;
FUN F[100001];

void unwarp(unsigned i){
  unsigned b;
  unsigned tcs = F[i].tc.size();
  list<unsigned>::iterator end = F[i].tc.end();
  for(list<unsigned>::iterator j = F[i].tc.begin();j != end;++j) {
    b = *j;
    if(F[b].type == 1)
      F[i].ta[F[b].tr] += MOD(F[b].ta[F[b].tr]);
    else if(F[b].type == 2){
      F[i].tx *= MOD(F[b].tx);
      for(unsigned k = 1;k <= n;++k)
	F[i].ta[k] *= MOD(F[b].tx);
    }
    else if(F[b].type == 3){
      if(F[b].tc.size() != 0)
	unwarp(b);
      F[i].tx *= MOD(F[b].tx);
      for(unsigned k = 1;k <= n;++k) {
	F[i].ta[k] *= MOD(F[b].tx);
	F[i].ta[k] += MOD(F[b].ta[k]);
      }
    }
  } 
  F[i].tc.clear();
  MODF(F[i].tx);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ifstream fin("call.in");
  ofstream fout("call.out");

  fin >> n;
  for(unsigned i = 1;i <= n;++i)
    fin >> N[i];

  unsigned m;
  fin >> m;
  unsigned t, a, b;
  for(unsigned i = 1;i <= m;++i){
    fin >> t;
    if(t == 1){
      fin >> a >> b;
      F[i].type = 1;
      F[i].tr = a;
      F[i].ta[a] = MOD(b);
    }
    else if(t == 2){
      fin >> a;
      F[i].type = 2;
      F[i].tx = MOD(a);
    }
    else if(t == 3){
      fin >> a;
      F[i].type = 3;
      F[i].tx = 1;
      for(unsigned j = 1;j <= a;++j) {
	fin >> b;
	F[i].tc.push_back(b);
      }
    }
  }

  unsigned q;
  fin >> q;
  FUN& z = F[0];
  z.type = 3;
  z.tx = 1;
  for(unsigned i = 1;i <= q;++i){
    fin >> b;
    z.tc.push_back(b);
  }
  unwarp(0);

  for(unsigned i = 1;i < n;++i)
    fout << MOD(MOD(N[i] * MOD(z.tx)) + MOD(z.ta[i])) << ' ';
  fout << MOD(MOD(N[n] * MOD(z.tx)) + MOD(z.ta[n])) << endl;
  return 0;
}
