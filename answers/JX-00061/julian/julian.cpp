#include<bits/stdc++.h>
using namespace std;
int q;
long long n;
int y11[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int y[13];
int y22[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},y2[13];
int n4=365*4-1,n400=365*400+100-3,n100=365*400+25-1;

template <class T> inline void read(T &x)
{
	x=0;int g=1;char s=getchar();
	for (;s>'9'||s<'0';s=getchar())if (s=='-') g=-1;
	for (;s>='0'&&s<='9';s=getchar()) x=(x<<1)+(x<<3)+(s^48);
	x*=g;	
}
	
int main()
{
	int i,j;
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	read(q);
	y[0]=0;y11[0]=0;
	for (i=1;i<=12;i++)
		y[i]=y[i-1]+y11[i],y2[i]=y2[i-1]+y22[i];
	while(q--)
	{
		read(n);
		if (n<=365)
		{
				n++;
			//cout<<n<<endl;
				for (i=1;i<=12;i++)
					if (n-y[i]<=0)
					{
						cout<<n-y[i-1]<<" ";
						cout<<i<<" ";
						cout<<"4713 BC"<<endl;
						//printf("%d %d  4713 BC\n",n-y[i-1],  i);
						break;
					}
		}
		//else
			/*
				if
				{
					
				}
				else
				{
					
				}
				*/
	}
	//for (i=1;i<=12;i++) cout<<y[i]<<endl;
	return 0;
}