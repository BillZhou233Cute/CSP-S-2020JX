#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int randint();

int main()
{
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i += 1)
	{
		int a;
		cin >> a;
	}
	for (int i = 0; i < m; i += 1)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int p, v;
			cin >> p >> v;
		}
		else if (t == 2)
		{
			int v;
			cin >> v;
		}
		else if (t == 3)
		{
			int c;
			cin >> c;
			for (int j = 0; j < c; j += 1)
			{
				int g;
				cin >> g;
			}
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i += 1)
	{
		int f;
		cin >> f;
	}
	for (int i = 0; i < n; i += 1)
	{
		cout << randint() % 998244353 << ' ';
	}
	cout << endl;
	return 0;
}

int randint()
{
	srand(time(0));
	return rand();
}
