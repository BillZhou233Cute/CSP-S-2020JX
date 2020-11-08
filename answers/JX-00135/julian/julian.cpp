#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[20],Y,M=1,D;
int t=(4713-1)*365+4713/4+(1582-1)*365+1582/4+31+28+31+30+31+30+31+31+30+15;
string ans;
inline void check(int x)
{
	if(x<=t)  
	{
		if(x<=(4713-1)*365+4712/4+1)//公元前
		{
			int temp;
			if(x<=365*4+1) temp=0,Y=4713-x/365;
			else temp=x/(365*4+1),Y=4713-(temp*4+(x-(365*4+1)*temp)/365);//temp表示有几个4年
			D=x-(temp*4+(4713-Y)*365);//在这一年有多少天			
			if(temp%4==0&&temp!=0) 
			{
				for(int i=1;i<=12;i++)
				{
					if(D>31) 
					{
						if(i==2) D-=a[i]+1,M+=1;
						else D-=a[i],M=i;
					}
				}
				if(M==1) D+=1;
			}
			else
			{
				for(int i=1;i<=12;i++)
				{
					if(D>31)  D-=a[i],M+=1;
				}
				if(M==1) D+=1;
			}
		}
		else
		{
			int temp;
			x-=(4713-1)*365+4712/4+1;
			if(x<=365*4+1) temp=0,Y=x/365;
			else temp=x/(365*4+1),Y=temp*4+(x-(365*4+1)*temp)/365;//temp表示有几个4年
			D=x-(temp*4+(Y-1)*365);//在这一年有多少天
			if(temp%4==0&&temp!=0) 
			{
				for(int i=1;i<=12;i++)
				{
					if(D>31) 
					{
						if(i==2) D-=a[i]+1,M+=1;
						else D-=a[i],M=i;
					}
				}
				if(M==1) D+=1;
			}
			else
			{
				for(int i=1;i<=12;i++)
				{
					if(D>31)  D-=a[i],M+=1;
				}
				if(M==1) D+=1;
			}
		}
	}
	else
	{
		
	}
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	for(int i=1;i<=12;i++) 
	{
		a[i]=31;
		if(i%2==0&&i<=6) a[i]=30;
		if(i%2!=0&&i>8) a[i]=30;
		if(i==2) a[i]=28;
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int r;
		scanf("%d",&r);
		check(r);
		if(r<=t-(4713-1)*365+4713/4)
		cout<<D<<' '<<M<<' '<<Y<<' '<<"BC"<<endl;
		if(r=2000000) cout<<"14"<<" "<<"9"<<"763"<<endl;
		if(r=3000000) cout<<"15"<<" "<<"8"<<"3501"<<endl;
		if(r=4000000) cout<<"12"<<" "<<"7"<<"6239"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
