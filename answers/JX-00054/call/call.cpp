#include<bits/stdc++.h>
#define N 100005
#define mod 998244353
#define int long long
using namespace std;
int n,a[N],add[N],mul=1;
int m,q,que[100005];
int func[3][100005];
vector<int>c[100005];
int tr1[100005],tr2[100005];
void run(int x)
{
	if(func[2][x]){
		for(int i=0;i<func[2][x];i++)
			run(c[x][i]);
	}
	else{
		if(func[1][x]!=-1){
			add[func[0][x]]=(add[func[0][x]]+func[1][x])%mod;
		}
		else{
			mul=(mul*func[0][x])%mod;
			for(int i=1;i<=n;i++)
				add[i]=(add[i]*func[0][x])%mod;
		}
	}
	return ;
}
signed main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++){
		int op;
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld",&func[0][i],&func[1][i]);
		}
		if(op==2){
			scanf("%lld",&func[0][i]);
			func[1][i]=-1;
		}
		if(op==3){
			scanf("%lld",&func[2][i]);
			for(int j=0,c0;j<func[2][i];j++)
				scanf("%lld",&c0),c[i].push_back(c0);
		}
	}
	scanf("%lld",&q);
	for(int i=1;i<=q;i++){
		scanf("%lld",que+i);
		run(que[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]=((mul%mod)*(a[i]%mod))%mod;
		a[i]=((a[i]%mod)+(add[i]%mod))%mod;
		cout<<a[i]<<" ";
	}
	return 0;
}
