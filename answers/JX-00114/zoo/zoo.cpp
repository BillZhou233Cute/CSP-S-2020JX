#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int L = 63;
const int __ = 63 + 7;

int n, m, C, K;
bool exi[__], b[__];

ll gi() {
  ll x = 0; char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x;
}

void Init() {
  n = gi(), m = gi(), C = gi(), K = gi() - 1;
  //cerr << n << ' ' << m << ' ' << C << ' ' << K << endl;
  ll a;
  for (int i = 1; i <= n; ++i) {
    a = gi();
    for (int j = 0; j <= K; ++j) {
      if (a & 1) exi[j] = 1;
      a >>= 1;
    }
  }
  int p, q;
  for (int i = 1; i <= m; ++i) {
    p = gi(), q = gi();
    b[p] = 1;
  }
}

void Run() {
  ll num = 1;
  for (int i = 0; i <= K; ++i) {
    if (!b[i]) exi[i] = 1;
    if (exi[i]) num *= 2;
  }
  printf("%lld\n", num - n);
}

int main() {
  freopen("zoo.in", "r", stdin);
  freopen("zoo.out", "w", stdout);
  Init();
  Run();
  return 0;
}
