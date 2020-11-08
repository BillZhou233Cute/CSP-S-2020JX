#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#define ri register int
using namespace std;
int n,m,c,k;
inline int read()
{
	int s=0,tmp=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')tmp=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0',ch=getchar();}
	return s*tmp;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	long long ans=0;
	n=read(),m=read(),c=read(),k=read();
	for(ri i=1;i<=n;++i)
	{
		long long a;
		scanf("%lld",&a);
		ans=ans|a;
	}
	 long long tmp=1;
	long long tot=0;
	while(tmp<=ans)
	{
		if(tmp&ans)
		{
			if(tot==0)tot=2;
				else tot*=2;
		}
		tmp*=2;
	}
	for(ri i=1,p,q;i<=m;++i)
	{
		p=read(),q=read();
	}
	printf("%lld",tot-n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}