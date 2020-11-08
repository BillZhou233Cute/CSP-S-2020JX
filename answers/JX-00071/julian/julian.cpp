#include<bits/stdc++.h>
using namespace std;

int q;

int mond[15] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main()//juruo的大模拟
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(q--){
		int sty = -4712,stm = 1, std = 1;
		int day;
		scanf("%d",&day);
		if(day){
			while(day >= 355){
				if(sty == 1582){//1582 is a special year
					sty++;
					day -= 355;
					sty++;
				}
				else if(!(sty%4)&&(sty<1583||(sty%100?1:!(sty%400)))){
					if(day < 366)break;
					day -= 366;
					sty++;
				}//If this year is 闰年
				else{
					if(day < 365)break;
					day -= 365;
					sty++;
				}
			}
			while(day >= 21){
				if(stm == 10 && sty == 1582){
					day -= 21;
					stm++;
				}
				else if(stm == 2 && sty < 1582 && !sty%4){
					if(day < 29)break;
					day -= 29;
					stm++;
				}
				else if(stm == 2 && sty>=1582 && (sty%100?!(sty%4):!(sty%400))){
					if(day < 29)break;
					day -= 29;
					stm++;
				}
				else{
					if(day < mond[stm - 1])break;
					day -= mond[stm - 1];
					stm++;
				}
			}
			std += day;
			if(sty == 1582 && stm == 10 && std >= 5){
				std = 14 + std - 4;
			}
			day = 0;
			if(sty <= 0){
				printf("%d %d %d BC\n",std,stm,-sty+1);
			}
			else if(sty >= 1582){
				printf("%d %d %d \n",std,stm,sty-1);
			}
			else{
				printf("%d %d %d \n",std,stm,sty);
			}
		}
	}
	return 0;
}
