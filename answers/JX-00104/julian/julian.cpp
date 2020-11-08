#include<bits/stdc++.h>
using namespace std;
long long q;
int y,m,d,a[13]={31,29,31,30,31,30,31,31,30,31,30,31},b[13]={31,28,31,30,31,30,31,31,30,31,30,31},c[5]={365,365,365,366};
inline long long read(){
	int x=0;
	bool flag=0;
	char ch;
	do{
		ch=getchar();
		if(ch=='-'){
			flag=1;
		}
	}while(!(ch>='0'&&ch<='9'));
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	if(flag){
		return -x;
	}
	return x;
}
bool run(int year){
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				return 1;
			}
			return 0;
		}
		return 1;
	}
	return 0;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	while(q--){
		long long x=read();
		if(x<=365){
			y=4713;
			for(int i=0;i<12;i++){
				if(x>=a[i]){
					x-=a[i];
				}else{
					m=i+1;
					d=1+x;
					break;
				}
			}
			printf("%d %d %d BC\n",d,m,y);
		}else{
			if(x<=1721423){
				y=4713;
				int t=x/1461;
				t*=4;
				y-=t;
				x%=1461;
				for(int i=0;i<4;i++){
					if(x>c[i]){
						x-=c[i];
					}else{
						if(i==3){
							y-=3;
							for(int j=0;j<12;j++){
								if(x>a[j]){
									x-=a[j];
								}else{
									m=j+1;
									d=x;
									break;
								}
							}
							printf("%d %d %d BC\n",d,m,y);
						}else{
							y-=i;
							for(int j=0;j<12;j++){
								if(x>b[j]){
									x-=b[j];
								}else{
									m=j+1;
									d=x;
									break;
								}
							}
							printf("%d %d %d BC\n",d,m,y);
							break;
						}
					}
				}
			}else{
				y=0;
				if(x<2299191){
					x-=1721423;
					int t=x/1461;
					t*=4;
					x%=1461;
					y+=t;
					for(int i=1;i<4;i++){
						if(x>c[i]){
							x-=c[i];
						}else{
							if(i==3){
							y+=3;
							for(int j=0;j<12;j++){
								if(x>a[j]){
									x-=a[j];
								}else{
									m=j+1;
									d=x+1;
									break;
								}
							}
							printf("%d %d %d\n",d,m,y);
						}else{
							y+=i;
							for(int j=0;j<12;j++){
								if(x>b[j]){
									x-=b[j];
								}else{
									m=j+1;
									d=x+1;
									break;
								}
							}
							printf("%d %d %d\n",d,m,y);
							break;
						}
						}
					}
				}else{
					x-=2299190;
					x+=30;
					y=1582,m=10,d=15;
					if(x<=78){
						if(x<=17){
							printf("%d 10 1582",14+x);
						}else{
							x-=17;
							if(x<=30){
								printf("%d 11 1582",x);
							}else{
								x-=30;
								printf("%d 12 1582",x);
							}
						}
					}else{
						x-=78;
						int t=x/146097;
						t*=400;
						y=t;
						x%=146097;
						for(int i=1583;i<=1982;i++){
							int d;
							if(run(i)){
								d=366;
							}else{
								d=365;
							}
							if(x>d){
								x-=d;
							}else{
								if(run(i)){
									for(int j=0;j<12;j++){
										if(x>a[j]){
											x-=a[j];
										}else{
											d=x;
											m=j+1;
											y+=i;
											break;
										}
									}
									printf("%d %d %d\n",d,m,y);
									break;
								}else{
									for(int j=0;j<12;j++){
										if(x>b[j]){
											x-=b[j];
										}else{
											d=x;
											m=j+1;
											y+=i;
											break;
										}
									}
									printf("%d %d %d\n",d,m,y);
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}