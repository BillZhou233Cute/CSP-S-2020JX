#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int ,int> PII;
const int N = 1e6+10;
int a[N];
int n, k;
int T;
int x, y;
priority_queue<PII> bq;
priority_queue<PII, vector<PII>, greater<PII> > sq;

int main()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	cin >> T;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	while(T--)
	{
		int rest = n;
		while(!bq.empty())
			bq.pop();
		while(!sq.empty())
			sq.pop();
		for(int i =1;i <= n;i++)
		{
			bq.push(make_pair(a[i], i));
			sq.push(make_pair(a[i], i));
		}
		while(true)
		{
			int sma = sq.top().first;
			sq.pop();
			if((bq.top().first - sma <= sq.top().first  && bq.top().second != sq.top().second)|| rest == 1)
			{
				cout << rest << endl;
				break;
			}else
			{
				int tmp = bq.top().first - sma;
				int ttmp = bq.top().second;
				sq.push(make_pair(bq.top().first - sma, ttmp));
				bq.pop();
				bq.push(make_pair(tmp, ttmp));
				rest --;
			}
		}
		if(!T)
			break;
		cin >> k;
		for(int i = 1;i <= k;i++)
		{
			cin >> x >> y;
			a[x] = y;
		}
	}
	return 0;
}
