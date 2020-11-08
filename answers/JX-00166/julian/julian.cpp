#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=5005;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int Q;
int year[5005][2];
int pre[maxn][2];
int val[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int sum[15];
int day[maxn][15][2];
int pre1[maxn][15][2];
int wns1=0;
int len=0;
signed main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	pre[4714][0]=0;
	for(int i=4713;i>=1;i--)
	{
		if((i-1)%4==0)
		{
			for(int j=1;j<=12;j++)
			{
				day[i][j][0]=val[j];
			}
			day[i][2][0]=29;
			for(int j=1;j<=12;j++)
			{
				pre1[i][j][0]=pre1[i][j-1][0]+day[i][j][0];
			}
			year[i][0]=366;
		}
		else
		{	
			for(int j=1;j<=12;j++)
			{
				day[i][j][0]=val[j];
				pre1[i][j][0]=pre1[i][j-1][0]+day[i][j][0];
			}
			year[i][0]=365;
		}
		pre[i][0]=pre[i+1][0]+year[i][0];
	}
	for(int i=1;i<=1582;i++)
	{
		if(i%4==0)
		{
			for(int j=1;j<=12;j++)
			{
				day[i][j][1]=val[j];
			}
			day[i][2][1]=29;
			for(int j=1;j<=12;j++)
			{
				pre1[i][j][1]=pre1[i][j-1][1]+day[i][j][1];
			}
			year[i][1]=366;
		}
		else
		{	
			for(int j=1;j<=12;j++)
			{
				day[i][j][1]=val[j];
				pre1[i][j][1]=pre1[i][j-1][1]+day[i][j][1];
			}
			year[i][1]=365;
		}
		pre[i][1]=pre[i-1][1]+year[i][1];
	}
	wns1=pre[1582][1]-87;
	//cout<<wns1<<endl;
	Q=read();
	//cout<<pre[1][0]<<endl;
	while(Q--)
	{
		int x=read();
		x++;
		//cout<<x<<endl;
		int ans1=0,ans2=0,ans3=0;
		if(x<=pre[1][0])
		{
			//int ans1,ans2,ans3;  year month day
			int l=1,r=4713;
			while(l<r)
			{
				int mid=(l+r+1)>>1;
				if(pre[mid][0]>=x)
				{	
					l=mid;
				}
				else
				r=mid-1;
			}
			ans1=l;
			x-=pre[l+1][0];
			//int now=0;
			for(int j=1;j<=12;j++)
			{
				if(pre1[ans1][j][0]>=x)
				{
					x-=pre1[ans1][j-1][0];
					ans2=j;
					break;
				}
			}
			ans3=x;
			printf("%lld %lld %lld BC\n",ans3,ans2,ans1);
			continue;
		}
		x-=pre[1][0];
		if(x<=wns1)
		{
			//int ans1,ans2,ans3;  year month day
			int l=1,r=1582;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(pre[mid][1]>=x)
				{	
					r=mid;
				}
				else
				l=mid+1;
			}
			ans1=l;
			x-=pre[l-1][1];
			//int now=0;
			for(int j=1;j<=12;j++)
			{
				if(pre1[ans1][j][1]>=x)
				{
					x-=pre1[ans1][j-1][1];
					ans2=j;
					break;
				}
			}
			ans3=x;
			printf("%lld %lld %lld\n",ans3,ans2,ans1);
			continue;
		}
		x-=wns1;
		x+=10;
		if(x<=87)
		{
			ans3=1582;
			if(x<=26)
			{
				ans2=10,ans3=4+x;
			}
			else
			if(x<=56)
			{
				ans2=11,ans3=x-26;
			}
			else
			{
				ans2=12,ans3=x-56;
			}
			printf("%lld %lld %lld\n",ans3,ans2,ans1);
			continue;
		}
		x-=87;
		//cout<<x<<endl;
		int l=1583,r=1e9;
		int wns=0;
		while(l<r)
		{
			int mid=(l+r)>>1;
			len=mid-1583+1;
			//int yu=len%4;
			wns=len*365+(len+2)/4-(len+82)/100+(len+382)/400;
			if(wns>=x)
			{	
				r=mid;
			}
			else
			l=mid+1;
		}
		//cout<<ans3<<" "<<ans2<<" "<<ans1<<endl;
		ans1=l;
		len=(ans1-1)-1583+1;
		wns=len*365+(len+2)/4-(len+82)/100+(len+382)/400;
		//cout<<x<<" "<<wns<<endl;
		x-=wns;
		if(ans1%400==0 || (ans1%4==0 && ans1%100!=0))
		{	
			//cout<<"FUCK"<<" ";
			for(int i=1;i<=12;i++)
			{
				sum[i]=sum[i-1]+val[i];
				if(i==2)
				sum[i]++;
				if(sum[i]>=x)
				{
					ans2=i,ans3=x-sum[i-1];
					break;
				}
			}
		}
		else
		{
			for(int i=1;i<=12;i++)
			{
				sum[i]=sum[i-1]+val[i];
				if(sum[i]>=x)
				{
					ans2=i,ans3=x-sum[i-1];
					break;
				}
			}
		}
		printf("%lld %lld %lld\n",ans3,ans2,ans1);
	}
	return 0;
}
/*
1
2000000
*/
