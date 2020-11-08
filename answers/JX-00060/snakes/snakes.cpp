#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("snakes.in","r" ,stdin);
	freopen("snakes.out","w",stdout);
	int n,T,a[1000005],z=1,k,x,y,v=0;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		if(i==1)
		{
			cin>>n;
			for(int j=1;j<=n;j++)
				cin>>a[j];
			sort(a+1,a+n+1);
			while(a[n]-a[z]>a[n-1])
			{
				a[n]-=a[z];
				z++;
			}
			cout<<n+1-z<<endl;
			z=1;	
		}
		else
		{
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>x;
				cin>>a[x];
			}
			sort(a+1,a+n+1);
			while(a[n]-a[z]>a[n-1])
			{
				a[n]-=a[z];
				z++;
			}
			cout<<n+1-z<<endl;
			z=1;	
		}
	}
	fclose(stdin);
	fclose(stdout);	
}
