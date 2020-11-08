#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
using namespace std;
#define int unsigned long long
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
const int N=1e6+5;
int n,m,c,k,a[N],p,q,ans;
bool b[N];
map<int,bool>f;
il void deal(int x)
{
	int t=0;
	while(x)
	{
		if(x&1&&!b[t])b[t]=1;
		t++;x>>=1;
	}	
}
signed main()
{
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
    n=read();m=read();c=read();k=read();
	for(re i=1;i<=n;i++)
	{
		a[i]=read();
		deal(a[i]);
	}
	for(re i=1;i<=m;i++)
	{
		p=read();q=read();f[p]=1;
	}
	for(re i=0;i<k;i++)if(!f[i]||(b[i]&&f[i]))ans++;
	if(1<<ans<n)print(0);
	else print((1<<ans)-n);
    return 0;
}
