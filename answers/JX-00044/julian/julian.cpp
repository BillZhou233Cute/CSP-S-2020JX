#include<bits/stdc++.h>
using namespace std;
int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int T;
long long r;
bool is_r(int y)
{
	if(y<0)return (-y)%4==1;
	if(y<1582)return y%4==0;
	return (y%4==0&&y%100!=0)||y%400==0;
}
int da(int y,int m)
{
	if(is_r(y)&&m==2)return 29;
	return day[m];
}
int get(long long& tr,int y)
{
	tr++;
	int i=1;
	for(i=1;tr>da(y,i);i++)
		tr-=da(y,i);
	return i;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("jilian.out","w",stdout);
	cin>>T;
	while(T--)
	{
		scanf("%lld",&r);
		if(r<=365)
		{
			int mon=get(r,-4713);
			printf("%lld %d 4713 BC\n",r,mon);
		}
		else if(r<=1721423)
		{
			r-=366;
			int y=4712-r/1461*4;
			r%=1461;
			for(int i=1;i<=3;i++)
				if(r>365)
				{
					r-=365;
					y--;
				}
			int mon=get(r,-y);
			printf("%lld %d %d BC\n",r,mon,y);
		}
		else if(r<=2299160)
		{
			r-=1721424;
			int y=r/1461*4;
			r%=1461;
			for(int i=1;i<=3;i++)
				if(r>365)
				{
					r-=365;
					y++;
				}
			int mon=get(r,y);
			printf("%lld %d %d\n",r,mon,y);
		}
		else if(r<=22999238)
		{
			r-=577460+1721423;
			r+=9;
			int mon=get(r,1582);
			printf("%lld %d 1582\n",r,mon);
		}
		else
		{
			r-=22999239;
			if(r<=365)
			{
				int mon=get(r,1583);
				printf("%lld %d 1583\n",r,mon);
			}
			else if(r<=365+1461*4)
			{
				r-=366;
				int y=1584+r/1461*4;
				r%=1461;
				for(int i=1;i<=3;i++)
					if(r>365)
					{
						r-=365;
						y++;
					}
				int mon=get(r,y);
				printf("%lld %d %d\n",r,mon,y);
			}
			else
			{
				r-=366;
				r-=1461*4;
				int y=1600+r/1460997*100;
				r%=1460997;
				for(int i=1;i<=400;i++)
					if(r>(is_r(y)?366:365))
					{
						r-=is_r(y)?366:365;
						y++;
					}
				int mon=get(r,y);
				printf("%lld %d %d\n",r,mon,y);
			}
		}
	}
	return 0;
}
