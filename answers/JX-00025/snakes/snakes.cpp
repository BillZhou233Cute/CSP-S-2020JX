#include<bits/stdc++.h>
using namespace std; 
int a[1000005];
int main()
{
	int t;
	cin>>t;
	//freopen("snakes.in","r",stdin);
	//freopen("snakes.out","w",stdout);
	while(t--)
	{
		int n;
		cin>>n;
		int k=n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			if(i==n-1)
				if(a[n]>a[n-1])
				{
					k--;
					break;
				}
			if(a[n]-a[n-1]>=a[i])
			{
				a[n]-=a[i];
				k--;
			}
		}
		cout<<k;
	}
}