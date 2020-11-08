#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int read()
{
	int x=0;bool f=0;char ch=getchar();
	while ((ch<'0') || (ch>'9')) {if (ch=='-') f=1;ch=getchar();}
	while ((ch>='0') && (ch<='9')) {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	if (!f) return x;
	return -x;
}
int n,m,c,k,ani,ans,p,q,r;
bool f[70],w[70];
long long an;
int main()
{
	freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
	n=read();m=read();c=read();k=read();
	for (int i=1;i<=n;i++)
	{
		ani=read();
		while (ani)
		{
			int tmp=ani&(-ani);
			ani-=tmp;
			ans=0;
			while (tmp>1) tmp>>=1,ans++;
			w[ans]=1;
		}
	}
	/*for (int i=0;i<=70;i++)
		printf("%d",w[i]);*/
	an=1<<k;
	//cout << endl << an << endl;
	r=m;
	for (int i=1;i<=m;i++)
	{
		p=read();
		q=read();
		f[p]=1;
	}
	/*for (int i=0;i<=70;i++)
		printf("%d",f[i]);*/
	for (int i=0;i<70;i++)
		if ((f[i]) && (!(w[i]))) an>>=1;
	printf("%lld",an-((long long)n));
	return 0;
}
