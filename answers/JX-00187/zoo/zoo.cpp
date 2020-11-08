#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e6+10;
unsigned long long n, m, c, k;
int a[N];
int p[N], q[N];
bool book[100000000];
unsigned long long ans = 1;
bool rb[N];

int main()
{
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	cin >> n >> m >> c >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		rb[a[i]] = true;
	}
	for(int i= 1;i <= m;i++)
		cin >> p[i] >> q[i];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(a[i] >> (p[j]))
				book[q[j]] = true;
	for(int i = 0;i <= ((unsigned long long)1 << k)-1;i++)
		for(int j = 1;j <= m;j++)
			if(i >> (p[j]-1) && book[q[j]] && !rb[i])
			{
				ans++;
				rb[i] = true;
			}
	cout << ans;
	return 0;
}