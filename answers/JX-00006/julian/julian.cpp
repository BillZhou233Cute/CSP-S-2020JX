#include <iostream>
#include <cstdio>
#define ll long long

using namespace std;

const int limit=365*4713+4713/4;//1.1.1
const int ruli=limit+1581*365+1581/4+6*31+2*30+28+4;//1582.10.5
int q,a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

void bc(ll x);
void rl(ll x);
void ad(ll x);

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);	
	ll x;
	for(int i=1;i<=q;i++){
		scanf("%lld",&x);
		if(x<limit)
			bc(x);
		else if(x<ruli)
			rl(x);
		else
			ad(x);
	}	
	return 0;
}	
void bc(ll x){
	int y=x/(365*4+1);
	y*=4;
	x=x%(365*4+1);//0->1.1
	if(!x){
		printf("1 1 %d\n",4713-y);
		return ;
	}	
	if(x<366){
		x++;
		for(int i=1;i<=12;i++){
			if(x<=a[i]||(x==a[i]+1&&i==2)){
				printf("%lld %d %d BC\n",x,i,4713-y);
				return ;
			}
			x-=a[i];
			if(i==2)
				x--;
		}	
	}
	x-=365;
	y++;
	while(x>365){
		x-=365;
		y++;
	}
	for(int i=1;i<=12;i++){
		if(x<=a[i]){
			printf("%lld %d %d BC\n",x,i,4713-y);
			return ;
		}
		x-=a[i];
	}	
}
void rl(ll x){
	x-=limit;//0->1.1.1
	x++;//1->1.1.1
	int y=x/(365*4+1);
	y*=4;
	x=x%(365*4+1);
	if(x==0){
		printf("12 31 %d\n",y);
		return ;
	}	
	if(x<366){
		for(int i=1;i<=12;i++){
			if(x<=a[i]){
				printf("%lld %d %d\n",x,i,1+y);
				return ;
			}
			x-=a[i];
		}	
	}
	x-=365;//1->2.1.1
	y++;
	int add=1;
	while(x>365){
		x-=365;
		y++;
		add++;
	}
	for(int i=1;i<=12;i++){
		if(x<=a[i]||(add==3&&i==2&&x==a[i]+1)){
			printf("%lld %d %d\n",x,i,y);
			return ;
		}
		x-=a[i];
		if(add==3&&i==2)
			x--;
	}		
}
void ad(ll x){
	x-=ruli;//0->1582.10.15
	if(x<=16+30+31){
		x+=15;
		for(int i=10;i<=12;i++){
			if(x<=a[i]){
				printf("%lld %d 1582\n",x,i);
				return ;
			}
			x-=a[i];
		}	
	}
	x-=77;//0->1583.1.1
	x++;//1->1583.1.1
	if(x<366){
		for(int i=1;i<=12;i++){
			if(x<=a[i]){
				printf("%lld %d 1583\n",x,i);
				return ;
			}
			x-=a[i];
		}	
	}
	x-=365;//1->1584.1.1
	int y4=366+365*3;//->1587.12.31
	if(x<=4*y4){
		if(x<=366){
			for(int i=1;i<=12;i++){
				if(x<=a[i]||(x==a[i]+1&&i==2)){
					printf("%lld %d 1584\n",x,i);
					return ;
				}
				x-=a[i];
				if(i==2)
					x--;
			}
		}
		int y=1584;
		x-=366;//1->1585.1.1
		y++;
		while(x>365){
			x-=365;
			y++;
		}	
		for(int i=1;i<=12;i++){
			if(x<=a[i]){
				printf("%lld %d %d\n",x,i,y);
				return ;
			}
			x-=a[i];
		}
	}
	x-=4*y4;//1->1600.1.1
	int y400=97+365*400;
	int y100=24+365*100;
	int y=1600;
	y+=x/y400*400;
	x%=y400;
	y+=x/y100*100;
	x%=y100;
	y+=x/y4*4;
	x%=y4;
	y+=x/365;
	x%=365;
	if(x==0){
		printf("31 12 %d",y);
		return ;
	}	
	for(int i=1;i<=12;i++){
		if(x<=a[i]||(x==a[i]+1&&i==2&&y%4==0&&y%100!=0)){
			printf("%lld %d %d\n",x,i,y);
			return ;
		}
		x-=a[i];
		if(i==2&&y%4==0&&y%100!=0)
			x--;
	}	
}