#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)
#define ll long long

long long n,m,c,k;
long long a[1000010],q[100000010];
bool use[100];
ll u,siliao;

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
	for(long long i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		int x = a[i];
		u=u|a[i];
	}
	for(long long i = 1; i<= m; i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		q[y] |= (1<<x);
		if(!((1<<x)&u))siliao|=q[y];
	}
	int cnt = 0;
	for(int i = 0; i < k; i++){
		if((~(siliao >> i))&1)cnt++;
	}
	int base = 2;
	long long ans = 1;
	while(cnt){
		if(cnt&1)ans *= base;
		base *= base;
		cnt >>= 1;
	}
	cout<<ans - n<<endl;
	return 0;
}
