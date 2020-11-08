#include<bits/stdc++.h>
#define R register int
using namespace std;
const int N=1e7+5;
int yue[N],ri[N],v[N],year[N];
int read()
{
	int f=1;char ch;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') f=-1;
	int res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') res=res*10+ch-'0';
	return res*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void pre(int i)
{
	bool flag=true;//是闰年
	int day;bool qian=true;
	if(flag) day=366;
		int x=i,y=4712;
		while(x>=day)
		{
			x=x-day;
			if(qian) y--;//公元前
			else  qian=false,y++;//公元后
			if(y<0)
			{
				qian=false;
				y=1;
			}
			if(qian==false&&y>1582)
			{
				if(y%400==0||(y%4==0&&y%100!=0))
				{
					flag=true;
					day=366;
				}
				else 
				{
					flag=false;
					day=365;
				}
			}
			else
			{
				if(y%4==0)
				{
					flag=true;
					day=366;
				}
				else 
				{
					flag=false;
					day=365;
				}
			}
		}
		if(qian==true) 
		{
			v[i]=1;
			year[i]=y+1;
		}
		else 
		{
			v[i]=0;
			year[i]=y;
		}
		if(qian==false&&y==1582)
		{
			flag=false;
			day=365;
			if(x<31) yue[i]=1;
			else if(x<59) yue[i]=2,x-=31;
			else if(x<90) yue[i]=3,x-=59;
			else if(x<120) yue[i]=4,x-=90;
			else if(x<151) yue[i]=5,x-=120;
			else if(x<181) yue[i]=6,x-=151;
			else if(x<212) yue[i]=7,x-=181;
			else if(x<243) yue[i]=8,x-=212;
			else if(x<273) yue[i]=9,x-=243;
			else
			{
				if(x<=276) yue[i]=10,x-=273;
				else 
				{
					x+=10;
					if(x<304) yue[i]=10,x-=273;
					else if(x<334) yue[i]=11,x-=304;
					else if(x<365) yue[i]=12,x-=334;
				}
			}
			ri[i]=x+1;
		}
		if(qian==false&&y>1782)x+=10;
		if(x<day)
		{
			if(flag)
			{
				if(x<31) yue[i]=1;
				else if(x<60) yue[i]=2,x-=31;
				else if(x<91) yue[i]=3,x-=60;
				else if(x<121) yue[i]=4,x-=91;
				else if(x<152) yue[i]=5,x-=121;
				else if(x<182) yue[i]=6,x-=152;
				else if(x<213) yue[i]=7,x-=182;
				else if(x<244) yue[i]=8,x-=213;
				else if(x<274) yue[i]=9,x-=244;
				else if(x<305) yue[i]=10,x-=274;
				else if(x<335) yue[i]=11,x-=305;
				else if(x<366) yue[i]=12,x-=335;
				ri[i]=x+1;
			}
			else
			{
				if(x<31) yue[i]=1;
				else if(x<59) yue[i]=2,x-=31;
				else if(x<90) yue[i]=3,x-=59;
				else if(x<120) yue[i]=4,x-=90;
				else if(x<151) yue[i]=5,x-=120;
				else if(x<181) yue[i]=6,x-=151;
				else if(x<212) yue[i]=7,x-=181;
				else if(x<243) yue[i]=8,x-=212;
				else if(x<273) yue[i]=9,x-=243;
				else if(x<304) yue[i]=10,x-=273;
				else if(x<334) yue[i]=11,x-=304;
				else if(x<365) yue[i]=12,x-=334;
				ri[i]=x+1;
			}
		}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q=read();
	while(q--)
	{
		int r=read();pre(r);
		write(ri[r]);putchar(' ');write(yue[r]);putchar(' ');write(year[r]);
		if(v[r]) printf(" BC");
		putchar('\n');
	}
	fclose(stdin);fclose(stdout);
}