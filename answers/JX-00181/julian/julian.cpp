#include<bits/stdc++.h>
#define long long int
using namespace std;
int t,n;
void day1(int x)
{
	if(x<31){
		printf("%lld 1 ",x);
		return ;
	}
	x-=31;
	if(x<28){
		printf("%lld 2 ",x);
		return ;
	}
	x-=28;
	if(x<31){
		printf("%lld 3 ",x);
		return ;
	}
	x-=31;
	if(x<30){
		printf("%lld 4 ",x);
		return ;
	}
	x-=30;
	if(x<31){
		printf("%lld 5 ",x);
		return ;
	}
	x-=31;
	if(x<30){
		printf("%lld 6 ",x);
		return ;
	}
	x-=30;
	if(x<31){
		printf("%lld 7 ",x);
		return ;
	}
	x-=31;
	if(x<31){
		printf("%lld 8 ",x);
		return ;
	}
	x-=31;
	if(x<30){
		printf("%lld 9 ",x);
		return ;
	}
	x-=30;
	if(x<31){
		printf("%lld 10 ",x);
		return ;
	}
	x-=31;
	if(x<30){
		printf("%lld 11 ",x);
		return ;
	}
	x-=30;
	if(x<31){
		printf("%lld 12 ",x);
		return ;
	}
}
void day2(int x)
{
	if(x<31){
		printf("%lld 1 ",x);
		return ;
	}
	x-=31;
	if(x<29){
		printf("%lld 2 ",x);
		return ;
	}
	x-=29;
	if(x<31){
		printf("%lld 3 ",x);
		return ;
	}
	x-=31;
	if(x<30){
		printf("%lld 4 ",x);
		return ;
	}
	x-=30;
	if(x<31){
		printf("%lld 5 ",x);
		return ;
	}
	x-=31;
	if(x<30){
		printf("%lld 6 ",x);
		return ;
	}
	x-=30;
	if(x<31){
		printf("%lld 7 ",x);
		return ;
	}
	x-=31;
	if(x<31){
		printf("%lld 8 ",x);
		return ;
	}
	x-=31;
	if(x<30){
		printf("%lld 9 ",x);
		return ;
	}
	x-=30;
	if(x<31){
		printf("%lld 10 ",x);
		return ;
	}
	x-=31;
	if(x<30){
		printf("%lld 11 ",x);
		return ;
	}
	x-=30;
	if(x<31){
		printf("%lld 12 ",x);
		return ;
	}
}
main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%d",&n);
		n++;
		if(n<=366){
			day2(n);
			printf("4713 ");
			puts("BC");
			continue;
		}
		n-=366;
		if(n<=1721424){
			int a=n/1178;
			int b=n-a*1178;
			if(b<=1095){
				int c=b/365;
				n=b-c*365;
				day1(n);
				printf("%lld ",4713-a*4-c-1);
				puts("BC");
				continue;
			}
			b-=1095;
			n=b;
			day2(n);
			printf("%lld ",4713-a*4-4);
			puts("BC");
			continue;
		}
		n-=1721424;
		if(n<=465310){
			int a=n/1178;
			int b=n-a*1178;
			if(b<=1095){
				int c=b/365;
				n=b;
				day1(n);
				printf("%lld ",1+a*4+c+1);puts("");
				continue;
			}
			b-=1095;
			n=b;
			day2(n);
			printf("%lld ",1+a*4+4);puts("");
			continue;
		}
		n-=465310;
		if(n<=365){
			day1(n);
			printf("1581 ");puts("");
			continue;
		}
		n-=365;
		if(n<=273){
			day1(n);
			printf("1582 ");puts("");
			continue;
		}else if(n<=355){
			n+=10;
			day1(n);
			printf("1582 ");puts("");
			continue;
		}
		n-=355;
		if(n<=365){
			day1(n);
			printf("1583 ");puts("");
			continue;
		}
		n-=365;
		if(n<=4712){
			int a=n/1178;
			int b=n-a*1178;
			if(b<=366){
				n=b;
				day2(n);
				printf("%lld ",1583+a*4+4);puts("");
				continue;
			}
			b-=366;
			int c=b/365;
			n=b-c*365;
			day1(n);
			printf("%lld ",1583+a*4+c+1);puts("");
			continue;
		}
		n-=4712;
		int p=n/117797;
		n=n-p*117797;
		if(n<=29450){
			int a=n/1178;
			int b=n-a*1178;
			if(b<=366){
				n=b;
				day2(n);
				printf("%lld ",1583+p*400+a*4+4);puts("");
				continue;
			}
			b-=366;
			int c=b/365;
			n=b-c*365;
			day1(n);
			printf("%lld ",1583+p*400+a*4+c+1);puts("");
			continue;
		}
		n-=29450;
		if(n<=29449){
			if(n<=1177){
				int b=n;
				int c=b/365;
				n=b-c*365;
				day1(n);
				printf("%lld ",1583+p*400+100+c+1);puts("");
				continue;
			}
			int a=n/1178;
			int b=n-a*1178;
			if(b<=366){
				n=b;
				day2(n);
				printf("%lld ",1583+p*400+a*4+4+100);puts("");
				continue;
			}
			b-=366;
			int c=b/365;
			n=b-c*365;
			day1(n);
			printf("%lld ",1583+p*400+a*4+c+1+100);puts("");
			continue;
		}
		n-=29449;
		if(n<=29449){
			if(n<=1177){
				int b=n;
				int c=b/365;
				n=b-c*365;
				day1(n);
				printf("%lld ",1583+p*400+200+c+1);puts("");
				continue;
			}
			int a=n/1178;
			int b=n-a*1178;
			if(b<=366){
				n=b;
				day2(n);
				printf("%lld ",1583+p*400+a*4+4+200);puts("");
				continue;
			}
			b-=366;
			int c=b/365;
			n=b-c*365;
			day1(n);
			printf("%lld ",1583+p*400+a*4+c+1+200);puts("");
			continue;
		}
		n-=29449;
		if(n<=29449){
			if(n<=1177){
				int b=n;
				int c=b/365;
				n=b-c*365;
				day1(n);
				printf("%lld ",1583+p*400+300+c+1);puts("");
				continue;
			}
			int a=n/1178;
			int b=n-a*1178;
			if(b<=366){
				n=b;
				day2(n);
				printf("%lld ",1583+p*400+a*4+4+300);puts("");
				continue;
			}
			b-=366;
			int c=b/365;
			n=b-c*365;
			day1(n);
			printf("%lld ",1583+p*400+a*4+c+1+300);puts("");
			continue;
		}
		n-=29449;
	}
	return 0;
}