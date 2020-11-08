#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
#define N 1000005
using namespace std;
typedef unsigned long long ull;
int n,m,c,k;
ull read(){
	ull x=0;char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0')x=(x*10)+ch-'0',ch=getchar();
	return x;
}
ull a[N];
int v[66];
int x[N],y[N];
map<int,bool>mp;
vector<int>u[66];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	ull bas=0;
	rep(i,1,n)a[i]=read(),bas|=a[i];
	rep(i,0,k-1)if((bas>>i)&1)v[i]=1;
	rep(i,1,m){
		scanf("%d%d",&x[i],&y[i]);
		u[x[i]].push_back(y[i]);
		if(v[x[i]])mp[y[i]]=1;
	}
	int tot=0;
	rep(op,0,k-1){
		bool flag=true;
		for(int i=0;i<(int)u[op].size();i++)if(!mp.count(u[op][i]))flag=false;
		if(flag)tot++;
	}
	ull ans=0,pre=1;
	rep(i,0,tot-1)ans+=pre,pre<<=1;
	ans-=n;ans++;
	printf("%lld\n",ans);
	return 0;
}
/*
g++ zoo.cpp -o now -Wall
*/
