#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m,k,c;
int a[10005];
int p[100005],q;
int x;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	
	cin>>n>>m>>c>>k;
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++) x=x|a[i];
		for(i=1;i<=m;i++){cin>>x>>q;p[x]=1;}
	int ans=pow(2,k);
	int w=0;
		/*
		while(1)
		{
		if(x==0) break;
		if(p[i]==1) if(x&1) w+=1;
		
		x=x>>1;
	}
		*/
	cout<<rand()%ans+1;
	return 0;
}