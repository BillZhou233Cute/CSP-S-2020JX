#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define lson rt << 1, l, mid 
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
const int N = 1e5 + 10;
const int mod = 998244353;
long long val[N<<2], add[N<<2], mul[N<<2];
int n, m, q;
bool ok[N];
vector<int> num[N];
void work(int op) {
	if (num[op][0] == 1) {
		int a = num[op][1], b = num[op][2];
		val[a] = (val[a] + b) % mod;
	} else if (num[op][0] == 2) {
		int a = num[op][1];
		for (int i = 1; i <= n; i++)
			val[i] = val[i] * a % mod;
	} else {
		for (int i = 1; i <= num[op][1]; i++) 
			work(num[op][1+i]);
	}
}	
int main() {
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	scanf("%d", &n);
	for (int i  = 1; i <= n; i++) cin >> val[i];
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int op;
		scanf("%d", &op);
		num[i].push_back(op);
		if (op == 1) {
			int a, b;
			scanf("%d %d", &a, &b);
			num[i].push_back(a);
			num[i].push_back(b);
		} else if (op == 2) {
			int a;
		    scanf("%d", &a);
			num[i].push_back(a);
		} else {
			int t;
			scanf("%d", &t);
			num[i].push_back(t);
			while (t--) {
				int a;
				scanf("%d", &a);
				num[i].push_back(a);
			}
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int a;
		scanf("%d", &a);
		work(a);
	}
	for (int i = 1; i <= n; i++) printf("%d ", val[i]);
	return 0;
}