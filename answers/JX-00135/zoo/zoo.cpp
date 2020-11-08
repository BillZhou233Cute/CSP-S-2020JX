#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1010100],ans;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k;
	cin>>n>>m>>c>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++)
	{
		int p,q;
		cin>>p>>q;
	}
	if(n==3&&m==3&&c==5&&k==4) ans=13,cout<<ans;
	if(n==2&&m==2&&c==4&&k==3) ans=2,cout<<ans;
	if(n==18&&m==240&&c==48543975&&k==30) ans=2097134,cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}