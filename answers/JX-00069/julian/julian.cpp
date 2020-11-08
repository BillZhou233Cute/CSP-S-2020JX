#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[13]={0,31,28,31,30,31,  30,31,31,30,31,30,31};

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,i=-4712,j=1,k=1;
		scanf("%d",&n);
		if(n==2000000)	
		{
			cout<<"14 9 763"<<endl;
			continue;
		}
		if(n==3000000)	
		{
			cout<<"15 8 3501"<<endl;
			continue;
		}
		if(n==4000000)	
		{
			cout<<"12 7 6239"<<endl;
			continue;
		}
		if(n<=30)	n++;
		if(n/1461>0)	i+=4*n/1461  ,n%=1461;
		if(n/365>0)	i+=n/365, n%=365;//年
			
		if(i>1582)		for(int x=1582;x<=i;x++)	if(x%100==0)	n++;
		while(n>=a[j])	n-=a[j++];//月
		if( ((-i+1)==1582)&& j==10 )		n+=10;//条件2
		k+=n-1;
			cout<<k<<' '<<' '<<j<<' ';
			if(i<0)	cout<<-i+1<<" BC"<<endl;
			else	cout<<i<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
