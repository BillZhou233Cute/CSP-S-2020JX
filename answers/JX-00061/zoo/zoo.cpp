#include<bits/stdc++.h>
//#define ll long long
using namespace std;
int n,m,c,k,cnt;
const int N=1000005;
unsigned long long a[N];
int b[70];
unsigned long long ans=1,tmp;
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
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	read(n);read(m);read(c);read(k);
	for (i=1;i<=n;i++)	read(a[i]);
	for (i=1;i<=m;i++)		
	{
		int p,q;
		read(p);read(q);
		b[p]=1;
	}	
	for (i=1;i<=n;i++)
	{
		for (j=0;j<=k-1;j++)
		{
			if (((a[i]>>j)&1)&&b[j]==1)
				b[j]=2;
		}
	}
	for (i=0;i<=k-1;i++)
		if (b[i]==2||b[i]==0)
			cnt++;

	for (i=1;i<=cnt;i++)
		ans*=2;
	tmp=(unsigned long long )n;
	cout<<ans-tmp<<endl;	
	return 0;
}
/*
2 2 4 3
1 2
1 3
2 4
*/