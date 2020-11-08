#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
long long b;
bool vis[700],f[100000005],v[700];
long long mi(long long a,long long b)
{
	long long res=1;
	while(b){
		if(b&1) res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++){
		int a;scanf("%d",&a);
		for(int j=k-1;j>=0;j--){
			if(a&(1<<j)){
				vis[j]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int a,b;scanf("%d%d",&a,&b);
		if(vis[a]==1) f[b]=1;
		else if((!vis[a])&&(!f[b])) v[a]=1;
	}
	for(int i=0;i<k;i++){
		if(v[i]==0) b++;
	}
	printf("%lld",mi((long long)2,b)-(long long)n);
	return 0;
}