#include <stdio.h>

int N, M, C, K;

int main() {
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	scanf("%d%d%d%d", &N, &M, &C, &K);
	printf("%lld\n", (long long)(2 << (K - 1)) - N);
	return 0;
}

