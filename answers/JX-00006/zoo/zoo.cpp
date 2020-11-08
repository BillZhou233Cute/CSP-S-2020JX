#include <iostream>
#include <cstdio>
#define ll unsigned long long

using namespace std;

int n,m,c,k,cnt;
ll need,sum;
bool vis[70];

ll mul(int x);

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	ll x;
	for(int i=1;i<=n;i++){
		scanf("%llu",&x);
		need|=x;
	}
	int a,b;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(a>k)
			continue ;
		if(!(mul(a)&need)&&!vis[a]){
			vis[a]=1;
			cnt++;
		}
	}
	ll sum=mul(k-cnt);
	sum-=n;
	printf("%llu",sum);
	return 0;
}	
ll mul(int x){
	ll y=1;
	for(int i=1;i<=x;i++)
		y*=2;
	return y;
}	