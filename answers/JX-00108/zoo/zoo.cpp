#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#define int long long
using namespace std;
int n,m,c,k;
int hash[1000005];
int a[1000005],p[1000005],q[1000005];
bool v[70],t[1000005],ct[70];
int h(int p)
{
	int k=p;
	int sum=0;
	int i=1;
	while(k)
	{
		int l=k%10;
		k>>=1;
		sum+=i*l;
		i++;
	}
	return(sum*sum+k)%1000005;
}
void getbt(int t)
{
	int i=0;
	while(t)
	{
		if(t&1) v[i]=true;
		t>>=1;i++;
	}
}
signed main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	memset(v,false,sizeof v);
	memset(ct,true,sizeof ct);
	cin >> n >> m >> c >> k;
	for(int i=1;i<=n;i++) {scanf("%d",a+i);getbt(a[i]);}
	//for(int i=0;i<8;i++) cout << v[i] <<' ';
	for(int i=1;i<=m;i++) {scanf("%d%d",p+i,q+i);if(v[p[i]]) /*mapp.insert(q[i],q[i]);*/hash[h(q[i])]=1;}//mapp bought
	//for(int i=1;i<64;i++)
	for(int i=1;i<=m;i++)
	{
		if(/*mapp.find(q[i])==-1*/!hash[h(q[i])])  ct[p[i]]=false;
	}
	//for(int i=0;i<8;i++) cout << ct[i] <<' ';
	int num=0;
	for(int i=0;i<k;i++) if(ct[i]) num++;
		int ans=((long long)1<<num)-n;
		cout << ans;
		return 0;
}