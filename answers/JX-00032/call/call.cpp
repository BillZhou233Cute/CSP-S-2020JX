#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
char In[1 << 20], *ss = In, *tt = In;/*
#define getchar() (ss == tt && (tt = (ss = In) + fread(In, 1, 1 << 20, stdin), ss == tt) ? EOF : *ss++)*/
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + int(ch - '0');
	return x * f;
}
const int MAXN = 1e5 + 5;
const int P = 998244353;
int pls(int a, int b) {return a + b < P ? a + b : a + b - P;}
int mns(int a, int b) {return a < b ? a - b + P : a - b;}
int mul(int a, int b) {return 1ll * a * b % P;}
int n;
ll a[MAXN];
int m;

typedef pair<int, ll> pil;
#define fi first
#define se second


vector<int> G[MAXN];
vector<pil> t[MAXN];
ll cnt[MAXN];
bool vis[MAXN], leaf[MAXN];
int Q;

void merge(int a, int b) {
	vector<pil> ans;
	int i = 0, j = 0;
	int la = t[a].size(), lb = t[b].size();
	while(i < la && j < lb) {
		if(t[a][i].fi < t[b][j].fi) {
			ans.push_back(pil(t[a][i].fi, mul(t[a][i].se, cnt[b])));
			i++;
		} else if(t[a][i].fi > t[b][j].fi) {
			ans.push_back(pil(t[b][j].fi, t[b][j].se));
			j++;
		} else {
			ans.push_back(pil(t[a][i].fi, pls(mul(t[a][i].se, cnt[b]), t[b][j].se)));
			i++; j++;
		}
	}
	while(i < la) {
		ans.push_back(pil(t[a][i].fi, mul(t[a][i].se, cnt[b])));
		i++;
	}
	while(j < lb) {
		ans.push_back(pil(t[b][j].fi, t[b][j].se));
		j++;
	}
	t[a] = ans;
	cnt[a] = mul(cnt[a], cnt[b]);
}
void dfs(int u) {
	if(leaf[u]) return;
	if(vis[u]) return;
	vis[u] = 1;
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		dfs(v);
	}
	int v0 = G[u][0];
	t[u] = t[v0]; cnt[u] = cnt[v0];
	for(int i = 1; i < G[u].size(); i++)
		merge(u, G[u][i]);//merge i to u
}
int main() {
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	m = read();
	for(int i = 1; i <= m; i++) {
		int opt = read();
		if(opt == 1) {
			int P = read(); ll V = read();
			t[i].push_back(pil(P, V));
			cnt[i] = 1;
			leaf[i] = 1;
		} else if(opt == 2) {
			cnt[i] = read();
			leaf[i] = 1;
		} else {
			cnt[i] = 1;
			int C = read();
			for(int j = 1; j <= C; j++) G[i].push_back(read());
		}
	}
	cnt[0] = 1;
	Q = read();
	for(int i = 1; i <= Q; i++) G[0].push_back(read());
	dfs(0);
	for(int i = 1; i <= n; i++) a[i] = mul(a[i], cnt[0]);
	for(int i = 0; i < t[0].size(); i++) {
		int p = t[0][i].fi; ll tim = t[0][i].se;
		a[p] = pls(a[p], tim);
	}
	for(int i = 1; i <= n; i++) printf("%lld ", a[i]);
	printf("\n");
	return 0;
}
