#include<bits/stdc++.h>
using namespace std;

#define D1 1721423//gong'yuan
#define D2 2299160//gai'li'fa
#define D3 2299238//gai'li'fa'hou'yi'nian
#define D4 2305447//1600
#define YY 1583
#define BFY 1461
#define AFHY 146097
#define AOHY 36524
int g[14]={0,31,59,90,120,151,181,212,243,273,304,334,365};
int Q,num;
int y,m,d;
bool flag=false;

int read()
{
	int f=1,temp=0;char s;s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){temp=temp*10+s-'0';s=getchar();}
	return f*temp;
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	Q=read();
	while(Q--)
	{
		num=read();num++;
		y=0;m=0;d=0;
		
		if(num<=D1)
		{
			y=-4713;
			y+=(num-1)/BFY*4;num=(num-1+BFY)%BFY+1;
			if(num<=366)
			{
				if(num<=60){
					m=(num-1)/31+1;d=(num+30)%31+1;}
				else
					for(int i=3;i<=12;i++)
						if(num<=g[i]+1){
							m=i;d=num-g[i-1]-1;break;}
			}
			else{
				y++;num-=366;
				y+=(num-1)/365;num=(num-1+365)%365+1;
				for(int i=1;i<=12;i++)
					if(num<=g[i]){
						m=i;d=num-g[i-1];break;}
			}
			printf("%d %d %d BC\n",d,m,-y);
			continue;
		}
		
		if(num>D1&&num<=D2)
		{
			num-=D1;
			y=(num-1)/BFY*4;num=(num-1)%BFY+1;
			if(num<=365*3)
			{
				y+=(num-1)/365+1;num=(num-1)%365+1;
				for(int i=1;i<=12;i++)
					if(num<=g[i]){
						m=i;d=num-g[i-1];break;}
			}
			else{
				num-=365*3;y+=4;
				if(num<=60){
					m=(num-1)/31+1;d=(num-1)%31+1;}
				else
					for(int i=3;i<=12;i++)
						if(num<=g[i]+1){
							m=i;d=num-g[i-1]-1;break;}
			}
			printf("%d %d %d\n",d-1,m,y);
			continue;
		}
		
		if(num>D2&&num<=D3)
		{
			num-=D2;y=YY-1;
			if(num<=17){m=10;d=num+14;}
			if(num>17&&num<=47){m=11;d=num-17;}
			if(num>=78){m=12;d=num-47;}
			printf("%d %d %d\n",d-1,m,y);
			continue;
		}
		
		if(num>D3&&num<=D4)
		{
			num=num-D3;
			y=(num-1)/BFY*4;num=(num-1)%BFY+1;
			if(num<=365)
			{
				y+=1;
				for(int i=1;i<=12;i++)
					if(num<=g[i]){
						m=i;d=num-g[i-1];break;}
			}
			if(num>365&&num<=365+366){
				y+=2;num-=365;
				if(num<=60){
					m=(num-1)/31+1;d=(num-1)%31+1;}
				else
					for(int i=3;i<=12;i++)
						if(num<=g[i]+1){
							m=i;d=num-g[i-1]-1;break;}
			}
			if(num>365+366)
			{
				num-=365+366;y+=(num-1)/365+2;num=(num-1)%365+1;
				for(int i=1;i<=12;i++)
					if(num<=g[i]){
						m=i;d=num-g[i-1];break;}
			}
			printf("%d %d %d\n",d-1,m,y+YY);
		}
		if(num>D4)
		{
			num-=D4;
			y=(num-1)/AFHY*400;num=(num-1)%AFHY+1;
			y+=(num-1)/AOHY*100;num=(num-1)%AOHY+1;
			y+=(num-1)/BFY*4;num=(num-1)%BFY+1;
			if(num<=366){
				if(num<=60){
					m=(num-1)/31+1;d=(num-1)%31+1;}
				else
					for(int i=3;i<=12;i++)
						if(num<=g[i]+1){
							m=i;d=num-g[i-1]-1;break;}
			}
			if(num>366)
			{
				num-=366;y++;
				y+=(num-1)/365;num=(num-1)%365+1;
				for(int i=1;i<=12;i++)
					if(num<=g[i]){
						m=i;d=num-g[i-1];break;}
			}
			printf("%d %d %d\n",d-1,m,y+1600);
		}
	}
	return 0;
}