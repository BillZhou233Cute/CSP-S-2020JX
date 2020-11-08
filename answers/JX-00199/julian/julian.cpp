#include<bits/stdc++.h>
using namespace std;
int q,r,k,y=-4713, mo[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isR(int y)
{
	if(y<=1582) 
	{
		if(y<0) y=-y-1;
		if(y%4==0)return 1;
		else return 0;
	}
	if(y%400==0||(y%4==0&&y%100!=0)) return 1;
	else return 0;
}
void w1();
void w2();
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(k<q)
	{
		k++;
		scanf("%d",&r);
		while(r>0)
		{
			if(y<1582) w1();
			if(y==1582)
			{
				if(r>355) y++,r-=355;
				else 
				{
					for(int i=1;i<10;i++)
					{
						if(r>mo[i]) r-=mo[i];
						else 
						{
							printf("%d %d %d\n",r+1,i,y);
							r=0;
							break;
						}
					}
					{
					if(r<4)
					{	
						printf("%d 10 %d\n",r+1,y);
						break;
					}
					if(r>4&&r<21) 
						{
						printf("%d 10 %d\n",r+15,y);
						break;
						}
					for(int i=11;i<=12;i++)
					{
						if(r>mo[i]) r-=mo[i];
						else{
							printf("%d %d %d\n",r+1,i,y);
							break;
						}
					}
					}
				}
			}
			if(y>1582) w2();
		}
		y=-4713;
	}
	return 0;
	
}

void w1()
{
	while(y<-1)
	{
		for(int i=1;i<13;i++)
		{
			int d=0;
			if(isR(y)&&i==2) d=1;
			if(r>mo[i]+d) r-=mo[i]+d;
			else
				{
					printf("%d %d %d BC\n",r+1,i,-y);
					r=0;
					return ;
				}
		}
		y++;
	}
	if(y==-1)
	{
		if(r<366)
			for(int i=1;i<13;i++)
			{
				int d=0;
				if(i==0) d=1;
				if(r>mo[i]+d) r-=mo[i]+d;
				else
				{
					printf("%d %d %d BC",r+1,i,-y);
					r=0;
					return ;
				}
			}
		else {
		y=1;
		r-=366;
		}
	}
	// y>0
	while(r>0&&y<1582)
	{
		for(int i=1;i<13;i++)
		{
			int d=0;
			if(isR(y)&&i==2) d=1;
			if(r>mo[i]+d) r-=mo[i]+d;
			else

				{
					printf("%d %d %d \n",r+1,i,y);
					r=0;
					return ;
				}
		}
		y++;
	}
}

void w2()
{
	while(r>0)
	{
		
		for(int i=1;i<13;i++)
		{
			int d=0;
			if(isR(y)&&i==2) d=1;
			if(r>mo[i]+d) r-=mo[i]+d;
			else 
			{
				printf("%d %d %d\n",r+1,i,y);
				r=-1;
				return ;
			}
		}
		y++;
	}
}
