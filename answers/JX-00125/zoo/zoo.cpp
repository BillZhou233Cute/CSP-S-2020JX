#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000005;
int n,m,c,k,a[N],v[100],v1[100];

signed main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		int o = a[i],j = 0;
		while(o){
			if(o & 1) v[j] = 1; 
			o >>= 1;
			j++;
		}
	} 
	for(int i = 1,x,y;i <= m;i++){
		scanf("%d%d",&x,&y);
		if(v1[x]) continue;
		v1[x] = 1;
		if(v[x]) continue;
		k--;
	}
	printf("%lld\n",(1 << k) - n);
	return 0;
}
