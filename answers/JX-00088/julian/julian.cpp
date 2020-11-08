#include<bits/stdc++.h>
using namespace std;
int q,r,a,b,c,sum1,sum2;
int x[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int read()
{
	int x=0,y=0,z=getchar();
	while(!isdigit(z)&&(y=z=='-',1))z=getchar();
	while(isdigit(z))x=(x<<3)+(x<<1)+(z^48),z=getchar();
	return y?-x:x;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int i;
	q=read();
	for(i=1;i<=q;i++)
	{
		r=read();
		if(r<1721424)
		{
			sum1=r/1461;
			sum2=r%1461;
			c=4713-4*sum1;
			b=1,a=1;
			if(sum2<366)
			{
				sum1=sum2;
				while(sum1>=x[b])
				{
					if(b!=2)sum1-=x[b];
					else sum1=sum1-x[b]-1;
					b++;
				}
				a+=sum1;
				printf("%d %d %d BC\n",a,b,c);
			}
			else
			{
				sum2-=366;
				c-=1;
				sum1=sum2/365;
				c-=sum1;
				sum2=sum2-sum1*365;
				while(sum2>=x[b])
				{
					sum2-=x[b];
					b++;
				}
				a+=sum2;
				printf("%d %d %d BC\n",a,b,c);
			}
		}
		else if(r<2299160)
		{
			a=1,b=1,c=1;;
			r-=1721424;
			sum1=r/1461;
			sum2=r%1461;
			c+=sum1*4;
			if(sum2<1095)
			{
				sum1=sum2/365;
				c+=sum1;
				sum2%=365;
				while(sum2>=x[b])
				{
					sum2-=x[b];
					b++;
				}
				a+=sum2;
				printf("%d %d %d\n",a,b,c);
			}
			else
			{
				c+=3;
				sum2-=1095;
				while(sum2>=x[b])
				{
					if(b!=2)sum2-=x[b];
					else sum2=sum2-x[b]-1;
					b++;
				}
				a+=sum2;
				printf("%d %d %d\n",a,b,c);
			}
		}
		else 
		{
			a=14,b=10,c=1582;
			r-=2299160;
			if(r<1903)
			{
				if(r<442)
				{
					sum1=r/365;
					sum2=r%365;
					c+=sum1;
					if(sum2<16)
					{
						a+=sum2;
						printf("%d %d %d\n",a,b,c);
					}
					else
					{
						sum2-=16;
						b++;
						while(sum2>=x[b])
						{
							sum2-=x[b];
							b++;
						}
						a+=sum2;
						printf("%d %d %d\n",a,b,c);
					}
				}
				else
				{
					a=1,b=1,c=1584;
					sum1=r/1461;
					sum2=r%1461;
					c+=sum1*4;
					if(sum2<366)
					{
					sum1=sum2;
					while(sum1>=x[b])
					{
						if(b!=2)sum1-=x[b];
						else sum1=sum1-x[b]-1;
						b++;
					}
					a+=sum1;
					printf("%d %d %d \n",a,b,c);
					}
					else
					{
					sum2-=366;
					c-=1;
					sum1=sum2/365;
					c-=sum1;
					sum2=sum2-sum1*365;
					while(sum2>=x[b])
					{
					sum2-=x[b];
					b++;
					}
					a+=sum2;
					printf("%d %d %d \n",a,b,c);
					}
				}
			}
			else 
			{
				a=1,b=1,c=1600-17;
				sum1=r/146100;
				sum2=r%146100-65;
				c+=sum1*400;
				sum1=sum2/1461;
				sum2%=1461;
				c+=sum1*4;
				if(sum2<1095)
				{
					sum1=sum2/365;
					c+=sum1;
					sum2%=365;
					while(sum2>=x[b])
					{
						sum2-=x[b];
						b++;
					}
					a+=sum2;
					printf("%d %d %d\n",a,b,c);
				}
				else
				{
					c+=3;
					sum2-=1095;
					while(sum2>=x[b])
					{
						if(b!=2)sum2-=x[b];
						else sum2=sum2-x[b]-1;
						b++;
					}
					a+=sum2;
					printf("%d %d %d\n",a,b,c);
				}
			}
		}
	}
	return 0;
}