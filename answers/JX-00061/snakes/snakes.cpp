#include<bits/stdc++.h>
using namespace std;
int t,n,k,p,v;
const int N=2005;
int a[N];
template <class T> inline void read(T &x)
{
	x=0;int g=1;char s=getchar();
	for (;s>'9'||s<'0';s=getchar())if (s=='-') g=-1;
	for (;s>='0'&&s<='9';s=getchar()) x=(x<<1)+(x<<3)+(s^48);
	x*=g;	
}
	
int main()
{
	int i,j;
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	read(t);
	int tt=t;
	while(t--)
	{
		if (t==tt-1)
		{
			read(n);
			for (i=1;i<=n;i++) read(a[i]);
		}
		else	
		{
			read(k);
			for (i=1;i<=k;i++)
			{
				read(p);read(v);
				a[p]=v;
			}
		}
		if (n==3)
		{
			if (a[3]-a[2]>=a[1])
					printf("1\n");
			else
					printf("3\n");
		}	
	}
	
	return 0;
}

