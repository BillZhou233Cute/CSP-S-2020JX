#include <cstdio>
#include <iostream>
using namespace std;

unsigned long long cx,nx;
unsigned long long n,m,c,k;

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%llu %llu %llu %llu",&n,&m,&c,&k);
	for(int i=1;i<=n;i++){
		unsigned long long a;
		scanf("%llu",&a);
		nx |= a;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		cx = (unsigned long long) cx | (1<<a);
	}
	nx &= cx;nx = cx - nx;
	if(nx == 0) printf("%llu",(1<<k)-n);
	else {
		unsigned long long ans = 1,a = 1;
		for(int i=1;i<=k;i++){
			if(nx & 1) ans *= a,a = 1;
			else a *= 2;
			nx >>= 1;
		}
		printf("%llu",ans*a-n);
	}
	return 0;
}