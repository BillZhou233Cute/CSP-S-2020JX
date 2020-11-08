#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int _ = 1e6 + 7;

int n, a[_], num[_], ans[_];
bool b[_];

void Dfs(int k, int lc, int rc) {
  rc = min(rc, k - 1);
  if (k == 0 or b[k]) {
    bool flag = 0;
    for (int i = n; i >= 1; --i)
      if (num[i] > ans[i]) { flag = 1; break; }
    if (!flag) return;
    for (int i = 1; i <= n; ++i) ans[i] = num[i];
    ans[0] = 0;
    for (int i = 1; i <= n; ++i)
      if (!b[i]) ++ans[0];
    return;
  }
  int tmp = a[k];
  Dfs(k - 1, lc, rc);
  for (int i = lc; i <= rc; ++i) {
    num[k] = i - lc + 1;
    tmp -= a[i], b[i] = 1;
    int pl = upper_bound(a + lc, a + rc + 1, tmp) - a - 1;
    Dfs(k - 1, i, pl);
  }
  for (int i = 1; i <= rc; ++i) b[i] = 0;
}

void Run() {
  for (int i = 0; i <= n; ++i) ans[i] = 0;
  Dfs(n, 1, n - 1);
  cout << ans[0] << endl;
}

int main() {
  freopen("snakes.in", "r", stdin);
  freopen("snakes.out", "w", stdout);
  int T; cin >> T;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  Run();
  int K, x, v;
  --T;
  while(T--) {
    cin >> K;
    for (int i = 1; i <= K; ++i) {
      cin >> x >> v;
      a[x] = v;
    }
    Run();
  }
  return 0;
}
