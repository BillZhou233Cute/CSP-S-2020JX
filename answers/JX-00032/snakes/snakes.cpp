#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
char In[1 << 20], *ss = In, *tt = In;
#define getchar() (ss == tt && (tt = (ss = In) + fread(In, 1, 1 << 20, stdin), ss == tt) ? EOF : *ss++)
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + int(ch - '0');
	return x * f;
}
const int MAXN = 1e6 + 5;

int n, a[MAXN];
int dfn[MAXN], tim;
struct Node {
	int id, val;
	bool operator < (const Node& B)const {
		if(val != B.val) return val < B.val;
		return id < B.id;
	}
	Node gain(const Node& B) {
		return (Node){id, val + B.val};
	}
};
set<Node> se;
void work() {
	se.clear();
	tim = 0;
	for(int i = 1; i <= n; i++) se.insert((Node){i, a[i]});
	while(1) {
		if(se.size() == 1) {
			printf("%d\n", 1);
			return;
		}
		Node mx = *--se.end();
		dfn[mx.id] = ++tim;
		Node mn = *se.begin();
		Node smn = se.size() >= 3 ? *++se.begin() : (Node){mn.id, 0};
		if(mx < smn.gain(mn)) {
			printf("%d\n", n - tim + 1);
			return;
		} else {
			if(dfn[mn.id]) {
				printf("%d\n", n - dfn[mn.id] + 1);
				return;
			} else {
				se.erase(se.begin());
				se.erase(--se.end());
				se.insert((Node){mx.id, mx.val - mn.val});
			}
		}
	}
}
void init(int T) {
	if(T == 1) {
		n = read();
		for(int i = 1; i <= n; i++) a[i] = read();
	} else {
		int k = read();
		for(int i = 1; i <= k; i++) {
			int x = read(), y = read();
			a[x] = y;
		}
	}
}

int main() {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	//printf("qwq");
	int T = read();
	for(int i = 1; i <= T; i++) {
		init(i);
		work();
	}
	return 0;
}
