#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
struct tmp{
	int pos,val;
}a[100005],b[100005];

bool cmp(const tmp& i,const tmp& j) {
	return (i.val > j.val || (i.val == j.val && i.pos > j.pos));
}
void Read(int T) {
	if (T == 0) {
		scanf("%d", &n);
		for (int i = 0;i < n;++i) scanf("%d", &a[i].val),a[i].pos = i;
	} else {
		int k;
		scanf("%d", &k);
		while (k--) {
			int x,y;
			scanf("%d%d", &x, &y);
			a[x].val = y;
		}
	}
}
int main() {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int i = 0;i < T;++i) {
		Read(i);
		memcpy(b,a,sizeof(a));
		if (b[n-1].val - b[0].val < b[n-2].val)printf("%d\n", n);
		else printf("1\n");
	}
	
	return 0;
}


