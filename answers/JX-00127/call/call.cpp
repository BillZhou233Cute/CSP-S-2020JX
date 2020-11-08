#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
using namespace std;
#define int long long
#define il inline
#define next nee
#define re register int
#define inf 1e18
il int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return x*f;
}
il void print(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x/10)print(x/10);
    putchar(x%10+'0');
}
const int N=1e5+5,Mod=998244353;
int n,m,a[N<<2],Q,add[N<<2];
bool b[N];
struct node{
	int T,x,y;
	vector<int>z;
}c[N];

il void build(int k,int l,int r)
{
	add[k]=1;
	if(l==r){a[k]=read();return;}
	int mid=l+r>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
il void ADD(int k,int l,int r,int v)
{if(l==r)a[k]=a[k]*v%Mod;else add[k]=add[k]*v%Mod;}
il void pushdown(int k,int l,int r,int mid)
{
	if(l==r){add[k]=1;return;}
	ADD(k<<1,l,mid,add[k]%Mod);ADD(k<<1|1,mid+1,r,add[k]%Mod);
	add[k]=1;
}
il void change1(int k,int l,int r,int x,int y)
{
	if(l==r){a[k]+=y;a[k]%=Mod;return;}
	int mid=l+r>>1;
	if(add[k]>1)pushdown(k,l,r,mid);
	if(x<=mid)change1(k<<1,l,mid,x,y);
	else change1(k<<1|1,mid+1,r,x,y);
}

il void deal(int x)
{
	vector<int>d;b[x]=1;
	for(re i=0;i<c[x].x;i++)
	{
		int y=c[x].z[i];
		if(c[y].T<3)d.push_back(y);
		else {
			if(!b[y])deal(y);
			for(re j=0;j<c[y].x;j++)d.push_back(c[y].z[j]);
		}
	}
	c[x].z=d;c[x].x=d.size();
}
il void act(int x)
{
	if(c[x].T==1){change1(1,1,n,c[x].x,c[x].y);return;}
	if(c[x].T==2){add[1]=add[1]*c[x].x%Mod;return;}
	if(c[x].T==3){
		for(re i=0;i<c[x].x;i++)act(c[x].z[i]);
	}
}
il void print1(int k,int l,int r)
{
	if(l==r){print(a[k]%Mod),putchar(' ');return;}
	int mid=l+r>>1;
	if(add[k]>1)pushdown(k,l,r,mid);
	print1(k<<1,l,mid);print1(k<<1|1,mid+1,r);
}
signed main()
{
    freopen("call.in","r",stdin);
    freopen("call.out","w",stdout);
    n=read();
	build(1,1,n);
	m=read();
	for(re i=1;i<=m;i++)
	{
		c[i].T=read();
		if(c[i].T==1)c[i].x=read(),c[i].y=read();
		else if(c[i].T==2)c[i].x=read();
		else if(c[i].T==3){
			c[i].x=read();
			for(re j=1;j<=c[i].x;j++)c[i].z.push_back(read());
		}
	}
	for(re i=1;i<=m;i++)
	if(c[i].T==3&&!b[i])deal(i);
	Q=read();
	for(re i=1;i<=Q;i++)act(read());
	print1(1,1,n);
    return 0;
}
