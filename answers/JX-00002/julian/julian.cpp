#include<bits/stdc++.h>
using namespace std;
int q;
long long r,Y,M,D,mon[13]={0,31,29,31,30,31,30,31,31,30,31,30,31},tag;
bool check(int x){
	if((x%4==0&&x%100!=0)||(x%400==0)) return true;
	return false;
}
bool check2(int x){
	if(x%4==0) return true;
	return false;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(q--){
		tag=0;
		scanf("%lld",&r);
		if(!r){
			printf("1 1 4713 BC\n");
			continue;
		}
		if(r<1721424){//BC
			long long y=r-(r/146100)*146100+1;
			Y=4713-r/146100*400;
			while(1){
				if(check2(Y-1)){
					if(y<366) break;
					y-=366;
					Y--;
				}
				else{
					if(y<365) break;
					y-=365;
					Y--;
				}
			}
			if(!check2(Y-1)) tag=1;
			mon[2]-=tag;
			for(long long i=1;i<=12;i++){
				if(y<=mon[i]){
					printf("%lld %lld %lld BC\n",y,i,Y);
					break;
				}
				y-=mon[i];
			}
			mon[2]+=tag;
			continue;
		}
		r-=1721424;
		if(r<577460+273+4){//JLC
			long long y=r-(r/146100)*146100+1;
			Y=1+r/146100*400;
			while(1){
				if(check2(Y+1)){
					if(y<366) break;
					y-=366;
					Y++;
				}
				else{
					if(y<365) break;
					y-=365;
					Y++;
				}
			}
			if(!check2(Y)) tag=1;
			mon[2]-=tag;
			for(long long i=1;i<=12;i++){
				if(y<=mon[i]){
					printf("%lld %lld %lld\n",y,i,Y);
					break;
				}
				y-=mon[i];
			}
			mon[2]+=tag;
			continue;
		}				
		r-=577460+273+4-15;
		long long y=r-(r/146097)*146097;
		Y=r/146097*400+1582;
		while(1){
			if(check(Y+1)){
				if(y<366) break;
				y-=366;
				Y++;
			}
			else{
				if(y<365) break;
				y-=365;
				Y++;
			}
		}
		if(!y){
			printf("%lld %lld %lld\n",(long long)15,(long long)10,Y);
			continue;
		}
		if(y<=mon[10]){
			printf("%lld %lld %lld\n",y,(long long)10,Y);
			continue;
		}
		y-=mon[10];
		if(y<=mon[11]){
			printf("%lld %lld %lld\n",y,(long long)11,Y);
			continue;
		}
		y-=mon[11];
		if(y<=mon[12]){
			printf("%lld %lld %lld\n",y,(long long)12,Y);
			continue;
		}
		y-=mon[12];
		Y++;
		if(!check(Y)) tag=1;
		mon[2]-=tag;
		for(long long i=1;i<=12;i++){
			if(y<=mon[i]){
				printf("%lld %lld %lld\n",y,i,Y);
				break;
			}
			y-=mon[i];
		}
		mon[2]+=tag;
	}
	return 0;
}
