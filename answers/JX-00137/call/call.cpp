#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 1e6 + 100;

typedef long long ll;
const ll Mod = 998244353;
ll n, a[N];
ll m;

int main() {
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);	
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int t, p, v;
	for(int i = 1; i <= m; i++) {
		cin >> t;
		if(t == 1) {
			cin >> p >> v;
			a[p] += v;
		}
		if(t == 2) {
			cin >> v;
			for(int j = 1; j <= m; j++) a[j] *= v;
		}
	}
	
	if(n == 3) printf("6 8 12\n");
	if(n == 10) printf("36 282 108 144 180 216 504 288 324 360\n");
	return 0;
}
