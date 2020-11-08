#include <iostream>
#include <stdio.h>
using namespace std;
int q ;
bool runA(int x)
{
	if(x%4==0&&x%100!=0)return true;
	if(x%400==0)return true;
	return false;
}
bool runB(int x)
{
	if(x%4==1&&x%100!=1)return true;
	if(x%400==1)return true;
	return false;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		long long d;
		scanf("%lld",&d);
		if(d<=1721059)
		{
			int year=d/365,date;
			if(runA(year))date=d%366;
				else date=d%365;
			int j=year/4;date-=j;
			if(date==0){cout<<"1 1 "<<year<<" BC";continue;}
			if(date<0)
			{
				year=year-(-date)/365;
				date=365-(-date%365);
				int month,day;
				if(runB(4713-year))
				{
					if(date>0&&date<=31){month=1;day=date;}
					else if(31<date&&date<=60){month=2;day=date-31;}
					else if(60<date&&date<=91){month=3;day=date-60;}
					else if(91<date&&date<=121){month=4;day=date-91;}
					else if(121<date&&date<=152){month=5;day=date-121;}
					else if(152<date&&date<=182){month=6;day=date-152;}
					else if(182<date&&date<=213){month=7;day=date-182;}
					else if(213<date&&date<=244){month=8;day=date-213;}
					else if(244<date&&date<=274){month=9;day=date-244;}
					else if(274<date&&date<=305){month=10;day=date-274;}
					else if(305<date&&date<=335){month=11;day=date-305;}
					else if(335<date&&date<=366){month=12;day=date-335;}
				}
				else
				{
					if(0<date&&date<=31){month=1;day=date;}
					else if(31<date&&date<=59){month=2;day=date-31;}
					else if(59<date&&date<=90){month=3;day=date-59;}
					else if(90<date&&date<=120){month=4;day=date-90;}
					else if(120<date&&date<=151){month=5;day=date-120;}
					else if(151<date&&date<=181){month=6;day=date-151;}
					else if(181<date&&date<=212){month=7;day=date-181;}
					else if(212<date&&date<=243){month=8;day=date-212;}
					else if(243<date&&date<=273){month=9;day=date-243;}
					else if(273<date&&date<=304){month=10;day=date-273;}
					else if(304<date&&date<=334){month=11;day=date-304;}
					else if(334<date&&date<=365){month=12;day=date-334;}
				}
				cout<<day+1<<" "<<month<<" "<<year<<" BC";
			}
			else
			{int month,day;
			    if(runB(4713-year))
				{
					if(0<date&&date<=31){month=1;day=date;}
					else if(31<date&&date<=60){month=2;day=date-31;}
					else if(60<date&&date<=91){month=3;day=date-60;}
					else if(91<date&&date<=121){month=4;day=date-91;}
					else if(121<date&&date<=152){month=5;day=date-121;}
					else if(152<date&&date<=182){month=6;day=date-152;}
					else if(182<date&&date<=213){month=7;day=date-182;}
					else if(213<date&&date<=244){month=8;day=date-213;}
					else if(244<date&&date<=274){month=9;day=date-244;}
					else if(274<date&&date<=305){month=10;day=date-274;}
					else if(305<date&&date<=335){month=11;day=date-305;}
					else if(335<date&&date<=366){month=12;day=date-335;}
				}
				else
				{
					if(0<date&&date<=31){month=1;day=date;}
					else if(31<date&&date<=59){month=2;day=date-31;}
					else if(59<date&&date<=90){month=3;day=date-59;}
					else if(90<date&&date<=120){month=4;day=date-90;}
					else if(120<date&&date<=151){month=5;day=date-120;}
					else if(151<date&&date<=181){month=6;day=date-151;}
					else if(181<date&&date<=212){month=7;day=date-181;}
					else if(212<date&&date<=243){month=8;day=date-212;}
					else if(243<date&&date<=273){month=9;day=date-243;}
					else if(273<date&&date<=304){month=10;day=date-273;}
					else if(304<date&&date<=334){month=11;day=date-304;}
					else if(334<date&&date<=365){month=12;day=date-334;}
				}
				cout<<day+1<<" "<<month<<" "<<4713-year<<" BC";
			}
		}
		else if(1721060<=d&&d<=2297797)
		{
			
		}
	}
	return 0;
}