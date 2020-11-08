#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int read()
{
	int x=0;char ch;
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-48;
		ch=getchar();
	}	
		return x;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T,sum;
	T=read();
	for(int i=1;i<=T;++i)
	{
		int n,x;
		n=read();
		if(i==1){
			sum=n;
			for(int j=1;j<=n;++j)
				a[j]=read();
		}
		else{
			for(int j=1;j<=n;++j)
			{
				x=read();a[x]=read();
			}
		}
		
	}
	return 0;
}