#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
#define N 1000005
#define int long long 
using namespace std;
int mon[13]={31,28,31,30,31,30,31,31,30,31,30,31};
int nom[13]={31,29,31,30,31,30,31,31,30,31,30,31};
typedef pair<int,int> Pr;
Pr get(int x,int op){
	if(!op){
		rep(i,0,11)if(x>=mon[i])x-=mon[i];else return make_pair(i+1,x);
	}
	else{
		rep(i,0,11)if(x>=nom[i])x-=nom[i];else return make_pair(i+1,x);
	}
	return make_pair(0,0);
}
void out(int x,int y,int z){
	z-=4713;
	if(z<0)printf("%lld %lld %lld BC\n",x,y,-z);
	else printf("%lld %lld %lld\n",x,y,z+1);
}
bool ok(int x){
	if(x%400==0)return 1;
	if(x%100==0)return 0;
	if(x%4==0)return 1;
	return 0;
}
void task(int x){
	int year=0,day=0,month=0;
	int bas=1461;
	int cur=min(1574LL,x/bas);
	x-=cur*bas;year+=cur*4;
	int st=cur*4-4712;
	rep(i,st,1583){
		if(i%4==0){
			if(x>=366)year++,x-=366;
			else{
				Pr now=get(x,1);
				month=now.first;
				day=now.second;
				out(day+1,month,year);
				return ;
			}
		}
		else{
			if(x>=365)year++,x-=365;
			else{
				Pr now=get(x,0);
				month=now.first;
				day=now.second;
				out(day+1,month,year);
				return ;
			}
		}
	}
	rep(i,max(st,1584LL),1600){
		if(ok(i)){
			if(x>=366)year++,x-=366;
			else{
				Pr now=get(x,1);
				month=now.first;
				day=now.second;
				out(day+1,month,year);
				return ;
			}
		}
		else{
			if(x>=365)year++,x-=365;
			else{
				Pr now=get(x,0);
				month=now.first;
				day=now.second;
				out(day+1,month,year);
				return ;
			}
		}
	}
	bas=146097;
	year+=x/bas*400;
	x%=bas;bas=36524;
	rep(i,1,3)if(x>=bas)year+=100,x-=bas;else {
		bas=1461;
		rep(j,1,24)if(x>=bas)year+=4,x-=bas;else{
			rep(k,1,3)if(x>=365)year++,x-=365;else{
				Pr now=get(x,0);
				month=now.first;
				day=now.second;
				out(day+1,month,year);
				return;
			}
			Pr now=get(x,1);
			month=now.first;
			day=now.second;
			out(day+1,month,year);
			return;
		}
		rep(j,1,4)if(x>=365)year++,x-=365;else {
			Pr now=get(x,0);
			month=now.first;
			day=now.second;
			out(day+1,month,year);
			return;
		}
		return;
	}
	bas=1461;
	rep(j,1,25)if(x>=bas)year+=4,x-=bas;else{
		rep(k,1,3)if(x>=365)year++,x-=365;else{
			Pr now=get(x,0);
			month=now.first;
			day=now.second;
			out(day+1,month,year);
			return;
		}
		Pr now=get(x,1);
		month=now.first;
		day=now.second;
		out(day+1,month,year);
		return;
	}
}
signed main(){
	//freopen("INPUT","r",stdin);
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	//freopen("OUTPUT","w",stdout);
	int T;scanf("%lld",&T);
	while(T--){
		int x;scanf("%lld",&x);
		if(x>2299160)x+=10;task(x);
	}
	return 0;
}
/*
g++ julian.cpp -o now -Wall 
*/
