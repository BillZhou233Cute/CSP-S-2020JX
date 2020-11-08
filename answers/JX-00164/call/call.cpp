#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long a[100010],n,m,tag[100010],tag1[100010],b[100010],j[100010],c[100010],q,x[100010],dx[100010];
vector<int>d[100010];
void ch(int now)
{
	if(b[now]==1)a[dx[now]]+=j[now];
		if(b[now]==2){
			for(int j=1;j<=n;j++)
				a[j]*=c[now];
		}
	if(b[now]==3){
		for(int i=0;i<d[now].size();i++)
			ch(d[now][i]);
	}
	return;
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]==1)scanf("%d%d",&dx[i],&j[i]);
		if(b[i]==2)scanf("%d",&c[i]);
		if(b[i]==3){
			scanf("%d",&j[0]);
			for(int k=1;k<=j[0];k++)
				scanf("%d",&c[0]);
			d[i].push_back(c[0]);
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=q;i++)
	{
		ch(x[i]);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}