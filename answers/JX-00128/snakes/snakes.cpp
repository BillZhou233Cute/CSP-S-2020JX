#include<bits/stdc++.h>
#define ll long long
#define cin(x) scanf("%lld",&x)
using namespace std;

ll s[1000050],a[1000050];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ll T,t=0,dif=0;
	cin(T);
	while(t<T){
		ll ans,n;
		cin(n);
		if(t==0){
			dif=n;
			for(ll i=1;i<=n;i++){
				cin(a[i]);
				s[i]=a[i];
			}
		}
		else{
			for(ll i=1;i<=n;i++){
				ll x,y;
				cin(x);cin(y);
				a[x]=y;
			}
			for(ll i=1;i<=dif;i++)
				s[i]=a[i];
		}
		ans=dif;
		sort(s+1,s+dif+1);
		ll pj=1;
		for(ll i=1;i<dif&&pj;i++){
			if(s[dif]-s[i]>=s[dif-1]){
				ans--;
				s[dif]-=s[i];
			}
			else pj=0;
		}
		cout<<ans<<"\n";
		t++;
	}
	return 0;
}
