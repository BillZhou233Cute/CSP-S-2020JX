#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<int> vec;
const int L = 1e6 + 5;
int n, m, c, k, a[L], p[L], q[L], num, number[70], cnt, cnt1, cnt2=0, nnn=0;
bool flag[L], f;

int power(int x) {
	int ans = 1;
	for (int i = 1; i <= x; i++) ans *= 2;
	return ans;
}

int main() {
    freopen("zoo.in", "r", stdin);
    freopen("zoo.out", "w", stdout);
	
	scanf("%d %d %d %d", &n, &m, &c, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%d %d", &p[i], &q[i]);
		
	for (int i = 1; i <= m; i++) flag[i] = false;
		
	for (int i = 1; i <= n; i++) {
		memset(number, 0, sizeof(number));
		
		num = a[i];
		cnt = 0;
		while (num > 0) {
			number[k - cnt] = num&1;
			num >>= 1;
			cnt++;
		}
		
		f = false;
		
		for (int j = 1; j <= m; j++) {
			if (number[k-p[j]] == 1) flag[j] = true, f = true;
		}
		
		if (f) cnt1++;
	}
	
	if (vec.size() != 0) cnt2 = 1;
	for (int i = 1; i <= m; i++) {
		if (!flag[i]) vec.push_back(p[i]);
	}
	
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] != vec[i-1]) cnt2++;
	}
	
	nnn = 0;
	if (cnt2 == 1) nnn = power(k-1);
	else if (cnt2 >= 2) nnn = power(k) - power(k-2);
	printf("%d", power(k)-cnt1-nnn);
	
    return 0;
}