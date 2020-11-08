#include<bits/stdc++.h>
using namespace std;
const int sz=1e6+1;
int n,m,a[sz],c[sz<<1],i,j,k,x[sz],y[sz],z[sz],t,o,cc;
vector<int>b[sz];
int lt(int x){return -x&x;}
void add(int x,int y){for(int i=x;i<=n;i+=lt(i))c[i]+=y;}
void cf()
{
	if(!cc)return;
	for(int i=1;i<=n;++i)c[i]*=cc;
	cc=0;
}
int gt(int x)
{
	int s=0,i;
	for(i=n;i>=x;i-=lt(i))s+=c[i];
	return s;
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]),add(i,a[i]);
	scanf("%d",&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]==1)scanf("%d",&z[i]);
		if(x[i]==3)for(j=1;j<=y[i];++j)scanf("%d",&k),b[i].push_back(k);
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&o);
		if(x[o]==1){cf();add(y[o],z[o]);add(y[o]+1,-z[o]);}
		if(x[o]==2)cc=y[o];
		if(x[o]==3)
		{
			for(i=0;i<y[o];++i)
			{
				if(x[o]==1){cf();add(y[b[o][i]],z[b[o][i]]);add(y[b[o][i]]+1,-z[b[o][i]]);}
				if(x[o]==2){cf();cc=z[b[o][i]];}
			}
		}
	}
	for(i=1;i<=n;++i)printf("%d",gt(i)-gt(i-1));
	return 0;
}