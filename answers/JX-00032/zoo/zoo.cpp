#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char In[1 << 20], *ss = In, *tt = In;
#define getchar() (ss == tt && (tt = (ss = In) + fread(In, 1, 1 << 20, stdin), ss == tt) ? EOF : *ss++)
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + int(ch - '0');
	return x * f;
}
ull uread() {
	ull x = 0; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar());
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10ull + ull(ch - '0');
	return x;
}

const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;
const int MAXK = 70;
int n, m, c, k;
bool fl[MAXK];
int not_can[MAXK];
int main() {
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	n = read(), m = read(); c = read(); k = read();
	for(int i = 1; i <= n; i++)	 {
		ull a = read();
		for(int j = 0; j < k; j++)
			if((a >> j) & 1) fl[j] = 1;
	}
	for(int i = 1; i <= m; i++) {
		int p = read(), q = read();
		if(!fl[p]) not_can[p] = 1;
	}
	int tot = 0;
	for(int i = 0; i < k; i++)
		if(!not_can[i]) tot++;
	printf("%llu\n", (1ull << tot) - n);
	return 0;
}
