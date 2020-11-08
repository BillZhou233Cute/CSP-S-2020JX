#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int mod=998244353;
int n,m,c,k,ans,t1p[1001],t1v[1001],t2v[1001];
long long a[1001];
vector<int>t3[1001];
int tot1,tot2,tot3,zhi[1001],t[1001];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);ch=getchar();
	}
	return x*f;
}
void zhixing(int i)
{
	for(int j=0;j<t3[i].size();j++)
	{
		int k=t3[i][j];
		if(t[k]==1)
		{
			a[t1p[k]]+=t1v[k];
		}
		if(t[k]==2)
		{
			for(int g=1;g<=n;g++)
			a[g]*=t2v[k];
		}
		if(t[k]==3)
		{
			zhixing(k);
		}
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		t[i]=read();
		if(t[i]==1)
		{
			t1p[i]=read();t1v[i]=read();
		}
		if(t[i]==2)
		{
			t2v[i]=read();
		}
		if(t[i]==3)
		{
			int sum;
			sum=read();
			for(int j=1;j<=sum;j++)
			{
				int x;
				x=read();
				t3[i].push_back(x);
			}
		}
	}
	int q;
	q=read();
	for(int i=1;i<=q;i++)
	{
		zhi[i]=read();
		if(t[zhi[i]]==1)
		{
			a[t1p[zhi[i]]]+=t1v[zhi[i]];
		}
		if(t[zhi[i]]==2)
		{
			for(int j=1;j<=n;j++)
			a[j]*=t2v[zhi[i]];
		}
		if(t[zhi[i]]==3)
		{
			zhixing(zhi[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]%mod);
	}
	return 0;
}
