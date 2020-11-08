#include <iostream>
#include <cstdio>
using namespace std;
const int JC=2299160;
const int BC=1721423;
int q;
int jl[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int gc[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool pd1(int y)
{
	if((y*(-1)+1)%4==0)
	{
		return true;
	}
	return false;
}
bool pd2(int y)
{
	if(y%400==0||(y%4==0&&y%100!=0))
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(q--)
	{
		int r;
		scanf("%d",&r);
		/*if(r<=JC)
		{
			printf("%d Y\n",r);
		}*/
		if(r<=JC)
		{
			if(r>BC)
			{
				/*if(JC-r<=r-BC&&r<=JC&&r>BC)
				{
					printf("%d Y\n",r);
				}*/
				if(JC-r<=r-BC)
				{
					r=JC-r;
					int y=1582,m=10,d=4;
					//r=r-31-28-31-30-31-30-31-31-30-4;
					while((pd2(y)&&r>=366)||r>=365)
					{
						if(pd2(y))
						{
							r-=366;
						}
						else
						{
							r-=365;
						}
						y--;
					}
					//printf("%d\nn:%d %d %d\n",r,d,m,y);
					while((pd2(y)&&m==2&&r>=29)||r>=jl[m])
					{
						if(pd2(y)&&m==2)
						{
							r-=29;
						}
						else
						{
							r-=jl[m];
						}
						m--;
						if(m==0)
						{
							y--;
							m=12;
						}
					}
					while(r)
					{
						r--;
						d--;
						if(pd2(y)&&m==3&&d==0)
						{
							m--;
							d=29;
						}
						else if(d==0)
						{
							m--;
							d=jl[m];
						}
						if(m==0)
						{
							y--;
							m=12;
							
						}
					}
					printf("%d %d %d\n",d-1,m,y);
				}
				else
				{
					r-=BC;
					//printf("\n%d\n",r);
					int x=0;
					int y=1,m=1,d=1;
					while((pd2(y)&&r>=366)||r>=365)
					{
						if(pd2(y))
						{
							r-=366;
						}
						else
						{
							r-=365;
						}
						y++;
					}
					//printf("%d\nn:%d %d %d\n",r,d,m,y);
					while((pd2(y)&&m==2&&r>=29)||r>=jl[m])
					{
						if(pd2(y)&&m==2)
						{
							r-=29;
						}
						else
						{
							r-=jl[m];
						}
						m++;
						x++;
						if(m==13)
						{
							y++;
							m=1;
						}
					}
					//printf("%d\nn:%d %d %d\n",r,d,m,y);
					r=r-x+1;
					while(r)
					{
						r--;
						d++;
						if(d==jl[m]+1&&!pd2(y))
						{
							m++;
							d=1;
						}
						else if(pd2(y)&&m==2&&d==30)
						{
							m++;
							d=1;
						}
						if(m==13)
						{
							y++;
							m=1;
							
						}
					}
					printf("%d %d %d\n",d,m,y);
				}
			}
			else
			{
				if(BC-r>r)
				{
					int y=-4713,m=1,d=1;
					while((pd1(y)&&r>=366)||r>=365)
					{
						if(pd1(y))
						{
							r-=366;
						}
						else
						{
							r-=365;
						}
						y++;
					}
					//printf("%d\nn:%d %d %d\n",r,d,m,y*(-1));
					bool f=false,p=true;
					while((pd1(y)&&m==2&&r>=29)||r>=jl[m])
					{
						f=true;
						if(pd1(y)&&m==2)
						{
							r-=29;
							p=false;
						}
						else
						{
							r-=jl[m];
						}
						m++;
						if(m==13)
						{
							y++;
							m=1;
						}
					}
					//printf("%d\nn:%d %d %d\n",r,d,m,y*(-1));
					while(r)
					{
						r--;
						d++;
						if(d==jl[m]+1&&!pd1(y))
						{
							m++;
							d=1;
						}
						else if(pd1(y)&&m==2&&d==30)
						{
							m++;
							d=1;
						}
						if(m==13)
						{
							y++;
							m=1;
						}
					}
					//printf("%d\nn:%d %d %d\n",r,d,m,y*(-1));
					if(f&&p)
					{
						d--;
					}
					printf("%d %d %d BC\n",d,m,y*(-1));
				}
				else
				{
					r=BC-r;
					int y=-1,m=12,d=31;
					while((pd1(y)&&r>=366)||r>=365)
					{
						if(pd1(y))
						{
							r-=366;
						}
						else
						{
							r-=365;
						}
						y--;
					}
					while((pd1(y)&&m==2&&r>=29)||r>=jl[m])
					{
						if(pd1(y)&&m==2)
						{
							r-=29;
						}
						else
						{
							r-=jl[m];
						}
						m--;
						if(m==0)
						{
							y--;
							m=12;
						}
					}
					while(r)
					{
						r--;
						d--;
						if(pd1(y)&&m==3&&d==0)
						{
							m--;
							d=29;
						}
						else if(d==0)
						{
							m--;
							d=jl[m];
						}
						if(m==0)
						{
							y--;
							m=12;
						}
					}
					printf("%d %d %dBC\n",d,m,y*(-1));
				}
			}
		}
		else
		{
			r=r-JC;
			int y=1582,m=10,d=15;
			while((pd2(y)&&r>=366)||r>=365)
			{
				if(pd2(y))
				{
					r-=366;
				}
			    else
				{
					r-=365;
				}
				y++;
			}
			//printf("%d\nn:%d %d %d\n",r,d,m,y);
			while((pd2(y)&&m==2&&r>=29)||r>=jl[m])
			{
				if(pd2(y)&&m==2)
				{
					r-=29;
				}
				else
				{
					r-=jl[m];
				}
				m++;
				if(m==13)
				{
					y++;
					m=1;
				}
			}
			//printf("%d\nn:%d %d %d\n",r,d,m,y);
			r--;
			while(r)
			{
				r--;
				d++;
				if(d==jl[m]+1&&!pd2(y))
				{
					m++;
					d=1;
				}
				else if(pd2(y)&&m==2&&d==30)
				{
					m++;
					d=1;
				}
				if(m==13)
				{
					y++;
					m=1;
				}
			}
			printf("%d %d %d \n",d,m,y);
		}
	}
	return 0;
}