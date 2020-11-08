#include<cstdio>
#define N 1000003
#define int long long
int n,m,c,k,ans1,ans2;
bool cc[70];
inline int Read()
{
	int x=0,f=1;char c='?';
	while(c<'0'||c>'9')(c=='-')?f=-1,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
	return x*f;
}
int t1,t2,t3;
signed main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int xx=0,yy=0;
	n=Read();m=Read();c=Read();k=Read();
	for(int i=1;i<=n;i++)
	{
		t1=Read();xx|=t1;
	}
	for(int i=1;i<=m;i++)
	{

		t2=Read();Read();
		yy=yy|(1LL<<t2);
	}
	int kk=k;
	//printf("xxxxxxxxxx  xx=%lld yy=%lld kk=%lld\n",xx,yy,kk);
	for(int i=0;i<k;i++)
	{
		//printf("i=%lld yy=%lld xx=%lld\n",i,yy&(1LL<<i),xx&(1LL<<i));
		if((yy&(1LL<<i))&&(xx&(1LL<<i))==0)
		{
			kk--;
			//printf("i=%lld\n",i);
		}
	}
	//printf("kk=%lld\n",kk);
	printf("%lld\n",(1LL<<kk)-n);
	return 0;
}
