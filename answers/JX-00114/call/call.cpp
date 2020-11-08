#include <cstdio>
#include <iostream>
#include <vector>

#define pb push_back
#define sz(x) (int)(x).size()
#define mkp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;

const int _ = 1e3 + 7;
const int __ = 2e5 + 7;
const int mod = 998244353;

bool be;
int n, m, Q, a[_];
int to[_][_], C[_], de[_];
int ty[_], p[_], val[_], coef, mul[_], pls[_][_];
bool en;

void Init() {
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> ty[i];
    if (ty[i] == 1) cin >> p[i] >> val[i];
    else if (ty[i] == 2) cin >> val[i];
    else {
      cin >> C[i];
      for (int j = 1; j <= C[i]; ++j) { cin >> to[i][j]; ++de[to[i][j]]; }
    }
  }
}

int Pw(int a, int p) {
  int res = 1;
  while (p) {
    if (p & 1) res = (ll)res * a % mod;
    a = (ll)a * a % mod;
    p >>= 1;
  }
  return res;
}

void Dfs(int u) {
  if (ty[u] == 3 and !C[u]) return; 
  if (ty[u] == 2) { 
    for (int i = 1; i <= n; ++i) a[i] = (ll)a[i] * val[u] % mod;
    coef = (ll)coef * val[u] % mod;
    return;
  }
  if (ty[u] == 1) {
    a[p[u]] = (a[p[u]] + val[u]) % mod;
    return;
  }
  if (!mul[u]) {
    int tmp = coef;
    for (int i = 1; i <= n; ++i) pls[u][i] = a[i];
    for (int i = 1; i <= C[u]; ++i) Dfs(to[u][i]);
    mul[u] = (ll)coef * Pw(tmp, mod - 2) % mod;
    for (int i = 1; i <= n; ++i) pls[u][i] = (a[i] - (ll)pls[u][i] * mul[i] % mod + mod) % mod;
  }
  else {
    for (int i = 1; i <= n; ++i) a[i] = ((ll)a[i] * mul[i] % mod + pls[u][i]) % mod;
  }
}

void Run() {
  ++m;
  cin >> C[m];
  for (int i = 1; i <= C[m]; ++i) cin >> to[m][i];
  Dfs(m);
  for (int i = 1; i <= n; ++i) printf("%d ", a[i]); putchar('\n');
}

int main() {
  freopen("call.in", "r", stdin);
  freopen("call.out", "w", stdout);
  Init();
  Run();
  return 0;
}
