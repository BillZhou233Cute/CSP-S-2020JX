#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
using namespace std;
#define int long long
#define il inline
#define next nee
#define re register int
#define inf 1e18
il int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return x*f;
}
il void print(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x/10)print(x/10);
    putchar(x%10+'0');
}
const int N=1e5+5;
int n,m,a[N],b[N];
signed main()
{
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
	int T=read();
    n=read();
	for(re i=1;i<=n;i++)
	{
		b[i]=a[i]=read();
	}
	while(--T)
	{
		sort(a+1,a+n+1);
		if(a[n]-a[1]>=a[2]){printf("1\n");}
		else printf("%lld\n",n);
		m=read();
		for(re i=1;i<=n;i++)a[i]=b[i];
		for(re i=1;i<=m;i++){int x=read(),y=read();a[x]=b[x]=y;}
	}
	sort(a+1,a+n+1);
	if(a[n]-a[1]>=a[2]){printf("1\n");}
	else printf("%lld\n",n);
    return 0;
}
