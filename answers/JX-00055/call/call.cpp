#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100010
#define M 1000010
#define MOD 998244353
ll n,m,c,q;
ll a[N],tag[N*4];
ll ty[M],p[M],v[M];
ll cnt,first[M];
struct relation{
	ll fm,to,nt;
}e[M];

ll read()
{
	ll f=1,temp=0;char s;s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){temp=temp*10+s-'0';s=getchar();}
	return f*temp;
}

void add(int u,int v)
{
	cnt++;
	e[cnt].fm=u;e[cnt].to=v;
	e[cnt].nt=first[u];first[u]=cnt;
}

void build(ll k,ll l,ll r)
{
	tag[k]=1;
	if(l==r)return;
	ll mid=(l+r)>>1;
	build(k*2,l,mid);build(k*2+1,mid+1,r);
}

void pd(ll k,ll l,ll r)
{
	if(l==r)return;
	if(tag[k]==1)return;
	tag[k*2]=(tag[k*2]*tag[k])%MOD;
	tag[k*2+1]=(tag[k*2+1]*tag[k])%MOD;
	tag[k]=1;
}

void tplus(ll k,ll l,ll r,ll tp,ll d)
{
	if(l==r&&l==tp){
		a[l]=(a[l]*tag[k]%MOD+d)%MOD;tag[k]=1;return;}
	pd(k,l,r);
	ll mid=(l+r)>>1;
	if(tp<=mid)tplus(k*2,l,mid,tp,d);
	if(tp>mid)tplus(k*2+1,mid+1,r,tp,d);
}

void tmult(ll d)
{
	tag[1]=(tag[1]*d)%MOD;
}

void deal(ll);

void dddo(ll k)
{
	if(k==0)return;
	dddo(e[k].nt);
	deal(e[k].to);
}

void deal(ll k)
{
	if(ty[k]==1)tplus(1,1,n,p[k],v[k]);
	if(ty[k]==2)tmult(v[k]);
	if(ty[k]==3)
		dddo(first[k]);
}

void getans(ll k,ll l,ll r)
{
	if(l==r){a[l]=a[l]*tag[k]%MOD;return;}
	ll mid=(l+r)/2;
	pd(k,l,r);
	getans(k*2,l,mid);getans(k*2+1,mid+1,r);
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	m=read();
	for(ll i=1;i<=m;i++)
	{
		ty[i]=read();
		if(ty[i]==1){p[i]=read();v[i]=read();}
		if(ty[i]==2)v[i]=read();
		if(ty[i]==3){
			c=read();
			while(c--)add(i,read());
		}
	}
	q=read();
	while(q--) deal(read());
	getans(1,1,n);
	for(ll i=1;i<=n;i++)printf("%lld ",a[i]);
	return 0;
}