#include<bits/stdc++.h>
using namespace std;
int T,n,a[100000],k,b[100000],tot,u;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		if(i==1)
		{	
		cin >> n;
			for(int i=1;i<=n;i++)
			{
				cin >> a[i];
			tot=max(tot,a[i]);
			}
				}
		else
		{
			cin >> k;
			for(int j=1;j<=k*2;j++)
				cin >> b[j];
		}
	 return 0;
}	