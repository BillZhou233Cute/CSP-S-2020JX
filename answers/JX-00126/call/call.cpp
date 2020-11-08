#include <vector>
#include <cstdio>
using namespace std;

const int MOD = 998244353;
const int L = 1e5+5;
long long n, m, a[L], t[L], p[L], v[L], c[L], t1, q;
vector<long long> vec[L];

void solve(int x) {
    if (t[x] == 1) a[p[x]] = (a[p[x]] + v[x]) % MOD;
    else if (t[x] == 2) {
        for (int i = 1; i <= n; i++) a[i] = (a[i] * v[x]) % MOD;
    } else {
        for (int i = 0; i < c[x]; i++) solve(vec[x][i]);
    }
}

int main() {
    freopen("call.in", "r", stdin);
    freopen("call.out", "w", stdout);
    
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    scanf("%lld", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &t[i]);
        if (t[i] == 1) scanf("%lld %lld", &p[i],&v[i]);
        else if (t[i] == 2) scanf("%lld", &v[i]);
        else {
            scanf("%lld", &c[i]);
            for (int j = 1; j <= c[i]; j++) {
                scanf("%lld", &t1);
                vec[i].push_back(t1);
            }
        }
    }
    
    scanf("%lld", &q);
    while (q--) {
        scanf("%lld", &t1);
        solve(t1);
    }
    
    for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
    
    return 0;
}