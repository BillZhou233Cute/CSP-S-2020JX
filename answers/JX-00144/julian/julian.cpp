#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define inf 1000000010
using namespace std;
int q,r,yr=-4713,dy=1,mon=1;
int md[2][20]={{0,31,28,31,30,31,30,31,31,30,31,30,31,inf},{0,31,29,31,30,31,30,31,31,30,31,30,31,inf}};
int read()
{
	int x=0;bool f=0;char ch=getchar();
	while ((ch<'0') || (ch>'9')) {if (ch=='-') f=1;ch=getchar();}
	while ((ch>='0') && (ch<='9')) {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	if (!f) return x;
	return -x;
}
bool run(int x)
{
	if (x<0) x=-x-1;
	if (x%4) return 0;
	return 1;
}
bool run1(int x)
{
	if (((x%4==0) && (x%100!=0)) || (x%400==0)) return 1;
	return 0;
}
void geri()
{
	while (((!run1(yr)) && (r>=365)) || ((run1(yr)) && (r>=366)))
	{
		if (!run1(yr)) r-=365;
		else r-=366;
		yr++;
	}
	r+=10;
	if ((r<=273) && (yr==1982)) r-=10;
	int flag=run1(yr);
	while (r>=md[flag][mon])
	{
		r-=md[flag][mon];
		mon++;
	}
	dy+=r;
	printf("%d %d %d\n",dy,mon,yr);
}
void change(int x)
{
	dy=1;mon=1;yr=-4713;
	while (r>=366)
	{
		if (run(yr)) r-=366;
		else r-=365;
		yr++;
		if (yr==0) yr++;
		if (yr==1582) {geri();return;}
	}
	if ((r>=365) && (!run(yr)))
	{r-=365,yr++;if (yr==0) yr++;if (yr==1582){geri();return;}}
	int flag=run(yr);
	while ((r>=md[flag][mon]) && (mon<12))
	{
		r-=md[flag][mon],mon++;
		//printf("R:%d\n",r);//kkk
	}
	dy+=r;
	printf("%d %d %d",dy,mon,abs(yr));
	if (yr<0) printf(" BC\n");
	else printf("\n");
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	for (int i=1;i<=q;i++)
	{
		r=read();
		change(r);
	}
	return 0;
}
