#include<bits/stdc++.h>
#define ll long long
#define cin(x) scanf("%lld",&x)
using namespace std;

struct Call{
	ll t;
	vector<ll> x;
}c[100050];
ll n,a[100050];ll b[1000050];

inline ll lb(ll x){return x&(-x);}
inline void add(ll i,ll k){
	while(i<=n){
		b[i]+=k;
		i+=lb(i);
	}
}
inline ll sum(ll i){
	ll ret=0;
	while(i>0){
		ret+=b[i];
		i-=lb(i);
	}
	return ret;
}
inline void call(ll f){
	ll tf=c[f].t;
	if(tf==1)
		add(c[f].x[0],c[f].x[1]);
	else if(tf==2){
		for(ll i=1;i<=n;i++)
			a[i]=(sum(i)-sum(i-1))*c[f].x[0];
		memset(b,0,sizeof(b));
		for(ll i=1;i<=n;i++)
			add(i,a[i]);
	}
	else if(tf==3){
		for(ll i=1;i<=c[i].x[0];i++)
			call(c[f].x[i]);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	ll m;
	cin(n);
	for(ll i=1;i<=n;i++){
		cin(a[i]);
		add(i,a[i]);
	}
	cin(m);
	for(ll i=1;i<=m;i++){
		cin(c[i].t);
		if(c[i].t==1){
			ll p,v;
			cin(p);cin(v);
			c[i].x.push_back(p);c[i].x.push_back(v);
		}
		else if(c[i].t==2){
			ll v;
			cin(v);
			c[i].x.push_back(v);
		}
		else if(c[i].t==3){
			ll y;
			cin(y);
			c[i].x.push_back(y);
			for(ll j=0;j<y;j++){
				ll g;
				cin(g);
				c[i].x.push_back(g);
			}
		}
	}
	ll q;
	cin(q);
	while(q--){
		ll f;
		cin(f);
		call(f);
	}
	for(ll i=1;i<=n;i++)
		a[i]=sum(i)-sum(i-1);
	for(ll i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}
