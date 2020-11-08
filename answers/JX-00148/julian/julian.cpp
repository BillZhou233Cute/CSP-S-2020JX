#include<cstdio>
int mo[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int Q,n,ans1,ans2,ans3,k,h,t,day,year,m;
inline int Read()
{
	int x=0,f=1;char c='?';
	while(c<'0'||c>'9')(c=='-')?f=-1,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
	return x*f;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	Q=Read();
	while(Q--)
	{
		n=Read();
		year=n/365;
		if(year>=4713) while(n<=year*365+(4713-1)/4+(year-4713)/4&&year>0) year--;
		else	while(n<=year*365+(year-1)/4&&year>0) year--;
			ans3=year;
			n-=year*365+(year-1)/4;
			int i=1;
			if((year-1)/4==0) mo[2]=29;
			while(n>mo[i]&&n>0)
			{
				n-=mo[i];
				i++;
			}
			mo[2]=28;
			ans2=ans3=4713-ans3;
			if(ans3<0) ans2=-ans3+1;
			printf("%d %d %d",n+1,i,ans2);
			if(ans3>0)printf(" BC");
			printf("\n");
			}
			return 0;
}
