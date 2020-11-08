#include<iostream>
#include<cstdio>
using namespace std;
int T;
long long q,b[13];
long long cn(long long x,long long y,long long z)
{
	if(x==0)
		return y/z+1;
	return y/z-(x-1)/z;
}
long long gg(long long x,long long y)
{
	return cn(x,y,4ll)-cn(x,y,100ll)+cn(x,y,400ll);
}
long long rl_dc(long long x,long long y)
{
	return cn(x,y,4ll);
}
long long rl_bc(long long x,long long y)
{
	return cn(x-1ll,y-1ll,4ll);
}
long long f(long long x,bool y)
{
	//1 1 x YtrueBC
	if(y==true)
		return (4713ll-x)*365ll+rl_bc(x+1,4713);
	//y now false
	if(x<1583)
		return (x-1ll)*365ll+rl_dc(1,x-1);
	return (x-1583)*365ll+gg(1583,x-1);
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	b[1]=31; b[2]=28; b[3]=31; b[4]=30;
	b[5]=31; b[6]=30; b[7]=31; b[8]=31;
	b[9]=30; b[10]=31;b[11]=30;b[12]=31;
	//cout<<f(0,true)<<endl;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&q);
		if(q<1721424)
		{
			int l=1,r=4713;
			int ns=4713,md;
			while(l<=r)
			{
				md=(l+r)>>1;
				if(f(md,true)<=q)
				{
					ns=md;
					r=md-1;
				}
				else l=md+1;
			}
			int ta=1,tb=1;
			q-=f(ns,true);
			bool flg=((ns-1)%4==0);
			if(flg) b[2]++;
			while(q--)
			{
				tb++;
				if(tb==b[ta]+1)
				{
					ta++;
					tb=1;
				}
			}
			if(flg) b[2]--;
			printf("%d %d %d BC\n",tb,ta,ns);
			continue;
		}
		q-=1721424;
		if(q<577815)
		{
			int l=1,r=1582;
			int ns=1,md;
			while(l<=r)
			{
				md=(l+r)>>1;
				if(f(md,false)<=q)
				{
					ns=md;
					l=md+1;
				}
				else r=md-1;
			}
			int ta=1,tb=1;
			q-=f(ns,false);
			bool flg=(ns%4==0);
			if(flg) b[2]++;
			while(q--)
			{
				tb++;
				if(ns==1582&&ta==10&&tb==5)
				{
					tb=15;
					continue;
				}
				if(tb==b[ta]+1)
				{
					ta++;
					tb=1;
				}
			}
			if(flg) b[2]--;
			printf("%d %d %d\n",tb,ta,ns);
			continue;
		}
		q-=577815;
		//1583 1 1
		long long l=1583,r=1000000000;
		long long ns=1583,md;
		while(l<=r)
		{
			md=(l+r)>>1;
			if(f(md,false)<=q)
			{
				ns=md;
				l=md+1;
			}
			else r=md-1;
		}
		int ta=1,tb=1;
		q-=f(ns,false);
		bool flg=(ns%400==0||(ns%100!=0&&ns%4==0));
		if(flg) b[2]++;
		while(q--)
		{
			tb++;
			if(tb==b[ta]+1)
			{
				ta++;
				tb=1;
			}
		}
		if(flg) b[2]--;
		printf("%d %d %lld\n",tb,ta,ns);
	}
	return 0;
}