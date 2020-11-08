#include <bits/stdc++.h>
using namespace std;
int t,n,a[4],k,x;
int main()
{
	freopen("snake.in","r",stdin);
	freopen("snake.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		if(i==1)
		{
			cin>>n;
		    if(n!=3) return 0;
			cin>>a[1]>>a[2]>>a[3];
			sort(a+1,a+3+1);
			if(a[3]>a[2]+a[1]) cout<<1<<endl;
			else cout<<3<<endl;
		}
		else
		{
			cin>>k;
			for(int i=1;i<=k;i++)
			{
			   cin>>x;
				cin>>a[x];
			}
			sort(a+1,a+n+1);
			if(a[3]>a[2]+a[1]) cout<<1<<endl;
			else cout<<3<<endl;
		}
	}
	return 0;
}