#include<iostream>
#include<cstdio>
using namespace std;

//y%4==0&&(y%100!=0||y%400==0)

long long y=-4713,m=1,d=1,Ju[100000],n=0;
bool rn=0;
short mon[13]={31,28,31,30,31,30,31,31,30,31,30,31,-1};
int main()
{
	freopen("julian","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>Ju[i];
	}
	for(int i=0;i<n;i++)
	{
		while(Ju[i]>0)
		{
			if(y<1582||(y<1583&&(m<10||(m<11&&d<5))))
			{
				int a=Ju[i]/(365+365+365+366);
				if(a>0)
				{
					Ju[i]-=a*(365+365+365+366);
					y+=a;
				}
				else if(Ju[i]/365>0)
				{
					if(((y%4==-1?0:(y%4==0?3:-(y%4)-1))-y)>=Ju[i]/365||y-(y/4*4)>=Ju[i]/365)
					{
						Ju[i]-=Ju[i]/365*365;
						y+=Ju[i];
					}
					else
					{
						Ju[i]-=y*365;
						y+=Ju[i];
					}
				}
				else if(Ju[i]>366&&(y%4==-1||y%4==0))
				{
					Ju[i]-=366;
					y++;
				}
				else if(Ju[i]/365>0)
				{
					Ju[i]-=Ju[i]/365*365;
					y+=Ju[i];
				}
				else
				{
					for(int j=0;mon[j]>=0;j++)
					{
						if(Ju[i]>mon[j])
						{
							Ju[i]-=mon[j];
							m++;
						}
						else
						{
							d+=Ju[i];
							Ju[i]=0;
							break;
						}
					}
				}
			}
			else
			{
				int a=Ju[i]/(365+365+365+366);
				if(a>0)
				{
					Ju[i]-=a*(365+365+365+366);
					y+=a;
				}
				else if(Ju[i]/365>0)
				{
					if(((y%4==-1&&(y%100!=-1||y%400==-1)?0:(y%4==0&&(y%100!=0||y%400==0)?3:-(y%4)-1))-y)>=Ju[i]/365||y-(y/4*4)>=Ju[i]/365)
					{
						Ju[i]-=Ju[i]/365*365;
						y+=Ju[i];
					}
					else
					{
						Ju[i]-=y*365;
						y+=Ju[i];
					}
				}
				else if(Ju[i]>366&&(y%4==0&&(y%100!=0||y%400==0)||y%4==-1&&(y%100!=-1||y%400==-1)))
				{
					Ju[i]-=366;
					y++;
				}
				else if(Ju[i]/365>0)
				{
					Ju[i]-=Ju[i]/365*365;
					y+=Ju[i];
				}
				else
				{
					for(int j=0;mon[j]>=0;j++)
					{
						if(Ju[i]>mon[j])
						{
							Ju[i]-=mon[j];
							m++;
						}
						else
						{
							d+=Ju[i];
							Ju[i]=0;
							break;
						}
					}
				}
			}
		}
		cout<<y<<m<<d<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

