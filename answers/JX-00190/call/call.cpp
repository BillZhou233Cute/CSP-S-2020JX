#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<climits>
#include<sstream>
using namespace std;
#include<vector>
#define int long long

inline int read()
{
	char c ; int flag = 1;
	while((c = getchar()) < '0' || c > '9'){if(c == '-'){flag = -1;}}
	int count = c - '0';
	while((c = getchar()) >= '0' && c <= '9'){count *= 10 ; count += c - '0';}
	return count * flag;
}
inline void print(int x)
{
	if(x < 0){putchar('-') ; x = -x;}
	if(x > 9){print(x / 10);}
	putchar(x % 10 + '0');
}

const int N = 1e5 + 10;
const int Mod = 998244353;

int t[N << 2] , la[N << 2];
int a[N];
#define mid ((l + r) >> 1)

void build(int p , int l , int r)
{
	if(l == r)
	{
		t[p] = a[l] ; return;
	}
	build(p << 1 , l , mid) ; build(p << 1 | 1 , mid + 1 , r);
}

void pd(int p , int l , int r)
{
	if(la[p] != 1)
	{
		t[p << 1] *= la[p];
		t[p << 1] %= Mod;
		t[p << 1 | 1] *= la[p];
		t[p << 1 | 1] %= Mod;
		la[p << 1] *= la[p];
		la[p << 1] %= Mod;
		la[p << 1 | 1] *= la[p];
		la[p << 1 | 1] %= Mod;
		la[p] = 1;
	}
}

void modify(int p , int l , int r , int P , int s)
{
	if(l == r && l == P)
	{
		t[p] += s ; t[p] %= Mod ; return;
	}
	pd(p , l , r);
	if(P <= mid){modify(p << 1 , l , mid , P , s);}
	else{modify(p << 1 | 1 , mid + 1 , r , P , s);}
}

int query(int p , int l , int r , int P)
{
	if(l == P && l == r)
	{
		return t[p];
	}
	pd(p , l , r);
	if(P <= mid){return query(p << 1 , l , mid , P);}
	else{return query(p << 1 | 1 , mid + 1 , r , P);}
}

struct Node
{
	int c;
	int p , v;
	vector<int> f;
}node[N];
int n;
inline void check(int c)
{
	if(node[c].c == 1)
	{
		modify(1 , 1 , n , node[c].p , node[c].v);
	}
	if(node[c].c == 2)
	{
		la[1] *= node[c].v;
		la[1] %= Mod;
	}
	if(node[c].c == 3)
	{
		for(register int i = 0 ; i < node[c].f.size() ; i++)
		{
			check(node[c].f[i]);
		}
	}
}

signed main()
{
	freopen("call.in" , "r" , stdin);
	freopen("call.out" , "w" , stdout);
	n = read();
	for(register int i = 1 ; i <= n ; i++){a[i] = read();}
	for(register int i = 0 ; i < (N << 2) ; i++){la[i] = 1;}
	build(1 , 1 , n);
	int m = read();
	for(register int i = 1 ; i <= m ; i++)
	{
		node[i].c = read();
		if(node[i].c == 1)
		{
			node[i].p = read() ; node[i].v = read();
		}
		if(node[i].c == 2)
		{
			node[i].v = read();
		}
		if(node[i].c == 3)
		{
			int zc = read();
			for(register int j = 1 ; j <= zc ; j++)
			{
				node[i].f.push_back(read());
			}
		}
	}
	int q = read();
	for(register int i = 1 ; i <= q ; i++)
	{
		int c = read();
		check(c);
		//for(register int j = 1 ; j <= n ; j++)
		//{
		//	cout << query(1 , 1 , n , j) << " ";
		//}
		//cout << endl;
	}
	for(register int i = 1 ; i <= n ; i++)
	{
		print(query(1 , 1 , n , i)) ; putchar(' ');
	}
	return 0;
}
