#include<bits/stdc++.h>
using namespace std;
int T,a[1000001],b[1000001],n,k,life;
int biggest(int n)
{
	int ans=1;
	for(int i=2;i<=n;i++)
	if(a[ans]>a[i]);
	else
	ans=i;
	return ans;
}
int small(int n)
{
	int ans=1;
	for(int i=2;i<=n;i++)
	if(a[ans]>a[i])
	ans=i;
	return ans;
}
int big(int n)
{
	int ans=1;
	int k=biggest(life);
	for(int i=2;i<=n;i++)
	if(a[ans]>a[i]||i==k);
	else
	ans=i;
	return ans;
}
void tciay()
{
	if(life>=3)
	{
	int s=biggest(life),z=big(life),y=small(life);
	if((a[s]-a[y]>a[z])||(a[s]-a[y]==a[z]&&s>z))
	{
	life--;
	for(int i=y;i<=life;i++)
	a[i]=a[i]+1;
	tciay();
    }
    }
}
int main()
{	
freopen("snakes.in","r",stdin);
freopen("snakes.out","w",stdout);
cin>>T;
for(int i=1;i<=T;i++)
{
	if(i==1)
	{
		cin>>n;
		life=n;
		for(int j=1;j<=n;j++)
		{
		cin>>a[j];
		b[j]=a[j];
		}
	}
	else
	{
		life=n;
		cin>>k;
		for(int j=1;j<=n;j++)
		{
		a[j]=b[j];
		}
		for(int i=1;i<=k;i++)
		{
		int x,y;
		cin>>x>>y;
		a[x]=y;
		}
	}
	tciay();
	if(life<3)
	cout<<1;
	else
	cout<<life<<endl;
}
return 0;
}