#include<bits/stdc++.h>
#define LL long long
#define re register
#define IL inline
#define mod 998244353
using namespace std;

IL bool isnum(char ch)
{
	return ch>='0'&&ch<='9';
}
IL LL read()
{
	re LL x=0,fu=1;
	char ch=getchar();
	while(!isnum(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	while(isnum(ch)) x=(x<<3)+(x<<1)+(ch-'0'),ch=getchar();
	return x*fu;
}
/*******
*array size
*freopen
*delete debug
*test again
*********/
int n;
int q;
int o;
LL a[100010];
struct node
{
	int l,r;
	LL m;
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define m(x) b[x].m
}b[400040];
void build(int l,int r,int p)
{
	l(p)=l;
	r(p)=r;
	m(p)=1;
	if(l==r)
	{
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
}
void spread(int p)
{
	if(m(p))
	{
		if(l(p)==r(p))
		{
			a[l(p)]=a[l(p)]*m(p)%mod;
		}
		else
		{
			m(p<<1)=m(p)*m(p<<1)%mod;
			m(p<<1|1)=m(p<<1|1)*m(p)%mod;
		}
		m(p)=1;
	}
}
void change_one(int p,int x,LL k)
{
	spread(p);
	if(l(p)==r(p))
	{
		a[l(p)]=m(p)*a[l(p)]%mod;
		m(p)=1;
		a[l(p)]+=k;
		return;
	}
	int mid=(l(p)+r(p))>>1;
	if(x<=mid) change_one(p<<1,x,k);
	else change_one(p<<1|1,x,k);
}
void rash(int p)
{
	spread(p);
	if(l(p)==r(p)) return;
	rash(p<<1);
	rash(p<<1|1);
}
struct Order
{
	int t,p,v;
}order[1000010];
int cnt;
vector<int>ord[1000010];//real
vector<int>son[1000010];
bool opened[100010];
void dfs(int x)
{
	if(opened[x]) return;
	opened[x]=1;
	for(int i=0;i<son[x].size();i++)
	{
		dfs(son[x][i]);
		for(int j=0;j<ord[son[x][i]].size();j++)
		{
			ord[x].push_back(ord[son[x][i]][j]);
		}
	}
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(re int i=1;i<=n;i++) a[i]=read();
	build(1,n,1);
	o=read();
	for(re int i=1,t,x,y;i<=o;i++) 
	{
		t=read();
		if(t==1||t==2)
		{
			if(t==1) x=read();
			else x=0;
			y=read();
			order[++cnt]=(Order){t,x,y};
			ord[i].push_back(cnt);
		}
		else
		{
			x=read();
			while(x--) son[i].push_back(read());
		}
	}
	for(re int i=1;i<=o;i++)
	{
		if(!opened[i]) dfs(i);
	}
	q=read();
	int now,t,p,v;
	while(q--)
	{
		now=read();
		for(re int i=0;i<ord[now].size();i++)
		{
			t=order[ord[now][i]].t;
			p=order[ord[now][i]].p;
			v=order[ord[now][i]].v;
			if(t==1)
			{
				change_one(1,p,v);
			}
			else
			{
				m(1)=v*m(1)%mod;
			}
		}
	}
	rash(1);
	for(re int i=1;i<=n;i++) cout<<a[i]%mod<<" ";
	return 0;
}
/*******
*array size
*freopen
*delete debug
*test again
*********/