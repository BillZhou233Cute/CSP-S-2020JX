#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define N 1000010
ll n,m,c,k;
ll a[N],p[N],q[N],rq[N];
ll sum=0,ans=0;
bool book[100];
ll first[N],cnt;
struct relation{
	ll fm,to,nt;
}e[N];

ll read()
{
	ll f=1,temp=0;char s;s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){temp=temp*10+s-'0';s=getchar();}
	return f*temp;
}

void add(ll u,ll v)
{
	cnt++;
	e[cnt].fm=u;e[cnt].to=v;
	e[cnt].nt=first[u];first[u]=cnt;
}

void dec(ll t)
{
	for(ll i=first[t];i!=0;i=e[i].nt)
		book[e[i].to]=true;
}

bool check(ll d)
{
	bool flag=true;
	for(ll i=first[d];i!=0;i=e[i].nt)
		if(!book[e[i].to])flag=false;
	return flag;
}

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read();m=read();c=read();k=read();
	
	for(ll i=1;i<=n;i++)a[i]=read();
		
	for(ll i=1;i<=m;i++){
		p[i]=read();q[i]=read();
		add(p[i],q[i]);}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;j<k;j++)
		{
			ll t;t=a[i]>>j;t=t%2;
			if(t==1)dec(j);
		}
	}
	
	for(ll i=0;i<k;i++)
		if(check(i))sum++;
	
	ans=(1<<sum)-n;
	printf("%lld",ans);
	return 0;
}