#include<bits/stdc++.h>
#define ll unsigned long long
#define cin(x) scanf("%lld",&x)
using namespace std;

ll a[1000050],w[65],zn[65];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	ll n,m,c,k,M,mz=0;
	cin(n);cin(m);cin(c);cin(k);
	M=m;
	for(ll i=1;i<=n;i++)
		cin(a[i]);
	while(M--){
		ll q,p,b=1;
		cin(q);cin(p);
		zn[q]=1;
		for(ll i=1;i<=n&&b;i++){
			ll c=a[i]&(ll)pow(2,q);
			if(c){w[q]=1;b=0;}
		}
	}
	for(ll i=1;i<=64;i++)
		if((!w[i])&&zn[i])mz++;
	cout<<(ll)pow(2,k-mz)-n;
	return 0;
}
