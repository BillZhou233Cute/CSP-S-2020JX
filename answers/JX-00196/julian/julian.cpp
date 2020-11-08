#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read()
{
	re int x=0,f=1;
	re char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') f*=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
int k[1500][200];
int n,a,b,c,A=1721424,B=577737,C=78,D=6209,yor;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	k[0][0]=k[0][1]=0,k[1][0]=31,k[2][0]=28,k[3][0]=31,k[4][0]=30,k[5][0]=31,k[6][0]=30,k[7][0]=31,k[8][0]=31,k[9][0]=30,k[10][0]=31,k[11][0]=30,k[12][0]=31;
	for(re int i=1;i<=12;i++) k[i][1]=k[i-1][1]+k[i][0]+(i==2),k[i][0]+=k[i-1][0];
	for(re int T=read();T--;yor=0)
	{
		a=1,b=1,c=-4713;
		n=read();
		if(n<A)
		{
			c+=n/1461*4,n%=1461;
			if(n<=365) yor=1;
			else c+=1+(n-366)/365,n=(n-366)%365;
			for(re int i=1;i<=12;i++) 
				if(n<k[i][yor]) 
				{
					n-=k[i-1][yor],b+=i-1;
					break;
				}
			printf("%d %d %d BC\n",a+n,b,-c);
			continue;
		}
		n-=A,c=1;
		if(n<B)
		{
			c+=n/1461*4,n%=1461;
			if(n>365*3) c+=3,yor=1,n-=365*3;
			else c+=n/365,n%=365;
			for(re int i=1;i<=12;i++) 
				if(n<k[i][yor]) {n-=k[i-1][yor],b+=i-1;break;}
			printf("%d %d %d\n",a+n,b,c);
			continue;
		}
		n-=B;
		a=15,b=10,c=1582;
		if(n<C)
		{
			if(n>=47) b=12,a=1,n-=47;
			else if(n>=17) b=11,a=1,n-=17;
			continue;
		}
		n-=C;
		a=1,b=1,c=1583;
		if(n<D)
		{
			c+=n/1461*4,n%=1461;
			if(n>=365&&n<=730) c++,yor=1,n-=365;
			else if(n>730) c+=2,n-=730,c+=n/365,n%=365;
			for(re int i=1;i<=12;i++) 
				if(n<k[i][yor]) {n-=k[i-1][yor],b+=i-1;break;}
			printf("%d %d %d\n",a+n,b,c);	
			continue;
		}
		n-=D;
		a=1,b=1,c=1600;
		c+=n/146097*400,n%=146097;
		c+=n/1461*4,n%=1461;
		if(n<=365) yor=1;
		else c+=1+(n-366)/365,n=(n-366)%365;
		for(re int i=1;i<=12;i++) 
			if(n<k[i][yor]) {n-=k[i-1][yor],b=i;break;}
		printf("%d %d %d\n",a+n,b,c);
	}
	return 0;
}
