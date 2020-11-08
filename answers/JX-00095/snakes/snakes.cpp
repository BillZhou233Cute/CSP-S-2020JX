#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int t, n, a[1000005], b[1000005], ans;
int main()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	scanf("%d%d", &t, &n);
	for(int i = 1; i <= t; i++)
	{
		ans = n;
		if(i == 1)
		{
			for(int j = 1; j <= n; j++)
			{
				scanf("%d", &a[j]);
				b[j] = a[j];
			}
			sort(b+1, b+1+n);
			while(b[n] - b[1] >= b[n-1])
			{
				b[n] -= b[1];
				ans -= 1;
				sort(b+1, b+1+n);
			}
			printf("%d\n", ans);
		}
		else
		{
			int x;
			scanf("%d", &x);
			for(int j = 1; j <= x; j++)
			{
				int x1,x2;
				scanf("%d%d", &x1,&x2);
				a[x1] = x2;
			}
			for(int j = 1; j <= n; j++)
			{
				b[j] = a[j];
			}
			sort(b+1, b+1+n);
			while(b[n] - b[1] >= b[n-1] && ans > 1)
			{
				b[n] -= b[1];
				ans -= 1;
				sort(b+1, b+1+n);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}