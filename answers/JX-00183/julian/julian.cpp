#include<iostream>
#include<cstdio>
using namespace std;
const int mod=4e7;
int r,Q,c;
int now,day;
int d[29]={0,31,28,31,30,31,30,31,31,30,31,30,31};

void print()
{
	if(now==0) now=1;
	if((now<0&&(now+1+mod)%4==0)||(now>0&&(now%4==0))) d[2]=29;
	for(int i=1;i<=12;i++)
	{
		if(r<d[i])
		{
			printf("%d %d ",r+1,i);
			if(now<0) printf("%d BC",-now);
			else printf("%d",now);
			break;
		}
		else r-=d[i];
	}d[2]=28;
	puts("");
	return;
}

void run1()
{//cout<<1<<endl;
	now+=r/1461*4;
	r%=1461;
	if(r>=366)
	{
		r-=366;
		now++;
		now+=r/365;
		r%=365;
	}
	if(now>=0) now++;
	print();
}

void run2()
{//cout<<2<<endl;
	while(now<1600)
	{
		if(now%4==0) day=366;
		else day=365;
		if(r<day)
		{
			print();
			return ;
		}
		r-=day;
		now++;
	}
	now+=r/146097*400;
	r=r%146097;
	if(r>=36525)
	{
		r-=36525;
		now+=100;
		now+=r/36524*100;
		r%=36524;
		if(r>=1460) r-=1460,now+=4;
		else
		{
			now+=r/365;
			r%=365;
			print();
			return;
		}
	}
	now+=r/1461*4;
	r%=1461;
	if(r>=366)
	{
		r-=366;
		now++;
		now+=r/365;
		r%=365;
	}
	print();
	return;
}
	
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&Q);
	now=-4713;
	while(Q--)
	{
		scanf("%d",&r);
		now=-4713;
		if(r<2298884) run1();
		else if(r>=2298884&&r<=2299160)
		{
			r-=2298884;
			now=1582;
			print();
		}
		else 
		{
			r-=2298884;
			now=1582;
			r+=10;
			run2();
		}
//		cout<<25*(366+3*365)<<endl;
		//cout<<(25+24+24+24)*(366+3*365)+12*365<<endl;
		/*int ans=0;
		while(now<1582)
		{
			if(now==0) now=1;
			if((now<0&&((now+1+mod)%4==0))||(now>0&&now%4==0)) day=366;
			else day=365;
			ans+=day;
			now++;
		}
		cout<<ans<<endl;*/
	//		cout<<4*365<<endl;
//	cout<<2298884+276<<endl;
	}
	return 0;
}
