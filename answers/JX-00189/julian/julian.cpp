#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#include<cstring>
#include<queue>
using namespace std;
#define ll long long
inline void rd(int &x){
	x=0;bool flag=0;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){flag=1;ch=getchar();};
	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
	if(flag)x=-x;
}
inline void rd(ll &x){
	x=0;bool flag=0;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){flag=1;ch=getchar();};
	while(ch>='0'&&ch<='9')x=x*10ll+(ch-'0'),ch=getchar();
	if(flag)x=-x;
}
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
const ll A=1721424;//-
const ll B=2298884;//1582
const ll C=2299239;//1583
const ll D=2305448;//1600
const ll E=146097;
const ll F=1721423-1721058;
ll n,x,y,z;
inline void wk(){
	while(n){
		if(x%4==0&&((x%100==0&&x%400==0)||(x%100!=0))){
			if(n<366)break;
			else n-=366,++x;
		}else{
			if(n<365)break;
			else n-=365,++x;
		}
	}
}
inline void work(){
	y=1;z=1;
	if(x%4==0&&((x%100==0&&x%400==0)||(x%100!=0))){
		while(n){
			if(n>=b[y]){
				n-=b[y];
				++y;
			}else{
				z+=n;
				break;
			}
		}
	}else{
		while(n){
			if(n>=a[y]){
				n-=a[y];
				++y;
			}else{
				z+=n;
				break;
			}
		}
	}
}
void exwork(){
	y=1;z=1;
	while(n){
		if(y==10){
			if(n<=3){
				z+=n;break;
			}else{
				n-=4;
				z=15;
				if(n<=16){
					z+=n;break;
				}else{
					++y;z=1;n-=17;
				}
			}
		}else{
			if(n>=a[y]){
				n-=a[y];
				++y;
			}else{
				z+=n;
				break;
			}
		}
	}
}
inline void wok(){
	while(n){
		if(x%4==0){
			if(n<366)break;
			else n-=366,++x;
		}else{
			if(n<365)break;
			else n-=365,++x;
		}
	}
	y=1;z=1;
	if(x%4==0){
		while(n){
			if(n>=b[y]){
				n-=b[y];
				++y;
			}else{
				z+=n;
				break;
			}
		}
	}else{
		while(n){
			if(n>=a[y]){
				n-=a[y];
				++y;
			}else{
				z+=n;
				break;
			}
		}
	}
}
inline void rok(){
	while(n){
		if(x%4==0){
			if(n<366)break;
			else n-=366,--x;
		}else{
			if(n<365)break;
			else n-=365,--x;
		}
	}
	y=1;z=1;
	if(x%4==0){
		while(n){
			if(n>=b[y]){
				n-=b[y];
				++y;
			}else{
				z+=n;
				break;
			}
		}
	}else{
		while(n){
			if(n>=a[y]){
				n-=a[y];
				++y;
			}else{
				z+=n;
				break;
			}
		}
	}
}
inline void print(){
	printf("%lld %lld %lld\n",z,y,x);
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int t;rd(t);
	while(t--){
		rd(n);x=y=z=0;
		if(n<=A){
			x=4712;
			rok();
			++x;
			printf("%lld %lld %lld BC\n",z,y,x);
		}else if(n<=B){
			n-=A;x=1;
			wok();print();
		}else if(n<=C){
			n-=B;
			x=1582;
			exwork();print();
		}else if(n<=D){
			n-=C;x=1583;
			wk();
			work();print();
		}else{
			n-=D;
			x=1600;
			x+=400*(n/E);
			n%=E;
			wk();
			work();print();
		}
	}
	return 0;
}
