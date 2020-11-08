#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int read()
{
	int x=0;bool f=0;char ch=getchar();
	while ((ch<'0') || (ch>'9')) {if (ch=='-') f=1;ch=getchar();}
	while ((ch>='0') && (ch<='9')) {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	if (!f) return x;
	return -x;
}
int n,a[100010],num,sum=1,q,f;
int han[100010][3],k[1000010];
void wk(int f)
{
	if (han[f][0]==1) a[han[f][1]]=(a[han[f][1]]+han[f][2])%998244353;
	if (han[f][0]==2)
	{
		for (int j=1;j<=n;j++)
			a[j]=(a[j]*han[f][1])%998244353;
	}
	if (han[f][0]==3)
	{
		for (int i=han[f][2];i<han[f][2]+han[f][1];i++)
			wk(k[i]);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	num=read();
	for (int i=1;i<=num;i++)
	{
		han[i][0]=read();
		if (han[i][0]==1) han[i][1]=read(),han[i][2]=read();
		else if (han[i][0]==2) han[i][1]=read();
		else if (han[i][0]==3)
		{
			han[i][1]=read();
			han[i][2]=sum;
			for (int j=sum;j<sum+han[i][1];j++)
				k[j]=read();
			sum+=han[i][1];
		}
	}
	q=read();
	for (int i=1;i<=q;i++)
	{
		f=read();
		wk(f);
	}
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
