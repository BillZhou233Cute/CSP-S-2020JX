#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
int n,m,c,k,a[1000001],p[1000001],q[1000001];
int l,l2,temp2,temp1;
using namespace std;
int px(int g)
{
	int t=1;
	for(int i=1;i<=g;i++)
		t*=2;
	return t;
}
bool rr(int h,int g)
{
	return (h/(px(g)+1))%2;
}
bool rrr(int h,int g)
{
	return (h/(px(g)))%2;
}
int main(){
	freopen("zoo2.in","r",stdin);
	//freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)	{cin>>a[i];l2+=px(a[i]);}
	for(int i=1;i<=m;i++)	cin>>p[i]>>q[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(rr(a[i],p[j])&&!rr(l,q[j]))	l+=px(q[j]);	
		}
	for(int i=0;i<=px(k)-1;i++)
	if(!rr(l2,i))	
	{
		temp1=1;
		for(int j=1;j<=m;j++)
			if(rr(a[i],p[j])&&rr(a[i],p[j])!=rrr(l,p[j]))	
				{temp1=0;}
		if(temp1)	++temp2;
	}
	cout<<temp2;
	return 0;
}