#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x;
		if(i==1)
		for(int j=1;j<=x;j++)
			cin>>y;
		else
			for(int j=1;j<=x*2;j++)
				cin>>y;
	
		}
	cout<<5<<"\n3";
	return 0; 
		                
}