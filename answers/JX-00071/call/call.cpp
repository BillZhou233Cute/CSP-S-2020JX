#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5 +10;
const ll mod = 998244353;
int n,m,q,ct;
ll a[MAXN];
ll T[MAXN][3];
ll diao[1000010];
bool flag;

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	scanf("%d",&m);
	for(int i = 1; i <= m; i++){
		scanf("%lld",&T[i][0]);
		if(T[i][0] == 1)
			scanf("%lld%lld",&T[i][1],&T[i][2]);
		if(T[i][0] == 2)
			scanf("%lld",&T[i][1]);
		if(T[i][0] == 3){
			flag = 1;
			scanf("%lld",&T[i][1]);
			T[i][2] = ct;
			for(int j = 1; j <= T[i][1];j++){
				scanf("%lld",&diao[ct++]);
			}
		}
	}
	if(!flag){
		ll c = 1;
		scanf("%d",&q);
		while(q--){
			int t;
			scanf("%d",&t);
			if(T[t][0] == 1){
				a[T[t][1]] = (a[T[t][1]] + (T[t][2])) % mod;
			}
			else{
				for(int i = 1;i <= n;i++){
					a[i] *= T[t][1];
				}
			}
		}
		for (int i = 1; i <= n; i++){
			printf("%lld ",a[i] % mod);
		}
	}
	else{
		ll c = 1;
		scanf("%d",&q);
		while(q--){
			int t;
			scanf("%d",&t);
			if(T[t][0] == 1){
				a[T[t][1]] = (a[T[t][1]] + (T[t][2])) % mod;
			}
			else if(T[t][0] == 2)
				for(int i = 1;i<=n;i++){
					a[i] *= T[t][1];
				}
			else{
				int end = T[t][2] + T[t][1];
				for(int i = T[t][2];i < end;i++){
//					cout<<"!"<<endl;
					if(T[diao[i]][0] == 1){
						a[T[diao[i]][1]] = (a[T[diao[i]][1]] + (T[diao[i]][2]))%mod;
					}
					else{
						for(int j = 1;j<= n;j++){
							a[j] *= T[diao[i]][1];
						}
					}
	//				for(int j =1;j<=n;j++){
	//					cout<<a[j]<<' ';
	//				}
	//				cout<<endl;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			printf("%lld ",a[i]% mod);
		}
	}
	return 0;
}
