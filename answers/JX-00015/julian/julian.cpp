#include<cstdio>
#define int ll
typedef long long ll;
int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int read() {
	register int x=0,f=1;register char s=getchar();
	while(s>'9'||s<'0') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main() {
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int Q=read();
	while(Q--) {
		int R=read()+1,flag=0;
		for(register int y=4713;y>=1;--y) {
			for(register int m=1;m<=12;++m) {
				for(register int d=1;d<=month[m]+(m==2)*((y-1)%4==0);++d) {
					--R;
					if(R==0) {flag=1;printf("%lld %lld %lld BC\n",d,m,y);}
				}		
				if(flag) break;
			}	
			if(flag) break;
		}
		for(register int y=1;y<=10000;++y) {	
			for(register int m=1;m<=12;++m) {
				for(register int d=1;d<=month[m]+(m==2)*((((y%4==0&&y%100!=0)||y%400==0)&&y>1582)||(y%4==0&&y<=1582));++d) {
					if(y==1582&&m==10&&d<=14&&d>=5) continue;
					--R;
					if(R==0) {flag=1;printf("%lld %lld %lld\n",d,m,y);}
				}
				if(flag) break;		
			}
			if(flag) break;
		}

	}
}
