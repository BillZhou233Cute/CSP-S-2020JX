#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
#define N 1000006
#define M 1000006
#define C 100000008
#define K 64
using namespace std;
int read()
{
	int f=1, x=0;
	char c=getchar();
	for(; c<'0' || c>'9'; c=getchar())
		if(c=='-') f=-f;
	for(; c>='0'&&c<='9'; c=getchar())
		x = (x>>1) + (x>>3) + (c^48);
	return x*f;
}//, len[N]
int id[N], pos[C], note[M], kind[K][10001];
bool exist[N], er[N][K], need[K];
int n, m, c, k, ans;
bool nd[K];
bool pd(int ids)
{
	memset(nd, 0, sizeof(nd));
	//for(int i=1; i<=k; i++)
	//{
	//	if(er[ids][i])
			
	//}
	for(int i=1; i<=c; i++)
	{
		//for(int j=1; j<=kind[i][0]; j++)
			if(er[ids][pos[i]] && !need[i])
				return false;
	}
	return true;
}
int main()
{
	freopen("zoo1.in", "r", stdin);
	//freopen("zoo.out", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &c, &k);
	for(int i=1; i<=n; i++)
	{
		id[i] = read();
		int x = id[i];
		exist[x] = true;
		int len=0;
		while(x)
		{
			er[i][len++] = x%2ll;
			x >>= 1ll;
		}
	}
	for(int i=1; i<=m; i++)
	{
		int p = read(), q = read();
		note[i] = q;
		kind[p][++kind[p][0] ] = q;
		pos[q] = p; //position of buying q kind
	}
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(!exist[j]) continue;
			if(er[j][pos[note[i]]] )
				need[note[i]] = true;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(!exist[i] && pd(i))
		{
			ans++;
		}
	}
	
	printf("%d\n", ans);
	
	fclose(stdin);
	//fclose(stdout);
	return 0;
}