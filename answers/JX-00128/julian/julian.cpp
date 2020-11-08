#include<bits/stdc++.h>
#define ll long long
#define cin(x) scanf("%lld",&x)
using namespace std;

ll Y=-4713,ff=1461,ybc=1721424,yg=577737,fby=146097;
ll m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll rbc[4714]={-1};
inline bool run(ll x){
	ll y;
	y=(ll)abs(x)-(ll)(x<0);
	if(y%400==0)return 1;
	else if(y%4==0&&(y%100!=0||x<=1582))return 1;
	else return 0;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	ll q;
	cin(q);
	for(ll i=-1;i>=Y;i--)
		rbc[-1*i]=run(i);
	while(q--){
		ll r,sy=-4713,sm=1,sd=1;
		cin(r);
		if(ybc>r){
			ll ay;
			ay=(ll)(r-r%ff)/ff;
			r%=ff;
			sy+=4*ay;
			for(ll i=1;i<=r;i++){
				sd++;
				if(sd>m[sm]+(ll)(sm==2&&rbc[-1*sy])){
					sm++;
					sd=1;
				}
				if(sm>12){
					sy++;
					sm=1;
				}
			}
			cout<<sd<<' '<<sm<<' '<<-1*sy<<" BC"<<endl;
		}
		else{
			r-=ybc;
			sy=1;
			if(r<yg){
				ll ay=0;
				ay=(ll)(r-r%ff)/ff;
				r%=ff;
				sy+=4*ay;
				for(ll i=1;i<=r;i++){
					sd++;
					if(sd>m[sm]+(ll)(sm==2&&run(sy))){
						sm++;
						sd=1;
					}
					if(sm>12){
						sy++;
						sm=1;
					}
				}
				cout<<sd<<' '<<sm<<' '<<sy<<endl;
			}
			else{
				r-=yg;
				sy=1582;sm=10;sd=15;
				ll ay=0;
				ay=(ll)(r-r%fby)/fby;
				r%=fby;
				sy+=400*ay;
				for(ll i=1;i<=r;i++){
					sd++;
					if(sd>m[sm]+(ll)(sm==2&&run(sy))){
						sm++;
						sd=1;
					}
					if(sm>12){
						sy++;
						sm=1;
					}
				}
				cout<<sd<<' '<<sm<<' '<<sy<<endl;
			}		
		}
	}
	return 0;
}
