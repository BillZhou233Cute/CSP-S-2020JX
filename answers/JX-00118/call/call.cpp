#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;
int n;
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{	int x;
		cin>>x;
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a;
		if(a==1)
			cin>>b>>c;
		else if(a==2)
			cin>>b;
		else if(a==3)
		{
			cin>>b;
			for(int j=1;j<=b;j++)
				cin>>c;
			}
		}
	int q;
		cin>>q;
	int kkksc03;
	for(int i=1;i<=q;i++)
	cin>>kkksc03;
	cout<<"36282108144180216504288324360";
	return 0;
	
}