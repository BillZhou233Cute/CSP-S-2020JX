#include <iostream>
#include <cstdio>

using namespace std;

int t, n, k;
int a[1000001], b[1000001];

int main()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	cin >> t;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	int m = n;
	while (m > 0)
	{
		if (m >= 3)
		{
			if (b[m] - b[1] >= b[2])
			{
				b[m] -= b[1];
				m--;
				for (int i = 1; i <= m; i++)
				{
					b[i] = b[i + 1];
				}
				int i = m;
				while (i > 1 && b[i] < b[i - 1])
				{
					swap(b[i], b[i - 1]);
					i--;
				}
			}
			else break;
		}
		else if (m == 2)
		{
			if (b[m] > b[1])
			{
				b[m] -= b[1];
				m--;
				break;
			}
		}
		else break;
	}
	cout << m << endl;
	while (t > 1)
	{
		t--;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			int x, y;
			cin >> x >> y;
			b[x] = a[x] + y;
		}
		m = n;
		while (m > 0)
		{
			if (m >= 3)
			{
				if (b[m] - b[1] >= b[2])
				{
					b[m] -= b[1];
					m--;
					for (int i = 1; i <= m; i++)
					{
						b[i] = b[i + 1];
					}
					int i = m;
					while (i > 1 && b[i] < b[i - 1])
					{
						swap(b[i], b[i - 1]);
						i--;
					}
				}
				else break;
			}
			else if (m == 2)
			{
				if (b[m] > b[1])
				{
					b[m] -= b[1];
					m--;
					break;
				}
			}
			else break;
		}
		cout << m << endl;
	}
	return 0;
}
