#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN=1000010;
int n,m,c,k,i,j,a[MAXN],p[MAXN],q[MAXN],tot,b[MAXN],cnt;
bool f[MAXN];
unsigned long long num=0,s1=0,s2=0,s3=0,s4=0,ans,mi;

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[a[i]]=true;
		num|=a[i];
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&p[i],&q[i]);
		s2|=q[i];
		if(num&(1<<p[i])) s1|=q[i];
	}
	s3=s1^s2;
	for(i=1;i<=c;i++)
	if(s3&(1<<i)) b[++cnt]=p[i];
	ans=1;mi=1;
	for(i=1;i<=k;i++)
	{mi*=2;ans*=2;}
	ans-=n;
	if(!s3)
	{
		if(ans<0) ans=0;
		printf("%lld",ans);
	}
	else
	{
		ans=0;
		 for(unsigned long long i=1;i<=mi;i++)
		 {
			 bool f1=false;
			 if(f[i]) continue;
			 else
			 {
				 for(j=1;j<=cnt;j++)
				 {
					 if(i&(1<<b[j])) {f1=true;break;}
					 else continue;
				 }
				 if(f1) continue;
					else ans++;
			 }
		 }
		    if(ans<0) ans=0;
			printf("%lld",ans);
	}
	return 0;
}