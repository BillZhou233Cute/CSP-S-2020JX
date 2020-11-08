#include<cstdio>
#define MOD 998244353
#define N 200003
#define M 1100003
int n,m,a[N],j[N],chen=1,tmp[M];
int head[N],tot;
struct Edge
{
	int next,to;
}e[M];
struct F
{
	int t;
	int p;
	int v;
}d[N];

inline void Add(int a,int b)
{
	e[++tot].next=head[a];
	e[tot].to=b;
	head[a]=tot;
}
inline int Read()
{
	int x=0,f=1;char c='?';
	while(c<'0'||c>'9')(c=='-')?f=-1,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
	return x*f;
}
void dfs(int u)
{
	if(d[u].t==1)
	{
		a[d[u].p]=(a[d[u].p]+d[u].v)%MOD;
		//int t=0;
		//t=(a[d[u].p]+j[d[u].p])*chen+d[u].v;
		//j[d[u].p]=t/chen-a[d[u].p];
	}
	if(d[u].t==2)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=(a[i]*d[u].v)%MOD;
		}
	}
	if(d[u].t==3)
	{
		for(int i=head[u];i;i=e[i].next)
		{
			dfs(e[i].to);
		}
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int t1,t2,t3;
	n=Read();
	for(int i=1;i<=n;i++)a[i]=Read();
	m=Read();
	for(int i=1;i<=m;i++)
	{
		t1=Read();
		if(t1==1)
		{
			d[i].t=1;
			d[i].p=Read();
			d[i].v=Read();
		}
		else if(t1==2)
		{
			d[i].t=2;
			d[i].v=Read();
		}
		else
		{
			d[i].t=3;
				t3=Read();
				for(int j=1;j<=t3;j++)
				{
					tmp[j]=Read();
				}
				for(int j=t3;j>0;j--)
				{
					Add(i,tmp[j]);
				}
		}
	}
	int Q=Read();
	while(Q--)
	{
		t1=Read();
		dfs(t1);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
