#include<bits/stdc++.h>
using namespace std;
const int N=3e6+1;
int n,a[N],k;
inline int read()
{
	int x=0,y=0,z=getchar();
	while(!isdigit(z)&&(y=z=='-',1))z=getchar();
	while(isdigit(z))x=(x<<3)+(x<<1)+(z^48),z=getchar();
	return y?-x:x;
}
struct node{
	int num,v;
}aa[N];
bool pmp(const node &p,const node &q)
{
	return p.num>q.num;
}
int search(node x[],int l)
{
	if(l==2)return 1;
	int i,suml=1,sumr=1;
	for(i=2;i<=l;i++)if(x[i].v==x[1].v)suml++;
	if(suml>1)sort(x+1,x+suml+1,pmp);
	for(i=l-1;i>=1;i--)if(x[i].v==x[l].v)sumr++;
	if(sumr>1)sort(x+l-sumr+1,x+l+1,pmp);
	if(x[1].v-x[l].v<x[l-1].v||(x[1].v-x[l].v==x[l-1].v&&x[1].num<x[l-1].num))return l;
	x[1].v-=x[l].v;
	l-=1;
	
	int ls=2,rs=l,v=0;
	node y;
	while(ls<=rs)
	{
		if(x[1].v>=x[ls].v){v=1;break;}
		if(x[1].v<=x[rs].v){v=2;break;}
		ls++;
		rs--;
	}
	y.v=x[1].v;
	y.num=x[1].num;
	if(v==1)
	{
		for(i=1;i<ls-1;i++){x[i].v=x[i+1].v;x[i].num=x[i+1].num;}
		x[ls-1].v=y.v,x[ls-1].num=y.num;
	}
	else
	{
		for(i=1;i<rs;i++){x[i].v=x[i+1].v;x[i].num=x[i+1].num;}
		x[rs].v=y.v,x[rs].num=y.num;
	}
	
	search(x,l);
}
bool cmp(const node &p,const node &q)
{
	return p.v>q.v;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t,i,j,x,y;
	t=read();
	n=read();
	for(i=1;i<=n;i++)a[i]=read(),aa[i].v=a[i],aa[i].num=i;
	sort(aa+1,aa+n+1,cmp);
	printf("%d\n",search(aa,n));
	for(i=1;i<t;i++)
	{
		k=read();
		for(j=1;j<=k;j++)
		{
			x=read(),y=read();
			a[x]=y;
		}
		for(i=1;i<=n;i++)aa[i].v=a[i],aa[i].num=i;
		sort(aa+1,aa+n+1,cmp);
		printf("%d\n",search(aa,n));
	}
	return 0;
}