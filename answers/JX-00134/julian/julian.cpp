#include<bits/stdc++.h>
#define R register int
#define IN inline
using namespace std;
typedef long long ll;
IN int read()
{
	char ch;int f=1;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') f=-1;
	int x=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
int Q;
ll Div[3]={1721424,2299171};
int month[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
IN void work0(ll q)
{
	ll t=q/1461;
	ll y=4713-t*4,d=t*1461;
	while(d<q) 
	{
		if((y-1)%4==0) 
		{
			if(d+366<=q)
			d+=366,y--;
		}
		else
		{
			if(d+365<=q)
			d+=365,y--;
		}
	}
	if(d==q)
	{
		printf("31 12 %lld BC\n",y);
		return;
	}
	y--;int memm,memd;
	for(R i=1;i<=12;i++)
	{
		ll tmp=month[i];
		if((y-1)%4==0&&i==2) tmp++;
		if(tmp+d<=q) d+=tmp;	
		memm=i;
		memd=tmp;
	}	
	if(d==q)
	{
		printf("%d %d %lld BC\n",memd,memm,y);
		return;
	}
	memm++;memd=q-d;
	printf("%d %d %lld BC\n",memd,memm,y);
}
// 400 year 146100
IN void work1(ll q)
{
	q-=Div[0];
	ll t=q/146100;
	ll y=400*t,d=146100*t;
	while(d<q)
	{
		if(((y%4==0)&&(y%100!=0))||y%400==0) 
		{
			if(d+366<=q) d+=366,y++;
			
		}
		else
		{
			if(d+365<=q) d+=365,y++;
		}
	}
	if(d==q)
	{
		printf("31 12 %lld\n",y);
		return;
	}
	y++;
	int memm,memd;
	for(R i=1;i<=12;i++)
	{
		int tmp=month[i];
		if((((y%4==0)&&(y%100!=0))||y%400==0)&&i==2) tmp++;
		if(d+tmp<=q) 
		{
			d+=tmp;
			memm=i;
			memd=tmp;
		}
	}
	if(d==q) 
	{
		printf("%d %d %lld\n",memd,memm,y);
		return;
	}
	memd=q-d;
	printf("%d %d %lld\n",memd,memm+1,y);
}
int main()
{
	//freopen("julian.in","r",stdin);
	//freopen("julian.out","w",stdout);
	//cout<<4713/4+1;
	/*ll x=4713/4+1,y=4713-x;
	ll ans=0;
	ans=x*366+y*365;
	cout<<ans<<endl;
	x=1581/4;y=1581-x;
	ans+=x*366+y*365;
	ans+=31+28+31+30+31+30+31+31+30+14;
	cout<<ans;*/
	//cout<<365+365+366+365;
	scanf("%d",&Q);ll q;
	//int x=1+399/4,y=400-x;
	//cout<<x*366+y*365; 146100
	while(Q--)
	{
		scanf("%lld",&q);
		if(q<=Div[0]) work0(q);
		else if(q<=Div[1]) work1(q);
		else work1(q);
	}
	return 0;
}