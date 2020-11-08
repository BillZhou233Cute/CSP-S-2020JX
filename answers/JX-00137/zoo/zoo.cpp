#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef unsigned long long ull;
const int N = 2e6 + 100;

int n, m, c, k;
ull a[N];
int p[N], q[N], tm[N];
int vis[N], num;
//animal -> food
vector<int> g[N];

int main() {
	
	freopen("zoo.in" ,"r", stdin);
	freopen("zoo.out", "w", stdout);
	
	cin >> n >> m >> c >> k;
	
	//融合成大动物
	ull ax = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		ax |= a[i];
	}
	
	
	for(int i = 1; i <= m; i++) {
		scanf("%d %d", &p[i], &q[i]);
		if(ax & (ull)(1ull << p[i])) {
			//g[p[i]].push_back(q[i] + n);
			vis[++num] = q[i];
			g[num].push_back(p[i]);
		}
	}
	
	
	//
	ull bx = 0;
	
	for(int i = 1; i <= num; i++) {
		//cout << vis[i] << endl;
		for(unsigned int j = 0; j < g[i].size(); j++) {
			int v = g[i][j];
			//cout << v << " ";
			bx |= (ull)(1ull << v);
		}
		//cout << endl;
	}
	
	
	//求m没有提到的数
	ull ans = 0;
	for(int i = 1; i <= m; i++) {
		if(tm[p[i]] == 0) tm[p[i]] = 1, ans++;
	}
	
	ans = k - ans;
	
	//cout << ans << endl;
	
	for(int i = 0; i < k; i++) {
		if(bx & (ull)(1ull << i)) ans++;
	}
	//cout << ans << endl;
	
	cout << (1ull << ans) - n << endl;

	return 0;
}
