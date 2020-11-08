#include <iostream>
#include <cstdio>

using namespace std;

int n, m, c, k, ans;
int a[1000001], p[1000001], q[1000001], ma[100000001], num[64];
bool s[100000001];

void dfs(int t);

int main()
{
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	cin >> n >> m >> c >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i] >> q[i];
	}
	for (int i = 1; i <= m; i++)
	{
		ma[p[i]] = q[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int j = 0;
		while (a[i] > 0)
		{
			j++;
			if (ma[j] > 0 && a[i] % 2 == 1)
			{
				s[ma[j]] = true;
			}
			a[i] /= 2;
		}
	}
	s[0] = true;
	dfs(1);
	cout << ans - n << endl;
	return 0;
}

void dfs(int t)
{
	for (int i = 0; i < 2; i += 1)
	{
		num[t] = i;
		if (t < k)
		{
			dfs(t + 1);
		}
		else
		{
			bool can = true;
			for (int j = 0; j < k; j += 1)
			{
				if (num[j] == 1 && !s[ma[j + 1]])
				{
					can = false;
					break;
				}
			}
			if (can)
			{
				ans++;
			}
		}
	}
}
