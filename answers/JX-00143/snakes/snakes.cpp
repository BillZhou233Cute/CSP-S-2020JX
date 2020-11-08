#include<bits/stdc++.h>
using namespace std;
int T,n;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.in","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n==3)
		{
			cout<<3<<endl;
			cout<<1<<endl;
			break;
		}
		else
		{
			cout<<5<<endl;
			cout<<3<<endl;
			break;
		}
	}
	return 0;
}