#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int T, n;
int heal[maxn];
pair<int, int> theal[maxn];
int lef;
void solve()
{
	sort(theal + 1, theal + n + 1);
	int ans = 0;
	int head = 1;
	while(theal[n].first - theal[ans + 1].first >=theal[n - 1].first)
	{
		theal[n].first -= theal[ans + 1].first;
		theal[ans + 1].first = 0;
		heal[theal[ans + 1].second] = 0;
		head++;
		ans++;
	}
	int lef = n - ans;
	printf("%d\n", lef);
	}
int main()
{
	int k;
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	scanf("%d%d", &T, &n);
	lef = n;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &heal[i]);
		theal[i].first = heal[i];
		}
	solve();
	for(int i = 1; i < T; i++)
	{
		scanf("%d", &k);
		for(int i = 1; i <= k; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			heal[x] = y;
			}
		for(int j = 1; j <= n; j++)
			theal[j].first = heal[j];
		solve();
		}
	return 0;
	}