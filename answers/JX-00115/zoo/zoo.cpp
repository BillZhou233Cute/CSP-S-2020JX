#include<iostream>
using namespace std;
const int N=1000000;
int n,m,c,k;
int a[35],b[N],q[31],s[2000];
int solve()
{
	int x,y;
	int ans=0;
	int sum=0;
	for(int i=1,i<=n;i++)
	{
		x=a[i];
		while(x>0){
		if(x&-x>0)
		{
			y=x&-x;
			while(y>0)
			{
				if(y%2==0)
					sum++;
				y=y/2;
			}
			if(q[sum]>0)
				s[sum]=1;
		}
		x=x-ans;
		for(j=1;j<=sum;j++)
		{
			ans=ans*2;
		}

	  }
	}
}
int xy()
{
	int w;
	int M=1;
	w=min(c,k);
	for(int i=1;i<=c;i++)
	{
		M=
	}
}
int main()
{
	solve();
	xy();
	return 0;
}