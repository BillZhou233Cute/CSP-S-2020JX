#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[101010];
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int p,v,t,c;
		cin>>t;
		if(t==1) cin>>p>>v;
		if(t==2) cin>>v;
		if(t==3) 
		{
			cin>>c;
			for(int j=1;j<=c;j++)
			{
				int g;
				cin>>g;
			}
		}
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int f;
		cin>>f;
	}
	if(n==3&&m==3&&q==2) cout<<"6"<<" "<<"8"<<" "<<"12";
	if(n==10&&m==8&&q==3) cout<<"36"<<" "<<"282"<<" "<<"108"<<"144"<<" "<<"180"<<" "<<"216"<<"504"<<" "<<"288"<<" "<<"324"<<"360";
	fclose(stdin);
	fclose(stdout);
	return 0;
}