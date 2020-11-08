#include<bits/stdc++.h>
using namespace std;
int p[12]={0,31,59,90,120,151,181,212,243,273,304,334};
int r[12]={0,31,60,91,121,152,182,213,244,274,305,335};

int read()
{
	int x=0;char ch;
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-48;
		ch=getchar();
	}	
		return x;
}
int main()
{
        freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q;
	q=read();
	while(q--)
	{
		int a;a=read();a=a+1;
		if(a<=1721058)
		{	
			int b=a/1461;
			int c=a%1461;
			if(c<=366)
			{	
				b=b*4;
				int d;
				if(c==0)
					printf("%d %d %d BC\n",31,12,4713-b+1);
				else{
					for(int i=11;i>=0;--i)
						if(c-r[i]>0){d=i+1;c-=r[i];break;}
							printf("%d %d %d BC\n",c,d,4713-b);	
				}
			}
			else 
			{
				c-=366;b=b*4+c/365+1;c%=365;
				int d;
				if(c==0)
					printf("%d %d %d BC\n",31,12,4713-b+1);
				else{
					for(int i=11;i>=0;--i)
						if(c-p[i]>0){d=i+1;c-=p[i];break;}
							printf("%d %d %d BC\n",c,d,4713-b);	
					}	
			}
		}
		else{
			a-=721058;
			if(a<=579563)
			{
				int b=a/1461;
				int c=a%1461;
				if(c<=1095)
				{	
				b=b*4+c/365;
				int d;
				if(c==0)
					printf("%d %d %d BC\n",31,12,b-1);
				else{
					c%=365;
					for(int i=11;i>=0;--i)
						if(c-p[i]>0){d=i+1;c-=p[i];break;}
							printf("%d %d %d BC\n",c,d,b);	
					}
				}
				else 
				{
				c-=365*3;b=b*4+3;
				int d;
				if(c==0)
					printf("%d %d %d\n",31,12, b);
				else{
					for(int i=11;i>=0;--i)
						if(c-p[i]>0){d=i+1;c-=p[i];break;}
							printf("%d %d %d\n",c,d,b);	
					}	
				}
			}
		}	
	}
	return 0;
}
	
