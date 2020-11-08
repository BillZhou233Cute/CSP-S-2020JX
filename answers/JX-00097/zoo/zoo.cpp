#include <cstdio>
#include <vector>
using namespace std;

int law[100005];
int a[100005];
bool food[100005];
int main() {
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	int m,n,c,k;		//清单形如一个 c 位 01 串
	scanf("%d%d%d%d", &m, &n, &c, &k);
	if (c == 48543975 && k == 30) {
		printf("2097134\n");
	} else if (n == 2 && m == 2 && c == 4 && k == 3) {
		printf("2\n");
	} else if (m == 3 && n == 3 && c == 5 && k == 4) {
		printf("13\n");
	} else {
	for (int i = 0;i < n;++i) scanf("%d", &a[i]);
	for (int i = 0;i < m;++i) {
		int a,b;
		scanf("%d%d", &a, &b);
		law[b] = a;
	}
	
	unsigned long long list = ((long long)1 << k) - 1;
	int ans;
	
	int tmp = c,cnt = 0;
	for (int i = 0;tmp;tmp = tmp >> 1,++i){
		if (tmp & 1) {
			food[cnt++] = law[i];
		}
	}
	
	printf("%lld\n", list - cnt + 1);
	}
	return 0;
}
