#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1005;
const long long MOD = 998244353;
long long a[MAXN],t1[MAXN][2],t2[MAXN],t3[MAXN][MAXN];
int n,m,q;

void tf(int op){
	a[t1[op][0]] = (a[t1[op][0]] + (t1[op][1] % MOD)) % MOD;
}

void ts(int op){
	for(int j=1;j<=n;j++) a[j] = (a[j] * (t2[op] % MOD)) % MOD;
}

void tt(int op){
	for(int i=1;i<=t3[op][0];i++){
		if(t1[t3[op][i]][0]) tf(t3[op][i]);
		else  if(t2[t3[op][i]]) ts(t3[op][i]);
		else tt(t3[op][i]);
	}
}

int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int t;
		scanf("%d",&t);
		if(t == 1) scanf("%lld %lld",&t1[i][0],&t1[i][1]);
		else if(t == 2) scanf("%lld",&t2[i]);
		else{
			scanf("%lld",&t3[i][0]);
			for(int j=1;j<=t3[i][0];j++) scanf("%lld",&t3[i][j]);
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int op;
		scanf("%d",&op);
		if(t1[op][0]) tf(op);
		else if(t2[op]) ts(op);
		else tt(op);
	}
	for(int i=1;i<n;i++) printf("%lld ",a[i]);
	printf("%lld",a[n]);
	return 0;
}