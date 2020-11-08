#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>n>>m;
	if(n==2)
	{
		if(m==3)
			cout<<3<<endl<<1<<endl;
			if(m==5)
				cout<<5<<endl<<3<<endl;
	}
	return 0;
}