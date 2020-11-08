#include<bits/stdc++.h>
using namespace std;
const int sz=1e6+1;
int n,m,c,k,i,j,x,y,fg,s,f[65];
struct nd{int x,y,z,id;}a[sz];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(i=1;i<=n;++i)scanf("%d",&a[i].id);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		f[a[i].x]=1;
	}
	s+=f[0];c=1ll<<k;
	for(i=1;i<=c;++i)
	{
		y=0;x=i<<1;fg=1;
		while(x){++y;x>>=1ll;if(x&1&&!f[y]){fg=0;break;}}
		s+=fg;
	}
	printf("%d\n",s);
	return 0;
}