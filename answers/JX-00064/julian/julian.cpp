#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define BC 1721424//last day of BC
#define RL 2299161//last day of RL
#define GE 2299162//first day of GE
using namespace std;

int n;
int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int monn[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
long long a;

void _BC(long long x){
	int p=365*3+366;
	int Y,M,D;
	Y=x/p*4;
	int rest=x-(x/p*p);
	int now_y=0;
	for(int i=0;i<4;i++){
		now_y+=(i%4==0)?366:365;
		if(rest>now_y) continue;
		now_y-=(i%4==0)?366:365;
		Y+=i;rest-=now_y;
		int now_m=0;
		for(int j=1;j<=12;j++){
			now_m+=((4713-Y-1)%4==0)?monn[j]:mon[j];
			if(rest==now_m){D=((4713-Y-1)%4==0)?monn[j]:mon[j];M=j;break;}
			if(rest>now_m) continue;
			now_m-=((4713-Y-1)%4==0)?monn[j]:mon[j];
			M=j;
			D=rest-now_m+1;
			break;
		}
		break;
	}
	printf("%d %d %d BC\n",D,M,4713-Y);
	return;
}

void _RL(long long x){
	int p=365*3+366;
	int Y,M,D;
	Y=x/p*4;
	int rest=x-(x/p*p);
	int now_y=0;
	for(int i=1;i<=4;i++){
		now_y+=(i%4==0)?366:365;
		if(rest>now_y) continue;
		now_y-=(i%4==0)?366:365;
		Y+=i;rest-=now_y;
		int now_m=0;
		for(int j=1;j<=12;j++){
			now_m+=(Y%4==0)?monn[j]:mon[j];
			if(rest==now_m){D=(Y%4==0)?monn[j]:mon[j];M=j;break;}
			if(rest>now_m) continue;
			now_m-=(Y%4==0)?monn[j]:mon[j];
			M=j;
			D=rest-now_m;
			break;
		}
		break;
	}
	printf("%d %d %d\n",D,M,Y);
	return;
}

void _GE(long long x){
	if(x<=77){
		if(x<=16) printf("%d %d %lld\n",1582,10,15+x);
		else if(x<=46) printf("%d %d %lld\n",1582,11,x-16);
		else printf("%d %d %lld\n",1582,12,x-46);
		return;
	}
	int p=303*365+97*366;
	int Y,M,D;
	Y=x/p*400+1583;
	int rest=x-(x/p*p);
	int now_y=0;
	for(int i=Y;i<Y+400;i++){
		now_y+=((i%4==0 && i%100!=0) || i%400==0)?366:365;
		if(rest>now_y) continue;
		now_y-=((i%4==0 && i%100!=0) || i%400==0)?366:365;
		Y+=(i-Y)-1;rest-=now_y;
		int now_m=0;
		for(int j=1;j<=12;j++){
			now_m+=((i%4==0 && i%100!=0) || i%400==0)?monn[j]:mon[j];
			if(rest==now_m){D=((i%4==0 && i%100!=0) || i%400==0)?monn[j]:mon[j];M=j;break;}
			if(rest>now_m) continue;
			now_m-=((i%4==0 && i%100!=0) || i%400==0)?monn[j]:mon[j];
			M=j;
			D=rest-now_m+1;
			break;
		}
		break;
	}
	printf("%d %d %d\n",D,M,Y);
	return;
}

void work(){
	if(a<=BC) _BC(a);
	else if(a<=RL) _RL(a-BC);
	else _GE(a-GE);
	return;
}

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		work();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
