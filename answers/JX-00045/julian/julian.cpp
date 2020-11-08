#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
	ll q,x;
	q=read();
	for(ll i=1;i<=q;i++)
	{
		ll x,a=-4713,b=1,c=1,l=0,z=0;
		x=read();
		c+=x;
		while(c>d[b]+l)
		{
			c=c-(d[b]+l);
			b++;
			if(b>12)
			{
				b=1;
				a++;
			}
			if(a==0)
			a++;
			if(a>=1582&&b>=10&&c>=5&&z==0)
			c+=10,z=1;
			if(a<0&&b==2&&(abs(a)-1)%4==0)
			l=1;
			else
			if(a>0&&b==2&&a%4==0)
			{
				if(a%100==0&&a>1582)
				{
					if(a%400==0)
					l=1;
				}
				else
				l=1;
			}
			else
			l=0;
		}
		cout<<c<<" "<<b<<" "<<abs(a)<<" ";
    	if(a<0)
    	cout<<"BC"<<endl;
	    else
	    cout<<endl;
	}
	return 0;
}