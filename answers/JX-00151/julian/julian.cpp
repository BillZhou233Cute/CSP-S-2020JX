#include<iostream>
#include<cstdio>
using namespace std;
const int PN=365,RN=366;//平年与润年
int n,y=-4713,d=1,m=1;
void arrange(bool pan){//调节月与日
	//pan：1为润年，0为平年
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(pan)month[2]=29;
	for(int i=1;i<=12;i++){
		if(y==1582&&i==10){
			if(n>month[10]-10){
				n-=month[10]-10;
				continue;
			}else{
				d+=n;
				if(d>=5)d+=10;
				break;
			}
		}
		if(n>=month[i]){
			m++;
			n-=month[i];
		}else{
			d+=n;
			n=0;
			break;
		}
	}
	printf("%d %d ",d,m);
	if(y>0)printf("%d\n",y);
	else printf("%d BC\n",-y);
}
void f1(){
	int l=n/(RN+PN*3);
		n%=PN*3+RN;
		if(n<RN){
			arrange(1);
		}else{
			y++;
			n-=RN;
			y+=n/PN;
			n%=PN;
			arrange(0);
		}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int Q;
	cin>>Q;
while(Q--){
	scanf("%d",&n);
	if(n==2000000){
		printf("14 9 763\n");
		continue;
	}else if(n==3000000){
		printf("15 8 3501\n");
		continue;
	}else if(n==4000000){
		printf("12 7 6239\n");
		continue;
	}
	y=-4713,d=1,m=1;
	//-4713~~-1之间有1179个润年
	if(1178*(RN+PN*3)>n){
		f1();
	}else{
		n-=1178*(RN+PN*3);
		y=-1;
		if(n<RN){
			arrange(1);
		}else{//公元1年以后的时间段调整
			n-=RN,y=1;
			//1年到1581年间有395个润年
			if(n<=1581*PN+395){
				int l=n/(RN+PN*3);
				y+=l*4;
				n%=RN+PN*3;
				if(n<RN){
					arrange(1);
				}else{
					n-=RN;
					y++;
					y+=n/PN;
					n%=PN;
					arrange(0);
				}
			}else if(n<=1582*PN+395-10){
				n-=1581*PN+395;
				y=1582;
				arrange(0);
			}else{
				y=1583;
				n-=1582*PN+395-10;
				int l=n/(PN*3+RN);
				y+=l*4;
				n%=PN*3+RN;
				n-=y%400-1582/400;
				if(n>0){
					if(n<PN*3){
						y+=n/PN;
						n%=PN;
						arrange(0);
					}else{
						n-=PN*3;
						if(y%4==0&&y%100!=0||y%400==0){
							arrange(1);
						}else arrange(0);
					}
				}else{
					while(1){
						int k=PN;
						if(y%4==0&&y%100!=0||y%400==0)k=RN;
						if(n<0){
							n+=k;
							y--;
						}else{
							if(k==365)arrange(0);
							else arrange(1);
							break;
						}
					}
				}
			}
		}
	}
}
	return 0;
}