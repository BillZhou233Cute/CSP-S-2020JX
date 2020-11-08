#include<bits/stdc++.h>
using namespace std;
long long n,m,c,k,a[1000001],p,q,b[1000001],cc,kk;
long long s[1000001][65];
inline long long read()
{
	long long x=0;
	char c=getchar();
	bool flag=0;
	while(c>'9'||c<'0')
	{
		if(c=='-') flag=1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	if(flag) x=-x;
	return x;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(), c=read(),k=read();
	for(long long i=1;i<=n;i++) 
	{
		a[i]=read();
		long long j=0;
		while(a[i])
		{
			s[i][j++]=a[i]%2;
			//cout<<s[i][j-1]<<endl;
			a[i]/=2;
		}j--;
		if(j<k-1)
		{
			for(long long l=k-1-j;l<k;l++) s[i][l]=s[i][l-k+j+1];
			for(long long l=0;l<k-1-j;l++) s[i][l]=0;
		}
		//for(long long l=0;l<=k-1;l++) cout<<s[i][l];
		//cout<<endl;
	}
	for(long long i=1;i<=m;i++) 
	{
		long long z=0;
		p=read(),q=read();
		for(long long i=1;i<=n;i++) 
		if(s[i][p]) 
		{
			if(!b[i])
			b[i]=1,kk++;
			if(!z) cc++,z=1;
		}
	}
	long long ans=pow(2,cc)-kk;
	printf("%lld\n",ans);
	return 0;
}
