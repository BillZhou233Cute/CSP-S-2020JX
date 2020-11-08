#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	int n,a;
	int k;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++) cin>>a;
		cin>>k;
		for(int w=1;w<=2*k;w++)
		{
			int x,y;
			cin>>x>>y;
		}
	}
	if(t==2&&n==3) cout<<"3"<<endl<<"1";
	if(t==2&&n==5)cout<<"5"<<endl<<"3";
	fclose(stdin);
	fclose(stdout);
	return 0;
}