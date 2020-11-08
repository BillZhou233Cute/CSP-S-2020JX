#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#define N 1000010
#define M 100
using namespace std;
#define ll long long

ll n,m,c,k;
ll a[N];
ll sum=0;
bool vis1[M],vis2[M];

int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9') f=(c=='-')?-1:1,c=getchar();
	while(c>='0' && c<='9') x=x*10+c-48,c=getchar();
	return x*f;
}

ll Pow(ll x,ll y){
	ll sum=1;
	for(ll i=1;i<=y;i++) sum*=x;
	return sum;
}

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	ll ans1=0,ans2=0;
	for(ll i=1;i<=m;i++){
		ll x=read(),y=read();
		if(!vis1[x]){vis1[x]=true;ans1++;}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=64;j++)
			if(a[i]&(1<<j) && !vis2[j] && vis1[j]){vis2[j]=true;ans2++;} 
	}
	printf("%lld\n",Pow(2,k-ans1+ans2)-n);
	fclose(stdin);fclose(stdout);
	return 0;
}
