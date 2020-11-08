#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();long long f=1,x=0;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f*x;
}
long long month[]={0,31,28,31,30,31,30,31,31,30,31,30,31},q,x;
void work1(){
	for(int i=4713;;i--){
		if(i%4==1){
			if(x>366)x-=366;
			else{
				month[2]++;
				for(int j=1;j<=12;j++){
					if(x>month[j])x-=month[j];
					else{
						printf("%lld %d %d BC\n",x,j,i);
						month[2]--;
						return;
						}
					}
				}
			}
		else{
			if(x>365)x-=365;
			else{
				for(int j=1;j<=12;j++){
					if(x>month[j])x-=month[j];
					else{
						printf("%lld %d %d BC\n",x,j,i);
						return;
					}
				}
			}
		}
	}	
					
}
void work2(){
	x-=1721424;
	for(int i=1;;i++){
		if(i%4==0){
			if(x>366)x-=366;
			else{
				month[2]++;
				for(int j=1;j<=12;j++){
					if(x>month[j])x-=month[j];
					else{
						printf("%lld %d %d\n",x,j,i);
						month[2]--;
						return;
						}
					}
				}
			}
		else{
			if(x>365)x-=365;
			else{
				for(int j=1;j<=12;j++){
					if(x>month[j])x-=month[j];
					else{
						printf("%lld %d %d\n",x,j,i);
						return;
					}
				}
			}
		}
	}	
					
}
bool check(int y){
	if(y%400==0)return 1;
	if(y%4==0&&y%100!=0)return 1;
	return 0;
}
void work3(){
	x-=2299161;
	if(x<=17){printf("%lld %d %d\n",14+x,10,1582);return;}
	x-=17;
	if(x<=30){printf("%lld %d %d\n",x,11,1582);return;}
	x-=30;
	if(x<=31){printf("%lld %d %d\n",x,12,1582);return;}
	x-=31;
	for(int i=1583;i<1600;i++){
		if(check(i)){
			if(x>366)x-=366;
			else{
				month[2]++;
				for(int j=1;j<=12;j++){
					if(x>month[j])x-=month[j];
					else{
						printf("%lld %d %d\n",x,j,i);
						month[2]--;
						return;
						}
					}
				}
			}
		else{
			if(x>365)x-=365;
			else{
				for(int j=1;j<=12;j++){
					if(x>month[j])x-=month[j];
					else{
						printf("%lld %d %d\n",x,j,i);
						return;
					}
				}
			}
		}
	}
	int he=1600+400*(x/146097);
	x=x-(x/146097*146097);
	for(int i=he;;i++){
		if(check(i)){
			if(x>366)x-=366;
			else{
				month[2]++;
				for(int j=1;j<=12;j++){
					if(x>month[j])x-=month[j];
					else{
						printf("%lld %d %d\n",x,j,i);
						month[2]--;
						return;
						}
					}
				}
			}
		else{
			if(x>365)x-=365;
			else{
				for(int j=1;j<=12;j++){
					if(x>month[j])x-=month[j];
					else{
						printf("%lld %d %d\n",x,j,i);
						return;
					}
				}
			}
		}
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	while(q--){
		x=read();x++;
		if(x<=1721424)work1();
		else if(x<=2299161)work2();
		else work3();
		}
	return 0;
}
